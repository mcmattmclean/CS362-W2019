/*
** Unit test for function: drawCard()
** Location: File dominion.c, line 525
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
  printf("Testing drawCard()\n");

  int numPlayers = 2;
  struct gameState *state = newGame();
  initializeGame(numPlayers, kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 1, state);

  //Starting game, first player has hand of size 5, and a deck of 5 cards
  assert(state->handCount[0] == 5);
  assert(state->deckCount[0] == 5);

  //Second player has hand of size 0, and a deck of size 10
  assert(state->handCount[1] == 0);
  assert(state->deckCount[1] == 10);

  //Assert starting supply counts before drawing
  int i;
  assert(state->supplyCount[0] == 10);
  for(i = 1; i < 4; i++)
  {
    assert(state->supplyCount[i] = 8);
  }
  assert(state->supplyCount[4] == 46);
  assert(state->supplyCount[5] == 40);
  assert(state->supplyCount[6] == 30);
  for(i = 7; i < 10; i++)
  {
    assert(state->supplyCount[i] == 10);
  }

  //Check players after player1 draws
  drawCard(0, state);
  assert(state->handCount[0] == 6);
  assert(state->deckCount[0] == 4);
  assert(state->handCount[1] == 0);
  assert(state->deckCount[1] == 10);

  //Check players after player2 draws
  drawCard(1, state);
  assert(state->handCount[0] == 6);
  assert(state->deckCount[0] == 4);
  assert(state->handCount[1] == 1);
  assert(state->deckCount[1] == 9);

  //Check supply counts are unchanged
  assert(state->supplyCount[0] == 10);
  for(i = 1; i < 4; i++)
  {
    assert(state->supplyCount[i] = 8);
  }
  assert(state->supplyCount[4] == 46);
  assert(state->supplyCount[5] == 40);
  assert(state->supplyCount[6] == 30);
  for(i = 7; i < 10; i++)
  {
    assert(state->supplyCount[i] == 10);
  }

  printf("drawCard() test passed\n");
  return 0;
}