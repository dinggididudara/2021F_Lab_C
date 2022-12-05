/**
 * Title: Assignment #1
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due date: 11/14/2021
 * Submission date: 11/09/2021
 * 
 * 
 * 
 * Status :
 * Requirement #1: define WON LOST                                          Complete
 * Requirement #2: implement function with prototype                        Complete
 * Requirement #3: main - call playGame, keep tracking lost / won count     Complete
 * Requirement #4: conditional operator                                     Complete
 * Requirement #5: multiple .c files                                        Complete
 * Requirement #6: .h file                                                  Complete
 * Requirement #7: header comments                                          Complete
 * Requirement #8: makefile                                                 Complete
 * Requirement #9: input validation                                         Complete
 */
#include "Assign1.h" /*include own file*/
/**
 * Function Name: main
 * @purpose: main function display main menu
 * @param : void
 * @return: 0 / EXIT_SUCCESS
 * @version: 2
 * @author: Soomin Lee (040899389)
 */
int main()
{
    leftMoney = 50; /*initial betting money is $45*/
    counting = 0;
    int a;  /*answer for yesno question*/
    int a2; /*answer for another yesno question*/
    int result = 0;
    int betting = 0;   /*betting amount return from bet()*/
    int winCount = 0;  /*counting win*/
    int lostCount = 0; /*counting lose*/

    char option = 'a'; /*option for main menu*/

    while (1) /*until quit*/
    {
        if (counting == 0)
        { /*first time playing*/
            a2 = yesno("Please enter [y or Y] to play Dice or [n or N] to exit: ");

            if (a2 == NO)
            {
                break;       /*break the while loop*/
            }                /*if end*/
            betting = bet(); /*if want betting, it will return bet number. if not, return -1*/
        }                    /*if end*/

        if (counting > 0) /*if not first time to play*/
        {
            a = yesno("Play another Game? [y/n] "); /*scan option*/

            if (a == NO)
            {
                break;
            }
            else if (a == YES)
            {
                printf("Let's begin\n");
            }                /*else if end*/
            betting = bet(); /*if want betting, it will return bet number. if not, return -1*/
        }                    /*if end*/

        getchar();
        printf("\t\tROLL THE DICE [ENTER], to QUIT enter[q]\n");
        scanf("%c", &option);

        if (option == '\n') /*if enter*/
        {
            result = playGame();
            if (result != -1) /*if return not -1(failed)*/
            {
                counting++;
                if (betting > 0) /*if not -1(false)(no), do betting*/
                {
                    if (result == WON)
                    {
                        winCount++;                      /*increment winning count*/
                        leftMoney += betting * BETMONEY; /*add betting money*/
                    }
                    else if (result == LOST)
                    {
                        lostCount++;
                        leftMoney -= betting * BETMONEY;
                        if (leftMoney <= 0) /*check if leftMoney is lower than zero*/
                        {
                            char *question2 = "You have no more funds. Start-over? [y/n]\n";
                            a = yesno(question2);
                            if (a == YES)
                            {
                                printf("Game have reset, game on.\n");
                                leftMoney = 50; /*reset money to $50*/
                            }
                            else if (a == NO) /*if not play anymore*/
                            {
                                break;
                            } /*if-else end*/
                        }     /*if end*/
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
                } /*if-else end*/
            }
            else if (result == -1) /*if player does not want another game*/
            {
                break;
            } /*if-else end*/
        }
        else if (option == 113 || option == 81) /*if q for quit*/
        {
            break;
        }
        else
        {
            printf("Please enter [enter] or [q]\n");
        } /*if-else end*/

    } /*while end*/
    printf("Thank you for playing, Good bye\n");
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
 * @version: 2
 * @author: Soomin Lee (040899389)
 */
int yesno(char *question)
{
    char yesnoa;

    while (1)
    {
        printf("%s", question);
        scanf(" %c", &yesnoa);

        if (yesnoa >= 65 && yesnoa <= 122)
        {
            if (yesnoa == 89 || yesnoa == 121) /*if y*/
            {
                return YES; /*if yes return 0*/
            }
            else if (yesnoa == 78 || yesnoa == 110) /*if n*/
            {
                return NO; /*if no return 1*/
            }
            else
            {
                printf("Invalid option\n");
            } /*if-else end*/
        }
        else
        {
            printf("Invalid input\n");
        }      /*if-else end*/
    }          /*while end*/
    return -1; /*if not succeed return -1*/
} /*yesno end*/
