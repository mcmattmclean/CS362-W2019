#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H
#include "dominion.h"

struct ResultPair 
{
    struct gameState state;
    struct gameState copy;
};

int getRandomNumberPlayers();
void verifySame(struct ResultPair*);
void generateResultPair(struct ResultPair*, int kingdomCards[10]);


#endif