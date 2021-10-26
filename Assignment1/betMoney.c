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
int leftMoney = 0; /*leftover money starts with 0*/
int available=leftMoney/BETMONEY; /*available betting time*/
int bettingMoney = BETMONEY * 3; /*wining bet is 3 times*/

/**
 * Function Name: bet
 * @purpose: 
 * @parm : void
 * @return: 0 / EXIT_SUCCESS
 * Version: 1
 */
int bet()
{
    char *question = "Would you like to bet? [y/n] ";
    int a = yesno(question);
    while(1)
    {
        if(checkZero()==1) /*if checkZero is false*/
        {
            if (a == YES) /*if yes*/
            {
                printf("You have $%d, total number of $%d is %d\n", leftMoney, BETMONEY, available);
                printf("How many number of $%d would you like to bet? [1-%d]\n", BETMONEY, available); /*betMoney in macro*/
                scanf("%d", betNum);                                                                      /*scan total number for betting*/
                if (betNum >= 0 && betNum <= available)                                                      /**/
                {
                    printf("You bet $%d\n\n", betNum * BETMONEY); /*Print total betting money*/
                    return 0;
                }
                else
                {
                    printf("Please enter only number between 1-%d\n", available);
                } /*if-else end*/
            }
            else if (a == NO) /*if no*/
            {
                return 1; /*return false(1,no)*/
            } /*if-else end*/
        } /*if end*/
    } /*while end*/
    return 0;
} /*bet end*/
/**
 * Function Name: winLost
 * @purpose: 
 * @parm : void
 * @return: 0 / EXIT_SUCCESS
 * Version: 1
 */
void updateMoney(int wl)
{
   if(checkZero()==1) /*if checkZero false*/
   {
       if (wl == WON)
       {
           leftMoney += bettingMoney;
       }
       else if (wl == LOST)
       {
           leftMoney -= bettingMoney;
       } /*if-else end*/
   } /*if end*/
} /*bet end*/
/**
 * Function Name: bet
 * @purpose: 
 * @parm : void
 * @return: 0 / EXIT_SUCCESS
 * Version: 1
 */
void displayRemaining()
{
    printf("Your remaining money is $%d\n", leftMoney);
} /*bet end*/
/**
 * Function Name: checkZero
 * @purpose: 
 * @parm : void
 * @return: 0(true) / 1(false)
 * Version: 1
 */
void checkZero()
{
   if(leftMoney == 0)
   {
       printf("No money left\n");
       return 1; /*return false*/
   }
   exit(EXIT_SUCCESS); /*no more bet available -> exit*/
   return 0; /*return true*/
} /*bet end*/
