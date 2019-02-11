/*
** Card test for: Smithy
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
  printf("Starting smithy test\n");

  // Set up
  int numPlayers = 2;
  int player1 = 0;
  int player2 = 1;
  struct gameState *state = newGame();
  initializeGame(numPlayers, kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 1, state);

  // Check starting conditions
  assertTrue(state->handCount[player1] == 5);
  assertTrue(state->handCount[player2] == 0);
  assertTrue(state->deckCount[player1] == 5);
  assertTrue(state->deckCount[player2] == 10);

  // Set first card in hand as a smithy and play it
  state->hand[player1][0] = smithy;
  cardEffect(smithy, 0, 0, 0, state, 0, 0);

  // Check ending conditions
  assertTrue(state->handCount[player1] == 7);
  assertTrue(state->handCount[player2] == 0);
  assertTrue(state->deckCount[player1] == 2);
  assertTrue(state->deckCount[player2] == 10);
  assertTrue(state->playedCards[0] == smithy);

  printf("Smithy test complete\n");

  return 0;
}