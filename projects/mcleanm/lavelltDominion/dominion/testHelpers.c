#include "testHelpers.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// Get a random number in the accepted range of possible players
int getRandomNumberPlayers()
{
    return rand() % (MAX_PLAYERS + 1 - MIN_PLAYERS) + MIN_PLAYERS;
}

// Create randomized array of cards in game, including card being tested
int* getRandomCardSet(int cardToTest)
{
    int* set = malloc(SIZE_CARD_SET * sizeof(int));
    int i;
    for(i = 0; i < SIZE_CARD_SET; i++) 
    {
        set[i] = -1;
    };

    set[0] = cardToTest;

    // Fill rest of array with cards different from existing values
    for(i = 1; i < SIZE_CARD_SET; i++)
    {
        int tryAgain = FALSE;
        int card;
        do
        {
            card = rand() % (treasure_map + 1 - adventurer) + adventurer;
            int j;
            for(j = 0; j < SIZE_CARD_SET; j++)
            {
                if(card == set[j])
                {
                    tryAgain = TRUE;
                    break;
                }
                else
                {
                    tryAgain = FALSE;
                }
            }
        } while (tryAgain == TRUE); 
        set[i] = card;
    }
    return set;
}

// Add treasure and victory point cards to card set
int* getFullCardSet(int cardSet[10])
{
    int* fullSet = malloc((SIZE_CARD_SET + 6) * sizeof(int));
    int i;
    for(i = estate; i < adventurer; i++)
    {
        fullSet[i] = i;
    }
    for(i = 0; i < SIZE_CARD_SET; i++)
    {
        fullSet[i+6] = cardSet[i];
    }
    return fullSet;
}

void getRandomSupplyCounts(struct gameState* state, int cardSet[10])
{
    int numPlayers = state->numPlayers;
    if(numPlayers == 2)
    {
        state->supplyCount[curse] = rand() % 10;
        state->supplyCount[estate] = rand() % 8;
        state->supplyCount[duchy] = rand() % 8;
        state->supplyCount[province] = rand() % 8;
    }
    else if (numPlayers == 3)
    {
        state->supplyCount[curse] = rand() % 20;
        state->supplyCount[estate] = rand() % 12;
        state->supplyCount[duchy] = rand() % 12;
        state->supplyCount[province] = rand() % 12;
    }
    else
    {
        state->supplyCount[curse] = rand() % 30;
        state->supplyCount[estate] = rand() % 12;
        state->supplyCount[duchy] = rand() % 12;
        state->supplyCount[province] = rand() % 12;
    }
    state->supplyCount[copper] = rand() % (60 - (7 * numPlayers));
    state->supplyCount[silver] = rand() % 40;
    state->supplyCount[gold] = rand() % 30;
    int i, j;
    for (i = adventurer; i <= treasure_map; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (cardSet[j] == i)
            {
                if (cardSet[j] == great_hall || cardSet[j] == gardens)
                {
                    if (numPlayers == 2){ 
                        state->supplyCount[i] = rand() % 8; 
                    }
                    else
                    { 
                        state->supplyCount[i] = rand() % 12; 
                    }
                }
                else
                {
                    state->supplyCount[i] = rand() % 10;
                }
                break;
            }
            else    //card is not in the set choosen for the game
            {
                state->supplyCount[i] = -1;
            }
        }
	}
}

void getRandomEmbargoTokens(struct gameState* state, int cardSet[10])
{
    int i, j;
    for (i = adventurer; i <= treasure_map; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (cardSet[j] == i)
            {
                if((rand() % 10) == 1) // Only add embargo tokens occasionally
                {
                    state->embargoTokens[i] = rand() % 4;
                }
            }
        }
    }
}

void getRandomPlayerDecks(struct gameState* state, int cardSet[SIZE_FULL_CARD_SET])
{
    int i;
    for(i = 0; i < state->numPlayers; i++)
    {
        state->deckCount[i] = 0;
        int numCards = rand() % MAX_DECK;
        int j;
        for(j = 0; j < numCards; j++)
        {
            state->deck[i][j] = cardSet[rand() % SIZE_FULL_CARD_SET];
            state->deckCount[i]++;
        }
    }
}

void getRandomPlayerHands(struct gameState* state, int cardSet[SIZE_FULL_CARD_SET])
{
    int i;
    for(i = 0; i < state->numPlayers; i++)
    {
        state->handCount[i] = 0;
        int sizeHand = rand() % TEST_MAX_HAND;
        int j;
        for(j = 0; j < sizeHand; j++)
        {
            state->hand[i][j] = cardSet[rand() % SIZE_FULL_CARD_SET];
            state->handCount[i]++;
        }
    }
}

void getRandomPlayerDiscards(struct gameState* state, int cardSet[SIZE_FULL_CARD_SET])
{
    int i;
    for(i = 0; i < state->numPlayers; i++)
    {
        state->discardCount[i] = 0;
        int sizeDiscards = rand() % MAX_DECK;
        int j;
        for(j = 0; j < sizeDiscards; j++)
        {
            state->discard[i][j] = cardSet[rand() % SIZE_FULL_CARD_SET];
            state->discardCount[i]++;
        }
    }
}

void getRandomPlayedCards(struct gameState* state, int cardSet[SIZE_FULL_CARD_SET])
{
    state->playedCardCount = 0;
    int sizePlayedCards = rand() % MAX_DECK;
    int i;
    for(i = 0; i < sizePlayedCards; i++)
    {
        state->playedCards[i] = cardSet[rand() % SIZE_FULL_CARD_SET];
        state->playedCardCount++;
    }
}


// Takes game state to randomize with the card being tested to ensure it is included
struct gameState* getRandomState(struct gameState* state, int cardToTest)
{
    
    state = newGame();
    int numPlayers = getRandomNumberPlayers();
    int* cardSet = getRandomCardSet(cardToTest);
    initializeGame(numPlayers, cardSet, 1, state);

    int* fullCardSet = getFullCardSet(cardSet);
    getRandomSupplyCounts(state, cardSet);
    getRandomEmbargoTokens(state, cardSet);
    getRandomPlayerDecks(state, fullCardSet);
    getRandomPlayerHands(state, fullCardSet);
    getRandomPlayerDiscards(state, fullCardSet);
    getRandomPlayedCards(state, fullCardSet);
    state->whoseTurn = rand() % state->numPlayers;
    state->numActions = rand() % 3;
    state->numBuys = rand() % 3;
    state->coins = rand() % 12;

    free(cardSet);
    free(fullCardSet);

    return state;
}
