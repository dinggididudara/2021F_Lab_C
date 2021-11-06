/**
 * Title: Assignment #1
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 014
 * Professor: Surbhi Bahri
 * Due date: 11/09/2021
 * Submission date: 11/06/2021
 */
#include "Assign1.h" /*include own file*/
/**
 * Function Name: main
 * @purpose: main function display main menu
 * @parms : void
 * @return: 0 / EXIT_SUCCESS
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int main()
{
    leftMoney = 45; /*initial betting money is $45*/
    counting = 0;
    int a = YES; /*answer for yesno question*/
    int result = 0;
    int betting = 0;   /*betting amount return from bet()*/
    int winCount = 0;  /*counting win*/
    int lostCount = 0; /*counting lose*/

    char option; /*option for main menu*/

    while (1) /*until quit*/
    {
        if(counting>0) /*if not first time to play*/
        {
            char *question = "Another Game? [y/n] ";
            a = yesno(question); /*scan option*/
            if(a == NO)
            {
                break;
            }
            betting = bet();
        } /*if end*/
        printf("\t\tROLL THE DICE [ENTER] QUIT TO [q]\n");
        scanf("%c", &option);
        if (option == '\n') /*if enter*/
        {
            if (counting == 0) /*if first time to play*/
            {
                if (playGame() == WON)
                {
                    winCount++;
                }
                else if (playGame() == LOST)
                {
                    lostCount++;
                }
                counting++;
            }
            else /*if it is not first play*/
            {
                if (a == YES)
                {
                    result = playGame();
                    if (result != -1) /*if return not -1*/
                    {
                        if (betting > 0) /*if not 1(false)(no), doing betting*/
                        {
                            if (result == WON)
                            {
                                winCount++;
                                leftMoney += betting*BETMONEY;
                            }
                            else if (result == LOST)
                            {
                                lostCount++;
                                leftMoney -= betting*BETMONEY;
                                if (leftMoney <= 0) /*check if leftMoney is lower than zero*/
                                {
                                    printf("No money left\n");
                                } /*if end*/
                            }
                            else if (result == -1) /*if no more game*/
                            {
                                break;
                            }
                            printf("Your remaining money is $%d\n", leftMoney);
                        }    /*if end*/
                        else /*no betting*/
                        {
                            if (result == WON)
                            {
                                winCount++;
                            }
                            else if (result == LOST)
                            {
                                lostCount++;
                            }
                            else if (result == -1) /*if no more game*/
                            {
                                break;
                            } /*if-else end*/
                        }     /*if-else end*/
                    }
                    else if (result == -1) /*if player does not want another game*/
                    {
                        break;
                    }

                } 
                else /*if answer NO*/
                {
                    break;
                }/*if-else end*/
            }     /*if-else end*/
        }
        else if (option == 'q') /*if q for quit*/
        {
            break;
        }
        else
        {
            printf("Please enter [enter] or [q]\n");
        } /*if-else end*/
    }     /*while end*/
    printf("Thank you for playing\n");
    printf("You won %d game(s) and lost %d game(s)!\n", winCount, lostCount);
    printf("Your remaining money is $%d\n", leftMoney);
    exit(EXIT_SUCCESS); /*quit with EXIT_SUCCESS*/
    return 0;           /*return 0 for main function*/
} /*main end*/

/**
 * Function Name: yesno
 * @purpose: get valid input of question regarding yes/no
 * @parms : question - another game or bet
 * @return: 0(yes) / 1(no) / -1(fail)
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int yesno(char *question)
{
    char yesno[10];
    while (1)
    {
        printf("%s\n", question);
        scanf("%s", yesno);

        if (strcmp(yesno, "y") == 0)
        {
            return YES; /*if yes return 0*/
        }
        else if (strcmp(yesno, "n") == 0)
        {
            return NO; /*if no return 1*/
        }
        else
        {
            printf("please enter only y or n\n\n");
        }      /*if-else end*/
    }          /*while end*/
    return -1; /*if not succeed return -1*/
} /*yesno end*/
