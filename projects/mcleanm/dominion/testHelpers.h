#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include "dominion.h"

#define MIN_PLAYERS 2
#define TRUE 1
#define FALSE 0
#define SIZE_CARD_SET 10
#define SIZE_FULL_CARD_SET 16
#define TEST_MAX_HAND 20
// assertTrue macro source: https://piazza.com/class/jpu18p346423vs?cid=159
#define assertTrue(bool) if(bool) {} else {printf("TEST FAILED: '" #bool "' on line %d.\n", __LINE__);}

int getRandomNumberPlayers();
struct gameState* getRandomState(struct gameState*, int cardToTest);
int* getRandomCardSet(int cardToTest);
int* getFullCardSet(int cardSet[10]);
void getRandomSupplyCounts(struct gameState* state, int cardSet[10]);
void getRandomEmbargoTokens(struct gameState* state, int cardSet[10]);
void getRandomPlayerDecks(struct gameState* state, int cardSet[SIZE_FULL_CARD_SET]);
void getRandomPlayerHands(struct gameState* state, int cardSet[SIZE_FULL_CARD_SET]);
void getRandomPlayedCards(struct gameState* state, int cardSet[SIZE_FULL_CARD_SET]);


#endif