/*
** Unit test for function: kingdomCards()
** Location: File dominion.c, line 21
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "testHelpers.h"

int main()
{
    printf("Testing kingdomCards()\n");

    int k1 = 0;
    int k2 = 1;
    int k3 = 2;
    int k4 = 3;
    int k5 = 4;
    int k6 = 5;
    int k7 = 6;
    int k8 = 7;
    int k9 = 8;
    int k10 = 9;

    int* k = kingdomCards(k1, k2, k3, k4, k5, k6, k7, k8, k9, k10);

    int i;
    for(i = 0; i < 10; i++)
    {
        assertTrue(k[i] == i);
    }

    printf("kingdomCards() test complete\n");
    return 0;
}