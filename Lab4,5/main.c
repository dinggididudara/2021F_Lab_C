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
    card *card = (card*) malloc (sizeof(card));
    display();
    int a = compareTwoCards();
    if(a==TRUE)
    {
        printf("1st card won");
    }
    else if(a==FALSE)
    {
        printf("2nd card won");
    }
    return EXIT_SUCCESS;
}