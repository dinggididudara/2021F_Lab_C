/**
 * Title: Assignment #1
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due date: 11/14/2021
 * Submission date: 11/06/2021
 */
#include "Assign1.h"

/**
 * Function Name: bet
 * @purpose: betting money for the game
 * @param : void
 * @return: betNum(betting number) / fail,no(-1)
 * @version: 2
 */
int bet()
{
    int betNumber; /*betting number from user*/
    char *question = "Would you like to bet? [y/n] ";
    int a = yesno(question);

    if (a == YES) /*if yes*/
    {
       
        while (1)
        {
            printf("You have $%d, minimum bet is %d, you can make %d total bet(s)\n", leftMoney, BETMONEY, leftMoney / BETMONEY);
            getchar();
            if(scanf("%d", &betNumber)==0) /*if option is not digit*/
            {
                getchar();
                printf("Invalid option\n");
            } 
            else
            {
                if (betNumber > 0 && betNumber <= (leftMoney / BETMONEY)) /*if in the valid range*/
                {
                    printf("You bet $%d\n", betNumber * BETMONEY); /*Print total betting money*/
                    return betNumber;
                }
                else if (betNumber <= 0)
                {
                    printf("Please enter only number between 1-%d\n", leftMoney / BETMONEY);
                }
                else if (betNumber > (leftMoney / BETMONEY))
                {
                    printf("Invalid bet\n");
                } /*if-else end*/
            } /*if-else end*/
            

        } /*while end*/
    }
    else if (a == NO) /*if no*/
    {
        return -1; /*return false(-1,no)*/
    }              /*if-else end*/

    return -1;
} /*bet end*/