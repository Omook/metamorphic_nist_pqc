#include "hawk_bitexclusion.h"
#include "../hawk512/api.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


#define BIT_CONTRIBUTION_SUCCESS    0
#define BIT_VERIFY_SUCCESS          0
#define BIT_CONTRIBUTION_FAIL       -1
#define BIT_VERIFY_FAIL             -1

#define EXCLUSION_BYTELEN   30

void METAMORPHIC_hawk_bit_exclusion_test_dsa() 
{
    unsigned char       seed[48] = {0};
    unsigned char       msg[3300] = {0};
    unsigned char       entropy_input[48] = {0};

    unsigned char       *m, *m_buf, *sm, *sm_buf;
    unsigned long long  mlen, smlen, sm_buflen;
    unsigned char       pk[CRYPTO_PUBLICKEYBYTES], sk[CRYPTO_SECRETKEYBYTES];
    int                 ret_val;
    int                 flag = 0;
    
    int t=0, f=0, ff=0;
    //KAT_NIST_randombytes(seed, 48);
    mlen = 32;
    m = (unsigned char *)calloc(mlen+EXCLUSION_BYTELEN, sizeof(unsigned char));
    m_buf = (unsigned char *)calloc(mlen+EXCLUSION_BYTELEN, sizeof(unsigned char));
    sm = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));
    sm_buf = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));
    
    
    assert(m    != NULL);
    assert(m_buf  != NULL);
    assert(sm  != NULL);
    assert(sm_buf != NULL);

    srand(time(NULL));
    // set message with pseudorandom bytes
    for(int i = 0; i < mlen+EXCLUSION_BYTELEN; i++){
        m[i] = rand() & 0xff;
    }

    crypto_sign_keypair(pk, sk);
    ret_val = crypto_sign(sm, &smlen, m, mlen, sk);

    printf("exclusion test start 400\n");

    for(int i = 1; i < 2; i++){
        memcpy(m_buf, m, mlen + EXCLUSION_BYTELEN);
        m_buf[mlen + i/8] ^= 1 << (i % 8);

        t++;        
        ret_val = crypto_sign(sm_buf, &sm_buflen, m_buf, mlen, sk);
        

        if(memcmp(sm, sm_buf, smlen) != 0) 
        {   
            f++;
            flag = 1;            
            // printf("[sm] : %d\n", smlen);
            // for(int i=0;i<smlen;i++)
            // {
            //     printf("%x ", sm[i]);
            // }
            // printf("\n");
            // printf("[smbuf] : %d\n", sm_buflen);
            // for(int i=0;i<smlen;i++)
            // {
            //     printf("%x ", sm_buf[i]);
            // }
            // printf("\n\n");
        }
        if(smlen != sm_buflen) {
            ff++;
            flag = 1;            
        }
    }    


EXIT:    

    if(!flag){
        printf("Bit Exclusion Test Success++++++++++\n");        
    } else{
        printf("Bit Exclusion Test Failed: Failed on messaage---------\n");        
    }
    printf("t : %d\n", t);
    printf("f : %d\n", f);    
    printf("ff : %d\n", ff);    

}
