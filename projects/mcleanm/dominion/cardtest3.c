/*
** Card test for: Council Room
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "testHelpers.h"

int main()
{
  printf("Starting council room test\n");
  // Set up
  int numPlayers = 2;
  int player1 = 0;
  int player2 = 1;
  struct gameState *state = newGame();
  initializeGame(numPlayers, kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 1, state);

  // Check starting conditions
  assertTrue(state->handCount[player1] == 5);
  assertTrue(state->deckCount[player1] == 5);
  assertTrue(state->handCount[player2] == 0);
  assertTrue(state->deckCount[player2] == 10);
  assertTrue(state->numBuys == 1);

  // Set first card in hand as council room and play it
  state->hand[player1][0] = council_room;
  cardEffect(council_room, 0, 0, 0, state, 0, 0);

  // Check post conditions
  assertTrue(state->handCount[player1] == 8);
  assertTrue(state->deckCount[player1] == 1);

  assertTrue(state->handCount[player2] == 1);
  assertTrue(state->deckCount[player2] == 9);
  assertTrue(state->numBuys == 2);

  assertTrue(state->playedCards[0] == council_room);

  printf("Council room test complete\n");
  return 0;
}