/**
 * Title: Lab 4 & 5
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 014
 * Professor: Surbhi Bahri
 * Due date: 11/28/2021
 * Submission date: 11/20/2021
 */
#include "Lab4,5.h"
/**
 * Function Name: display
 * Purpose: 
 * @parms 
 * @return 
 * Version : 1
 * Quthor : Soomin Lee
 */
void display(){
    deck d = CardShuffle();
    printf("Single Card Shuffle : %s\n", d);
} /*display end*/
/**
 * Function Name: display
 * Purpose: 
 * @parms 
 * @return 
 * Version : 1
 * Quthor : Soomin Lee
 */
void display2(int f, int s){
    printf("Two Cards Shuffle : %s%s\n", card->face[f], card.suit[s]);
} /*display end*/
/**
 * Function Name: display
 * Purpose: generate random card number with rand()
 * @parms 
 * @return deck 
 * Version : 1
 * Quthor : Soomin Lee
 */
deck CardSuffle(){
    int face = ShuffleFace();
    int suit = ShuffleSuit();

    return deck.deck[face][suit];
} /*CardShuffle end*/
/**
 * Function Name: display
 * Purpose: generate random card number with rand()
 * @parms 
 * @return deck 
 * Version : 1
 * Quthor : Soomin Lee
 */
int ShuffleFace(){
    int face = rand()%13;
   
    return face;
} /*CardShuffle end*/
/**
 * Function Name: display
 * Purpose: generate random card number with rand()
 * @parms 
 * @return deck 
 * Version : 1
 * Quthor : Soomin Lee
 */
int ShuffleSuit(){
    int suit = rand()%4;

    return suit;
} /*CardShuffle end*/
/**
 * Function Name: display
 * Purpose:
 * @parms
 * @return int true(if first card won)/false (if second card won)
 * Version : 1
 * Quthor : Soomin Lee
 */
int compareTwoCards()
{
    /*generate two cards and display*/
    int face1 = ShuffleFace();
    int suit1 = ShuffleSuit();
    display2(face1, suit1);

    int face2 = ShuffleFace();
    int suit2 = ShuffleSuit();
    display2(face2, suit2);

    if(face1 > face2) /*if face1 is bigger than face2*/
    {
        return TRUE; /*1st card won*/
    } 
    else if(face1 < face2) /*if face1 is smaller than face2*/
    {
        return FALSE; /*2nd card won*/
    }
    else if (face1 == face2)
    {
        if(suit1 >= suit2)
        {
            return TRUE; /*1st card won*/
        }
        else if(suit1 < suit2)
        {
            return FALSE; /*2nd card won*/
        } /*if-else end*/
    } /*if-else end*/
} /*compareTwoCards end*/