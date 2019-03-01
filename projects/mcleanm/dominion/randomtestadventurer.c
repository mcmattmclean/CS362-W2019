//Testing adventurer card via random test generator
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "dominion.h"
#include "testHelpers.h"

#define TRUE 1
#define FALSE 0

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

    // Randomize the game state
    state = getRandomState(state, adventurer);

    // Play the adventurer, print if successful
    printTestResult(playAdventurer(state, state->whoseTurn));

    // // Test each game state
    // int i;
    // for(i = 0; i < NUMBER_TESTS; i++)
    // {
    //     // Randomize the game state
    //     if(state != NULL)
    //     {
    //         free(state);
    //         state = NULL;
    //     }
    //     state = getRandomState(state, adventurer);

    //     // Play the adventurer, print if successful
    //     printTestResult(playAdventurer(state, state->whoseTurn));
    // }

    free(state);
    return 0;
}