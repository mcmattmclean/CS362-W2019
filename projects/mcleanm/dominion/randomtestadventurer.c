//Testing adventurer card via random test generator
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "dominion.h"

#define NUMBER_TESTS 100
#define MAX_PLAYERS 20
#define MIN_PLAYERS 2

int getRandomNumberPlayers()
{
    return rand() % (MAX_PLAYERS + 1 - MIN_PLAYERS) + MIN_PLAYERS;
}

struct ResultPair 
{
    struct gameState* original;
    struct gameState* copy;
};

void verifyState(struct ResultPair result) 
{

}

void generateResultPair(struct ResultPair* result)
{
    result->original = gameState();
    result->copy = gameState();

    //Apply same random changes to each game state
}

int main() 
{
    srand(time(0));
    struct ResultPair* testPairs[NUMBER_TESTS];
    int i = 0;
    for(i = 0; i < NUMBER_TESTS; i++)
    {
        generateResultPair(testPairs[i]);
    }

    //Generate random state

    //Play adventurer

    //Assert state changed correctly

    return 0;
}