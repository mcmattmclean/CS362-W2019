/*
** Unit test for function: compare()
** Location: File dominion.c, line 8
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    printf("Testing compare function.\n");

    int higher = 1;
    int lower = 0;
    int same = 1;
    int same1 = 1;

    //Test for higher first value
    assert(compare(&higher, &lower) == 1);
    //Lower first value
    assert(compare(&lower, &higher) == -1);
    //Equal value
    assert(compare(&same, &same1) == 0);
    //Same variable (also equal value)
    assert(compare(&same, &same) == 0);

    printf("compare test passed\n");

    return 0;
}