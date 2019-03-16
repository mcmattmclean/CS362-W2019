/*
** Card test for: Feast
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "testHelpers.h"

const int numPlayers = 2;
const int player1 = 0;
const int player2 = 1;

void checkStartingConditions(struct gameState *state)
{
  assertTrue(state->handCount[player1] == 5);
  assertTrue(state->deckCount[player1] == 5);
  assertTrue(state->discardCount[player1] == 0);
  assertTrue(state->handCount[player2] == 0);
  assertTrue(state->deckCount[player2] == 10);
  assertTrue(state->discardCount[player2] == 0);
}

void checkPostConditionsCardAdded(struct gameState *state)
{
  assertTrue(state->handCount[player1] == 4);
  assertTrue(state->deckCount[player1] == 5);
  assertTrue(state->discardCount[player1] == 1);

  assertTrue(state->handCount[player2] == 0);
  assertTrue(state->deckCount[player2] == 10);
  assertTrue(state->discardCount[player2] == 0);

  assertTrue(state->playedCards[0] != feast);
}

void checkPostConditionsCardNotAdded(struct gameState *state)
{
  assertTrue(state->handCount[player1] == 4);
  assertTrue(state->deckCount[player1] == 5);
  assertTrue(state->discardCount[player1] == 0);

  assertTrue(state->handCount[player2] == 0);
  assertTrue(state->deckCount[player2] == 10);
  assertTrue(state->discardCount[player2] == 0);

  assertTrue(state->playedCards[0] != feast);
}

int main()
{
  printf("Starting feast test\n");
  // Set up
  int cardOver5 = province;
  int cardEqual5 = duchy;
  int cardUnder5 = copper;
  struct gameState *state = newGame();

  // Play feast with card cost under 5 
  initializeGame(numPlayers, kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 1, state);
  checkStartingConditions(state);
  state->hand[player1][0] = feast;
  cardEffect(feast, cardUnder5, 0, 0, state, 0, 0);
  checkPostConditionsCardAdded(state);

  //Play feast with card cost equal to 5
  initializeGame(numPlayers, kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 1, state);
  checkStartingConditions(state);
  state->hand[player1][0] = feast;
  cardEffect(feast, cardEqual5, 0, 0, state, 0, 0);
  checkPostConditionsCardAdded(state);

  //Play feast with card cost over 5
  initializeGame(numPlayers, kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 1, state);
  checkStartingConditions(state);
  state->hand[player1][0] = feast;
  cardEffect(feast, cardOver5, 0, 0, state, 0, 0);
  checkPostConditionsCardNotAdded(state);

  //Play feast when not any cards to buy of chosen type
  initializeGame(numPlayers, kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 1, state);
  state->supplyCount[cardUnder5] = 0;
  checkStartingConditions(state);
  state->hand[player1][0] = feast;
  cardEffect(feast, cardUnder5, 0, 0, state, 0, 0);
  checkPostConditionsCardNotAdded(state);

  printf("Feast test complete\n");
  return 0;
}