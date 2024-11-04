#include "LESS_run.h"
#include "../api.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

void run_LESS()
{
    unsigned char       seed[48] = {0};
    unsigned char       msg[3300] = {0};
    unsigned char       entropy_input[48] = {0};

    unsigned char       *m, *sm, *sm2, *m1;
    unsigned long long  mlen, smlen, mlen1;
    unsigned char       pk[CRYPTO_PUBLICKEYBYTES], sk[CRYPTO_SECRETKEYBYTES];
    int                 ret_val;

    
    //KAT_NIST_randombytes(seed, 48);
    mlen = 33;

    m = (unsigned char *)calloc(mlen, sizeof(unsigned char));
    sm = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));
    sm2 = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));

    ret_val = crypto_sign_keypair(pk, sk);
    ret_val = crypto_sign(sm, &smlen, m, mlen, sk);
    ret_val = crypto_sign_open(m, &mlen, sm, smlen, pk);
    printf("\nret_val : %d\n", ret_val);

    int cnt = 0;
    printf("sm[301] = %d\n", sm[301]);
    for(int i=0;i<255;i++)
    {
        memcpy(sm2, sm, smlen);
        sm2[301] = (sm[301] & 0x3) + (i & 0xfc);        
        ret_val = crypto_sign_open(m, &mlen, sm2, smlen, pk);
        printf("\nret_val : %d\n", ret_val);
        if(ret_val == 0) cnt++;
    }
    
    printf("cnt : %d\n", cnt);
    
    // printf("[sig]\n");
    // for(int i=0;i<smlen;i++){
    //     printf("%x",sm[i]);
    // }

    
}
