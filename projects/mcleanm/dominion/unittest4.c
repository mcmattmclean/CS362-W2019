/*
** Unit test for function: endTurn()
** Location: File dominion.c, line 350
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
  printf("Testing endTurn()\n");
  int numPlayers = 2;
  int player1 = 0;
  int player2 = 1;
  struct gameState *state = newGame();
  initializeGame(numPlayers, kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 1, state);

  //Player 1 starts the game
  assertTrue(whoseTurn(state) == 0);

  endTurn(state);

  //Test after player 1 turn ends conditions

  assertTrue(whoseTurn(state) == player2);
  assertTrue(state->handCount[player1] == 0);
  assertTrue(state->handCount[player2] == 5);
  assertTrue(state->outpostPlayed == 0);
  assertTrue(state->phase == 0);
  assertTrue(state->numActions == 1);
  assertTrue(state->numBuys == 1);
  assertTrue(state->playedCardCount == 0);
  assertTrue(state->handCount[player1] == 0);
  assertTrue(state->handCount[player2] == 5);

  //Test wrap-around of player turn when last player ends their turn
  endTurn(state);
  assertTrue(whoseTurn(state) == 0);

  printf("endTurn() test complete\n");

  return 0;
}