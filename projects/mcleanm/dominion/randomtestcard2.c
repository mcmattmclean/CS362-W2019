//Testing council room card via random test generator
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "dominion.h"
#include "rngs.h"
#include "testHelpers.h"

#define TRUE 1
#define FALSE 0
#define NUMBER_TESTS 1000


void printTestResult(int failed)
{
    if(failed == TRUE)
    {
        printf("Test failed.");
    }
}

int main() 
{
    srand(time(0));

    struct gameState* state = NULL;

    // Test each game state
    int i;
    for(i = 0; i < NUMBER_TESTS; i++)
    {
        // Randomize the game state
        if(state != NULL)
        {
            free(state);
            state = NULL;
        }
        state = getRandomState(state, council_room);

        // Play the adventurer, print if successful
        printTestResult(playCouncilRoom(state, state->whoseTurn, 1));
    }

    free(state);
    return 0;
}