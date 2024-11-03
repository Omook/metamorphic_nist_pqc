#include "hawk_bitcontribution.h"
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


void METAMORPHIC_hawk_bit_contribution_test_dsa() 
{
    unsigned char       seed[48] = {0};
    unsigned char       msg[3300] = {0};
    unsigned char       entropy_input[48] = {0};

    unsigned char       *m, *m_buf, *sm, *sm_buf, *sk_buf;
    unsigned long long  mlen, smlen, sm_buflen, sklen;
    unsigned char       pk[CRYPTO_PUBLICKEYBYTES], sk[CRYPTO_SECRETKEYBYTES];
    int                 ret_val;
    int                 flag = 0;
    
    int t=0, f=0, ff=0;
    //KAT_NIST_randombytes(seed, 48);
    sklen = CRYPTO_SECRETKEYBYTES;
    mlen = 32;
    m = (unsigned char *)calloc(mlen, sizeof(unsigned char));
    m_buf = (unsigned char *)calloc(mlen, sizeof(unsigned char));
    sk_buf = (unsigned char *)calloc(sklen, sizeof(unsigned char));
    sm = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));
    sm_buf = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));
    
    assert(m    != NULL);
    assert(m_buf  != NULL);
    assert(sk_buf  != NULL);
    assert(sm  != NULL);
    assert(sm_buf != NULL);

    srand(time(NULL));
    // set message with pseudorandom bytes
    for(int i = 0; i < mlen; i++){
        m[i] = rand() & 0xff;
    }

    crypto_sign_keypair(pk, sk);
    ret_val = crypto_sign(sm, &smlen, m, mlen, sk);

    
    printf("contribusion test start\n");
    //! change message
    for(int i = 0; i < mlen * 8; i++){        
        memcpy(m_buf, m, mlen);
        m_buf[i/8] ^= 1 << (i % 8);

        ret_val = crypto_sign(sm_buf, &sm_buflen, m_buf, mlen, sk);
        t++;
                
        if(memcmp(sm, sm_buf, smlen) == 0) 
        {            
            flag = 1;
            f++;            
        }
        if(smlen != sm_buflen) {               
            flag = 1;
            ff++;            
        }        
        
    }


    //! change sk    
    for(int i = 0; i < sklen * 8; i++){
        memcpy(sk_buf, sk, sklen);
        sk_buf[i/8] ^= 1 << (i % 8);

        ret_val = crypto_sign(sm_buf, &sm_buflen, m, mlen, sk_buf);
        t++;
                
        if(memcmp(sm, sm_buf, smlen) == 0 ){            
            flag = 1;
            f++;            
        }
        if(smlen != sm_buflen) {                        
            flag = 1;
            ff++;            
        }

        
    }
    

EXIT:

    if(!flag){
        printf("Bit Contribution Test Success+++++++++++\n");        
    } else{
        printf("Bit Contribution Test Failed: Failed on messaage---------\n");        
    }    
    printf("t : %d\n", t);
    printf("f : %d\n", f);
    printf("ff : %d\n", ff);

}
