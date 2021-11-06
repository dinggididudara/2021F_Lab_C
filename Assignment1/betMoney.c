/**
 * Title: Assignment #1
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 014
 * Professor: Surbhi Bahri
 * Due date: 11/09/2021
 * Submission date: 11/06/2021
 */
#include "Assign1.h"

/**
 * Function Name: bet
 * @purpose: betting money for the game
 * @parm : void
 * @return: betNum(betting number) / fail,no(-1)
 * Version: 1
 */
int bet()
{
    int betNum; /*betting number*/
    char *question = "Would you like to bet? [y/n] ";
    int a = yesno(question);
 
        if (a == YES) /*if yes*/
        {
            printf("You have $%d, total number of $%d is %d\n", leftMoney, BETMONEY, leftMoney / BETMONEY);
            printf("How many number of $%d would you like to bet? [1-%d]\n", BETMONEY, leftMoney / BETMONEY); /*betMoney in macro*/
            while (1)
            {
                scanf("%d", &betNum);                               /*scan total number for betting*/
                if (betNum > 0 && betNum <= (leftMoney / BETMONEY)) /*if in the valid range*/
                {
                    printf("You bet $%d\n", betNum * BETMONEY); /*Print total betting money*/
                    return betNum;
                }
                else
                {
                    printf("Please enter only number between 1-%d\n", leftMoney / BETMONEY);
                } /*if-else end*/
            }     /*while end*/
        }
        else if (a == NO) /*if no*/
        {
            return -1; /*return false(1,no)*/
        }             /*if-else end*/
    
    return -1;
} /*bet end*/