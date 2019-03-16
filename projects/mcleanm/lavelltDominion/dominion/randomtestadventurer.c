//Testing adventurer card via random test generator
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "dominion.h"
#include "rngs.h"
#include "testHelpers.h"

#define TRUE 1
#define FALSE 0
#define NUMBER_TESTS 10000

void testAdventurer(struct gameState* state)
{
    // Get preconditions
    int currentPlayer = state->whoseTurn;
    int handSize = state->handCount[currentPlayer];
    int treasureInDeck = 0;

    // Count available treasure in deck and discard
    int i;
    for(i = 0; i < state->deckCount[currentPlayer]; i++)
    {
        if(state->deck[currentPlayer][i] == gold || state->deck[currentPlayer][i] == silver || state->deck[currentPlayer][i] == copper)
        {
            treasureInDeck++;
        }
    }
    for(i = 0; i < state->discardCount[currentPlayer]; i++)
    {
        if(state->discard[currentPlayer][i] == gold || state->discard[currentPlayer][i] == silver || state->discard[currentPlayer][i] == copper)
        {
            treasureInDeck++;
        }
    }

    // Call function to test and check postcondition
    assertTrue(cardEffect(adventurer, 0, 0, 0, state, 1, 0) == 0);
    
    if(treasureInDeck > 1)
    {
        assertTrue(state->handCount[currentPlayer] == (handSize + 2 - 1)); // Gain treasure, discard played card
    }
    else
    {
        // printf("Treasure available: %d\n", treasureInDeck);
        // printf("Hand count before: %d\n", handSize);
        // printf("Hand count after: %d\n", state->handCount[currentPlayer]);
        assertTrue(state->handCount[currentPlayer] == (handSize + treasureInDeck - 1));
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
        state = getRandomState(state, adventurer);

        // Play the adventurer, print if successful
        testAdventurer(state);
    }

    free(state);
    return 0;
}