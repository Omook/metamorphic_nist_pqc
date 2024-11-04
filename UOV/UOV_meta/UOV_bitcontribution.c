#include "UOV_bitcontribution.h"
#include "../api.h"
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





void METAMORPHIC_UOV_bit_contribution_test_dsa() 
{
    FILE *file;

    // "output.txt" 파일을 쓰기 모드(w)로 열기
    file = fopen("output.txt", "w");

    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

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
        //m[i] = rand() & 0xff;
        m[i] = i+2;
    }

    crypto_sign_keypair(pk, sk);
    ret_val = crypto_sign(sm, &smlen, m, mlen, sk);

    
    printf("cccontribusion test start\n");
    //! change message
    for(int i = 0; i < mlen * 8; i++){        
        memcpy(m_buf, m, mlen);
        m_buf[i/8] ^= 1 << (i % 8);

        ret_val = crypto_sign(sm_buf, &sm_buflen, m_buf, mlen, sk);
        t++;
                
        if(memcmp(sm, sm_buf, smlen) == 0) 
        {            
            printf("%d : emergency\n", i);
            flag = 1;
            f++;            
        }
        if(smlen != sm_buflen) {               
            flag = 1;
            ff++;            
        }        
        
    }


    //! change sk    
    printf("test : %d\n", sklen*8);
    // for(int i = 0; i < 100000; i++){ //sklen*8
    //     memcpy(sk_buf, sk, sklen);
    //     sk_buf[i/8] ^= 1 << (i % 8);

    //     ret_val = crypto_sign(sm_buf, &sm_buflen, m, mlen, sk_buf);
    //     t++;
                        
    //     if(memcmp(sm, sm_buf, smlen) == 0 ){                  
    //         printf("%d ", i);                      
    //         flag = 1;
    //         f++;            
    //     }
    //     if(smlen != sm_buflen) {                        
    //         flag = 1;
    //         ff++;            
    //     }

        
    // }
    for(int i = 0; i < 10000; i++){ //sklen*8
        memcpy(sk_buf, sk, sklen);
        sk_buf[i] = ~sk_buf[i];

        ret_val = crypto_sign(sm_buf, &sm_buflen, m, mlen, sk_buf);
        t++;
                        
        if(memcmp(sm, sm_buf, smlen) == 0 ){                 
                         
            flag = 1;
            f++;     
            if(f>35){
                fprintf(file, "%d\n", 3); 
            fprintf(file, "i : %d\n", i);
            fprintf(file, "sk : %x\n", sk_buf[i]);
            fprintf(file, "m=\n");
            for(int i=0;i<mlen;i++){
                fprintf(file, "0x%x, ", m[i]);
            }
            fprintf(file, "\n\nsk=\n");
            for(int i=0;i<sklen;i++){
                fprintf(file, "0x%x, ", sk[i]);
            }
            fprintf(file, "\n\nsm=\n");
            for(int i=0;i<smlen;i++){
                fprintf(file, "0x%x, ", sm[i]);
            }


            fprintf(file, "\n\nsk_buf=\n");
            for(int i=0;i<sklen;i++){
                fprintf(file, "0x%x, ", sk_buf[i]);
            }
            fprintf(file, "\n\nsm_buf=\n");
            for(int i=0;i<smlen;i++){
                fprintf(file, "0x%x, ", sm_buf[i]);
            }
            break;                     
            }       
            
        }
        if(smlen != sm_buflen) {                        
            flag = 1;
            ff++;            
        }

        
    }
    fclose(file);

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
