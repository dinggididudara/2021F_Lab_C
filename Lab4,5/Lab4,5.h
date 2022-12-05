#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1
#define WON 0

/**
 * Struct Name: card
 * Purpose: 
 * @parms 
 * @return 
 * Version : 1
 * Quthor : Soomin Lee
 */
typedef struct card
{
    /* Ace, King, Queen, Jack, 2-10 */
    /* A > K > Q > J > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2 */
    char *faceArr[13] = {"A", "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
    /*Spades, Hearts, Diamonds, Clubs*/
    /*S > H > D > C*/
    char suitArr[4] = {'S', 'H', 'D', 'C'};
} card;
/**
 * Struct Name: deck
 * Purpose: 
 * @parms 
 * @return 
 * Version : 1
 * Quthor : Soomin Lee
 */
typedef struct deck
{
    int i,j;
    /*deck 2d array : 13 face + 4 suit*/
    char *deckArr[13][4]; 
    for(i=0;i<13;i++)
    {
        for(j=0;j<4;j++)
        {
            deckArr[i][j] = strcpy(card->faceArr[i]+card.suitArr[j]);
        } /*for end*/
    } /*for end*/
} deck;
/**
 * Struct Name: player
 * Purpose: 
 * @parms 
 * @return 
 * Version : 1
 * Quthor : Soomin Lee
 */
typedef struct player
{
   char *playerCard[2][2];
} player;