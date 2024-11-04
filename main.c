#include <stdio.h>
#include "cross/cross_meta/cross_run.h"
#include "cross/cross_meta/cross_bitcontribution.h"
#include "cross/cross_meta/cross_bitexclusion.h"
#include "cross/cross_meta/cross_verify.h"

#include "LESS/LESS_meta/LESS_run.h"
#include "LESS/LESS_meta/LESS_bitcontribution.h"
#include "LESS/LESS_meta/LESS_bitexclusion.h"
#include "LESS/LESS_meta/LESS_verify.h"

#include "hawk/hawk_meta/hawk_run.h"
#include "hawk/hawk_meta/hawk_bitcontribution.h"
#include "hawk/hawk_meta/hawk_bitexclusion.h"
#include "hawk/hawk_meta/hawk_verify.h"

#include "PERK/PERK_meta/PERK_run.h"
#include "PERK/PERK_meta/PERK_bitcontribution.h"
#include "PERK/PERK_meta/PERK_bitexclusion.h"
#include "PERK/PERK_meta/PERK_verify.h"

#include "sdith/sdith_meta/sdith_run.h"
#include "sdith/sdith_meta/sdith_bitcontribution.h"
#include "sdith/sdith_meta/sdith_bitexclusion.h"
#include "sdith/sdith_meta/sdith_verify.h"

#include "MAYO/MAYO_meta/MAYO_run.h"
#include "MAYO/MAYO_meta/MAYO_bitcontribution.h"
#include "MAYO/MAYO_meta/MAYO_bitexclusion.h"
#include "MAYO/MAYO_meta/MAYO_verify.h"

//#include "QRUOV/QRUOV_meta/QRUOV_run.h"

#include "SNOVA/SNOVA_meta/SNOVA_run.h"

#include "UOV/UOV_meta/UOV_run.h"
#include "UOV/UOV_meta/UOV_bug_run.h"
#include "UOV/UOV_meta/UOV_bitcontribution.h"
#include "UOV/UOV_meta/UOV_bitexclusion.h"
#include "UOV/UOV_meta/UOV_verify.h"



int main()
{    
    //run_cross();    
    //printf("CROSS metamorphic test start\n");
    // METAMORPHIC_CROSS_bit_contribution_test_dsa();
    // METAMORPHIC_CROSS_bit_exclusion_test_dsa();
    // METAMORPHIC_CROSS_verify_test_dsa();

    // run_LESS();
    // printf("LESS metamorphic test start\n");
    //METAMORPHIC_LESS_bit_contribution_test_dsa();
    //METAMORPHIC_LESS_bit_exclusion_test_dsa();
    //METAMORPHIC_LESS_verify_test_dsa();

    // run_hawk();
    // printf("HAWK metamorphic test start\n");
    // METAMORPHIC_hawk_bit_contribution_test_dsa();
    // METAMORPHIC_hawk_bit_exclusion_test_dsa();
    // METAMORPHIC_hawk_verify_test_dsa();

    // run_PERK();    
    // printf("PERK metamorphic test start\n");
    // METAMORPHIC_PERK_bit_contribution_test_dsa();
    // METAMORPHIC_PERK_bit_exclusion_test_dsa();
    // METAMORPHIC_PERK_verify_test_dsa();

    //run_sdith();
    // METAMORPHIC_sdith_bit_contribution_test_dsa();
    // METAMORPHIC_sdith_bit_exclusion_test_dsa();
    // METAMORPHIC_sdith_verify_test_dsa();

    //run_MAYO();
    // printf("MAYO metamorphic test start\n");
    // METAMORPHIC_MAYO_bit_contribution_test_dsa();
    // METAMORPHIC_MAYO_bit_exclusion_test_dsa();
    // METAMORPHIC_MAYO_verify_test_dsa();

    // run_QRUOV();
    // printf("QRUOV metamorphic test start\n");

    // run_SNOVA();
    // printf("SNOVA metamorphic test start\n");

    
    run_bug_UOV();
    printf("UOV metamorphic test start\n");
    //METAMORPHIC_UOV_bit_contribution_test_dsa();
    // METAMORPHIC_UOV_bit_exclusion_test_dsa();
    // METAMORPHIC_UOV_verify_test_dsa();

    printf("end\n");
    
    // run_hawk();
    // run_hawk();
    // run_hawk();
}