#include "UOV_bug_run.h"
#include "../api.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

unsigned char m[32] = {0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21};


void run_bug_UOV()
{
    unsigned char       seed[48] = {0};
    
    

    unsigned char       *sm, *sm2;
    unsigned long long  mlen, smlen, smlen2;    
    int                 ret_val;

    
    //KAT_NIST_randombytes(seed, 48);
    mlen = 32;
    
    sm = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));
    sm2 = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));

    
    ret_val = crypto_sign(sm, &smlen, m, mlen, sk);
    sk[1155] = ~sk[1155];
    ret_val = crypto_sign(sm2, &smlen2, m, mlen, sk);


    //ret_val = crypto_sign_open(m, &mlen, sm, smlen, pk);
    

    printf("smlen : %d\n", smlen);
    printf("smlen2 : %d\n", smlen2);

    if(memcmp(sm, sm2, smlen) == 0) printf("bug man~\n");

    printf("sm\n");
    for(int i=0;i<smlen;i++){
        printf("0x%x ", sm[i]);
    }
    printf("\n\nsm2\n");
    for(int i=0;i<smlen;i++){
        printf("0x%x ", sm2[i]);
    }

    printf("\nret_val : %d\n", ret_val);
}