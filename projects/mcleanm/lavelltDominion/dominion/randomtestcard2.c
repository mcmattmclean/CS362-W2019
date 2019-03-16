//Testing council room card via random test generator
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "dominion.h"
#include "rngs.h"
#include "testHelpers.h"

#define TRUE 1
#define FALSE 0
#define NUMBER_TESTS 10000


void testCouncilRoom(struct gameState* state)
{
    // Get preconditions
    int currentPlayer = state->whoseTurn;
    int numBuys = state->numBuys;
    int* handSizes = malloc(state->numPlayers * sizeof(int));
    int* deckAndDiscardSizes = malloc(state->numPlayers * sizeof(int));
    int i;
    for(i = 0; i < state->numPlayers; i++)
    {
        handSizes[i] = state->handCount[i]; // Save hand counts
    }
    for(i = 0; i < state->numPlayers; i++)
    {
        deckAndDiscardSizes[i] = state->discardCount[i] + state->deckCount[i];
    }

    // Call function to test and check postcondition
    assertTrue(playCouncilRoom(state, currentPlayer, 1) == 0);
    assertTrue(state->numBuys == (numBuys + 1));
    for(i = 0; i < state->numPlayers; i++)
    {
        if(i == currentPlayer)
        {
            if(deckAndDiscardSizes[i] > 3) // If the player has enough to draw full amount, they should have 3 cards
            {
                assertTrue(state->handCount[i] == (handSizes[i] + 3)); // Player of card gets 4 new cards, discarding the played one
            }
            else
            {
                assertTrue(state->handCount[i] == (handSizes[i] + deckAndDiscardSizes[i] - 1)); // Player of card gets whatever cards are available
                // printf("Number available: %d\n", deckAndDiscardSizes[i]);
                // printf("Hand count before: %d\n", handSizes[i]);
                // printf("Hand count after: %d\n", state->handCount[i]);
            }
        }
        else
        {
            if(deckAndDiscardSizes[i] > 0) // If there is a card, other players draw it
            {
                assertTrue(state->handCount[i] == (handSizes[i] + 1)); // Other players get 1 new card
            }
            else
            {
                assertTrue(state->handCount[i] == handSizes[i]);
                // printf("Number available: %d\n", deckAndDiscardSizes[i]);
                // printf("Hand count before: %d\n", handSizes[i]);
                // printf("Hand count after: %d\n", state->handCount[i]);
            }
        }
    }
    free(handSizes);
    free(deckAndDiscardSizes);
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

        // Test the council room
        testCouncilRoom(state);
    }

    free(state);
    return 0;
}