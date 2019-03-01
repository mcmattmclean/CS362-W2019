//Testing adventurer card via random test generator
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "dominion.h"

int main() 
{
    srand(time(0));
    struct ResultPair* testPairs[NUMBER_TESTS];
    int i = 0;
    for(i = 0; i < NUMBER_TESTS; i++)
    {
        generateResultPair(testPairs[i]);
    }

    //Generate random state, add to 

    //Play adventurer

    //Assert state changed correctly

    return 0;
}