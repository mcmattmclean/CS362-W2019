#include "testHelpers.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define NUMBER_TESTS 100
#define TEST_MAX_PLAYERS 20
#define TEST_MIN_PLAYERS 2

// Get a random number in the accepted range of possible players
int getRandomNumberPlayers()
{
    return rand() % (TEST_MAX_PLAYERS + 1 - TEST_MIN_PLAYERS) + TEST_MIN_PLAYERS;
}

// Compare two game states and return 0 if the same
void verifySame(struct ResultPair* result)
{
    if(result->original.numPlayers != result->copy.numPlayers) return 1;
    //TODO: add rest of checks
}

// Takes result pair with list of cards to use in test
void generateResultPair(struct ResultPair* result, int kingdomCards[10])
{
    initializeGame(getRandomNumberPlayers()result->original);
    initializeGame(result->copy);

    //Apply same random changes to each game state
    result->original.numPlayers = result->copy.numPlayers = getRandomNumberPlayers();
}
