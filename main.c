#include <stdio.h>
#include "cross/cross_meta/cross_run.h"
#include "cross/cross_meta/cross_bitcontribution.h"
#include "cross/cross_meta/cross_bitexclusion.h"
#include "cross/cross_meta/cross_verify.h"

#include "hawk/hawk_meta/hawk_run.h"

int main()
{
    printf("hello\n");
    //run_cross();    
    METAMORPHIC_CROSS_bit_contribution_test_dsa();
    METAMORPHIC_CROSS_bit_exclusion_test_dsa();
    METAMORPHIC_CROSS_verify_test_dsa();
    printf("hello\n");
    // run_hawk();
    // run_hawk();
    // run_hawk();
    // run_hawk();
}