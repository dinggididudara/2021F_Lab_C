/**
 * Title: Assignment #1
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 014
 * Professor: Surbhi Bahri
 * Due date: 11/09/2021
 * Submission date: 11/02/2021
 */
#include "Assign1.h"
/**
 * Function Name: main
 * Purpose: main function display main menu
 * @parms : void
 * @return: rollNum increase one
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int rollDice()
{
    int i,j,x;
    int sumRoll = 0;  /*sum of total roll*/
    int *dice = malloc(sizeof(int*) * betNum); /*allocate memory for dice 2d row*/
    
    for(i=0; i < betNum;i++)
    {
        dice[i] = malloc(sizeof(int*) * DICETOTAL); /*allocate memory for dice 2d array column*/
        for (j = 0; j < DICETOTAL; j++)
        {
            dice[j] = rand(1, 6); /*random number for dice array*/
            sumRoll += dice[j];   /*total roll sum*/
        } /*for end*/
    } /*for end*/                        
   
    return sumRoll;         /*increase roll number*/
} /*rollDice end*/
/**
 * Function Name: main
 * Purpose: main function display main menu
 * @parms : void
 * @return: 0 / EXIT_SUCCESS
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int playGame()
{
    int num = rollDice(); /*total number of roll*/
    char* question = "Another Game? [y/n] ";
    int a = yesno(question); /*scan option*/
    if(a==YES) /*if yes*/
    {
        
    }
    else if(a==NO) /*if no*/
    {

    } /*if-else end*/
} /*playGame end*/
/**
 * Function Name: sumUp
 * Purpose: main function display main menu
 * @parms : void
 * @return: s sum of rolls
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int checkSum(int s)
{
    if (s == 7 || s == 11) /*if sum is 7 or 11, player win*/
    {
        updateMoney(WON); /*update money*/
        return 0; /*return 0(true)*/
    }
    else if (s == 2 || s == 3 || s == 12) /*if sum is 2, 3 or 12, player lose*/
    {
        updateMoney(LOST); /*update money*/
        return 0; /*return 0(true)*/
    } /*if-else end*/
    return -1; /*return sum*/
}