/**
 * Title: Assignment #1
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due date: 11/14/2022
 * Submission date: 11/09/2021
 */
#include "Assign1.h"
/**
 * Function Name: rollDice
 * Purpose: make random number of dice
 * @parms : void
 * @return: random number or dice
 * @version: 2
 * @author: Soomin Lee (040899389)
 */
int rollDice()
{
    return ((rand() % 6) + 1); /*return random number of dice*/
} /*rollDice end*/
/**
 * Function Name: playGame
 * Purpose: play game with rolling dice
 * @parms : void
 * @return: WON(0) / LOST(1) / invalid,fail(-1)
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int playGame()
{
    int rollNum = 1; /*roll number starts with 0*/
    int answer = YES;     /*answer for yesno question*/
    int tempCheckSum = 0;       /*temporary for checkSum*/
    int t = 0;
    int pm = 0;            /*point match*/
    int pDice[2] = {0, 0}; /*player dice array*/
    int cDice[2] = {0, 0}; /*computer dice array*/
    int pSum;              /*sum of player's dices*/
    int cSum;              /*sum of computer's dices*/

    menu(); /*display menu one time*/
    while (1)
    {
        pDice[0] = rollDice(); /*player rolls 1*/
        pDice[1] = rollDice(); /*player rolls 2*/
        cDice[0] = rollDice(); /*computer rolls 1*/
        cDice[1] = rollDice(); /*computer rolls 2*/
        pSum = pDice[0] + pDice[1];
        cSum = cDice[0] + cDice[1];
        if(rollNum==1) /*first roll's point match will be player's sum*/
        {
            pm = pSum;
        } /*if end*/
        pm=pSum;
        printf("  %8d  %12d    %12d   %15d    %20d\n", rollNum, pDice[0], pDice[1], pSum, pm);

        if (pSum == 7 || pSum == 11 || pSum == pm) /*if sum is 7 or 11, player win*/
        {
            if (counting == 0)
            {
                printf("Congratulation you roll %d and WIN!!\n\n", pSum);
            }
            else
            {
                printf("Congratulation you roll %d and win on your 2nd try!!!\n\n", pSum);
            } /*if-else end*/
            pm = pSum;
            return WON;
        }
        else if (pSum == 2 || pSum == 3 || pSum == 12) /*if sum is 2, 3 or 12, player lose*/
        {
            if (rollNum == 1)
            {
                printf("You roll %d the losing match. You lose\n\n", pSum);
            }
            else
            {
                printf("You roll %d the losing match. You lose\n\n", pSum);
            }
            pm = pSum;
            return LOST;
        }
        else if (cSum == 7 || cSum == 11 || cSum == pm) /*if sum is 2, 3 or 12, player lose*/
        {
            if (counting == 0)
            {
                printf("Sorry, computer roll %d and you loose at your first try\n\n", cSum);
            }
            else
            {
                printf("Sorry, computer roll %d and you loose\n\n", cSum);
            }
            pm = cSum;
            return LOST;
        }
        else if (cSum == 2 || cSum == 3 || cSum == 12) /*if sum is 2, 3 or 12*/
        {
            if (counting == 0)
            {
                printf("Congratulation computer roll %d and you win at your first try!!!\n\n", cSum);
            }
            else
            {
                printf("Congratulation computer roll %d and you win!!!\n\n", cSum);
            }
            pm = cSum;
            return WON;
        }
        else
        {
            rollNum++; /*increase roll number*/
            printf("Computer rolled %d, game continues...\n");
            if (pm == 0)
            {
                pm = pSum; /*sum will be point match*/
            }              /*if end*/
        }                  /*if-else end*/
    }                      /*while end*/

    return -1; /*return -1*/
} /*playGame end*/

/**
 * Function Name: menu
 * @purpose: print menu for display
 * @parms : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
void menu()
{
    line();
    printf("  ROLL NUM \t  DICE#1 \t  DICE#2 \t TOTAL ROLL \t\t   POINT MATCH\n");
    line();
} /*menu end*/

/**
 * Function Name: line
 * @purpose: print line for display menu
 * @parms : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
void line()
{
    int i;
    for (i = 0; i < 95; i++)
    {
        printf("-");
    }             /*for end*/
    printf("\n"); /*new line*/
} /*line end*/