#include "UOV_run.h"
#include "../api.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

void run_UOV()
{
    unsigned char       seed[48] = {0};
    unsigned char       msg[3300] = {0};
    unsigned char       entropy_input[48] = {0};

    unsigned char       *m, *sm, *m1;
    unsigned long long  mlen, smlen, mlen1;
    unsigned char       pk[CRYPTO_PUBLICKEYBYTES], sk[CRYPTO_SECRETKEYBYTES];
    int                 ret_val;

    
    //KAT_NIST_randombytes(seed, 48);
    mlen = 33;

    m = (unsigned char *)calloc(mlen, sizeof(unsigned char));
    sm = (unsigned char *)calloc(mlen+CRYPTO_BYTES, sizeof(unsigned char));

    ret_val = crypto_sign_keypair(pk, sk);
    ret_val = crypto_sign(sm, &smlen, m, mlen, sk);
    ret_val = crypto_sign_open(m, &mlen, sm, smlen, pk);
    
    printf("[sig]\n");
    for(int i=0;i<smlen;i++){
        printf("%x",sm[i]);
    }

    printf("\nret_val : %d\n", ret_val);
}
