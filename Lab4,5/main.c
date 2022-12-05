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
int main(){
    /*card *card = (card*) malloc (sizeof(card));*/
    /*display single card*/
    display();
    /*display two cards*/
    int a = compareTwoCards();
    if(a==TRUE) /*1st card won*/
    {
        printf("1st card won");
    }
    else if(a==FALSE) /*2nd card won*/
    {
        printf("2nd card won");
    }
    /*2 players are playing game, dealing*/
    player p1, p2;
    
    return EXIT_SUCCESS;
} /*main end*/