#include "cross_verify.h"
#include "../api.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>



void METAMORPHIC_CROSS_verify_test_dsa() 
{
    unsigned char       seed[48] = {0};    
    unsigned char       entropy_input[48] = {0};

    unsigned char       *m, *m1, *sm, *sm_buf;
    unsigned long long  mlen, mlen1, smlen, sm_buflen;
    unsigned char       pk[CRYPTO_PUBLICKEYBYTES], sk[CRYPTO_SECRETKEYBYTES];
    int                 ret_val;
    int                 flag = 0;
    
    int t=0, f=0;
    //KAT_NIST_randombytes(seed, 48);
    mlen = 33;
    m = (unsigned char *)calloc(mlen, sizeof(unsigned char));
    m1 = (unsigned char *)calloc(mlen, sizeof(unsigned char));
    sm_buf = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));
    sm = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));

    assert(m    != NULL);
    assert(m1    != NULL);
    assert(sm_buf  != NULL);
    assert(sm  != NULL);
    

    srand(time(NULL));
    // set message with pseudorandom bytes
    for(int i = 0; i < mlen; i++){
        m[i] = rand() & 0xff;
    }

    crypto_sign_keypair(pk, sk);
    ret_val = crypto_sign(sm, &smlen, m, mlen, sk);

    printf("cc verify test start\n");

    int j = 1;

    //!change sm
    for(int i = 0; i < smlen * 8; i++){
        memcpy(sm_buf, sm, smlen);
        sm_buf[i/8] ^= 1 << (i % 8);

        t++;
        ret_val = crypto_sign_open(m, &mlen, sm_buf, smlen, pk);

        if(ret_val == 0) {                                          
            f++;
            flag = 1;
            printf("i : %d, %d\n", i, smlen);
            //goto EXIT;
        }
                
    }

    printf("t : %d\n", t);
    printf("f : %d\n", f);
    


EXIT:
    

    if(!flag){
        printf("Bit Verify Test Success++++++++++\n");
        //return BIT_CONTRIBUTION_SUCCESS;
    } else{
        printf("Bit Verify Test Failed: Failed on messaage---------\n");
        //return BIT_CONTRIBUTION_FAIL;
    }    

}