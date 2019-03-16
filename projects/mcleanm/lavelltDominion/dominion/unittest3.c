/*
** Unit test for function: drawCard()
** Location: File dominion.c, line 525
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "testHelpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  printf("Testing drawCard()\n");

  int numPlayers = 2;
  struct gameState *state = newGame();
  initializeGame(numPlayers, kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 1, state);

  //Starting game, first player has hand of size 5, and a deck of 5 cards
  assertTrue(state->handCount[0] == 5);
  assertTrue(state->deckCount[0] == 5);

  //Second player has hand of size 0, and a deck of size 10
  assertTrue(state->handCount[1] == 0);
  assertTrue(state->deckCount[1] == 10);

  //Assert starting supply counts before drawing
  int i;
  assertTrue(state->supplyCount[0] == 10);
  for(i = 1; i < 4; i++)
  {
    assertTrue(state->supplyCount[i] == 8);
  }
  assertTrue(state->supplyCount[4] == 46);
  assertTrue(state->supplyCount[5] == 40);
  assertTrue(state->supplyCount[6] == 30);
  for(i = 7; i < 10; i++)
  {
    assertTrue(state->supplyCount[i] == 10);
  }

  //Check players after player1 draws
  drawCard(0, state);
  assertTrue(state->handCount[0] == 6);
  assertTrue(state->deckCount[0] == 4);
  assertTrue(state->handCount[1] == 0);
  assertTrue(state->deckCount[1] == 10);

  //Check players after player2 draws
  drawCard(1, state);
  assertTrue(state->handCount[0] == 6);
  assertTrue(state->deckCount[0] == 4);
  assertTrue(state->handCount[1] == 1);
  assertTrue(state->deckCount[1] == 9);

  //Check supply counts are unchanged
  assertTrue(state->supplyCount[0] == 10);
  for(i = 1; i < 4; i++)
  {
    assertTrue(state->supplyCount[i] == 8);
  }
  assertTrue(state->supplyCount[4] == 46);
  assertTrue(state->supplyCount[5] == 40);
  assertTrue(state->supplyCount[6] == 30);
  for(i = 7; i < 10; i++)
  {
    assertTrue(state->supplyCount[i] == 10);
  }

  printf("drawCard() test complete\n");
  return 0;
}