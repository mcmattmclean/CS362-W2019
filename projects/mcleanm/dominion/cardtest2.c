/*
** Card test for: Adventurer
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "testHelpers.h"
#include <string.h>

const int numPlayers = 2;
const int player1 = 0;
const int player2 = 1;

void setupGame(struct gameState *state, int treasureType)
{
  initializeGame(numPlayers, kingdomCards(1, 2, 3, 4, 5, 6, 7, 8, 9, 10), 1, state);
  
  //Set all deck as particular treasure type
  int i;
  for(i = 0; i < state->deckCount[player1]; i++)
  {
    state->deck[player1][i] = treasureType;
  }
}

void checkPreconditions(struct gameState *state)
{
    // Check starting conditions
  assertTrue(state->handCount[player1] == 5);
  assertTrue(state->deckCount[player1] == 5);

  assertTrue(state->handCount[player2] == 0);
  assertTrue(state->deckCount[player2] == 10);
}

int main()
{
  printf("Starting adventurer test\n");

  // Set up
  struct gameState *state = newGame();

  /*
  ** Using copper as treasure
  */
  setupGame(state, copper);
  checkPreconditions(state);

  // Set first card in hand as a adventurer and play it
  state->hand[player1][0] = adventurer;
  cardEffect(adventurer, 0, 0, 0, state, 0, 0);

  // Check ending conditions
  assertTrue(state->handCount[player1] == 6);
  assertTrue(state->deckCount[player1] == 3);

  assertTrue(state->handCount[player2] == 0);
  assertTrue(state->deckCount[player2] == 10);

  assertTrue(state->playedCards[0] == adventurer);

  /*
  ** Using silver as treasure
  */
  setupGame(state, silver);
  checkPreconditions(state);
  // Set first card in hand as a adventurer and play it
  state->hand[player1][0] = adventurer;
  cardEffect(adventurer, 0, 0, 0, state, 0, 0);

  // Check ending conditions
  assertTrue(state->handCount[player1] == 6);
  assertTrue(state->deckCount[player1] == 3);

  assertTrue(state->handCount[player2] == 0);
  assertTrue(state->deckCount[player2] == 10);

  assertTrue(state->playedCards[0] == adventurer);

  /*
  ** Using gold as treasure
  */
  setupGame(state, gold);
  checkPreconditions(state);
  // Set first card in hand as a adventurer and play it
  state->hand[player1][0] = adventurer;
  cardEffect(adventurer, 0, 0, 0, state, 0, 0);

  // Check ending conditions
  assertTrue(state->handCount[player1] == 6);
  assertTrue(state->deckCount[player1] == 3);
  assertTrue(state->handCount[player2] == 0);
  assertTrue(state->deckCount[player2] == 10);

  assertTrue(state->playedCards[0] == adventurer);

  /*
  ** No treasure (all smithys)
  */
  setupGame(state, smithy);
  checkPreconditions(state);
  // Set first card in hand as a adventurer and play it
  state->hand[player1][0] = adventurer;
  cardEffect(adventurer, 0, 0, 0, state, 0, 0);

  // Check ending conditions
  assertTrue(state->handCount[player1] == 4);
  assertTrue(state->deckCount[player1] == 0);
  assertTrue(state->handCount[player2] == 0);
  assertTrue(state->deckCount[player2] == 10);

  assertTrue(state->playedCards[0] == adventurer);

  printf("Adventurer test complete\n");

  return 0;
}