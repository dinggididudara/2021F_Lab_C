#include <stdio.h>
#include "Assign1.h"

int main()
{
    char *option; /*option for main menu*/
    menu();       /*display menu*/
    scanf("%s", option);

    if (option == "\n") /*if enter*/
    {
        playGame(); /*play game*/
    }
    else if (option == "q") /*if q for quit*/
    {
        exit(EXIT_SUCCESS);
    }
    else
    {

    } /*if-else end*/

    return 0; /*return 0 for main function*/
} /*main end*/

/**
 * menu : display menu
 *
 */
void menu()
{
    printf("\t\tROLL THE DICE [ENTER] QUIT TO [q]\n");
    line();
    printf("  ROLL NUM \t DICE#1 \t DICE#2 \t TOTAL ROLL \t\t POINT MATCH");
    line();
} /*menu end*/
/**
 * line : display line for menu
 *
 */
void line()
{
    int i;
    for (i = 0; i < 80; i++)
    {
        printf("-");
    }
} /*line end*/
/**
 *
 *
 */
int rollDice()
{
    int i;
    int *dice = malloc(sizeof(int) * DICETOTAL); /*allocate memory for dice array*/
    int totalRoll = 0;                           /*sum of total roll*/
    for (i = 0; i < DICETOTAL; i++)
    {
        dice[i] = rand(1, 6); /*random number for dice array*/
        totalRoll += dice[i]; /*total roll sum*/
    }                         /*for end*/
    return rollNum++;         /*increase roll number*/
} /*rollDice end*/

/**
 *
 *
 */
int playGame()
{
    int num = rollDice; /*total number of roll*/
    char *yesno;
    while (1)
    {
        printf("Another Game? [y/n] ");
        scanf("%s", yesno);

        if (yesno == "y")
        {
            bet();      /*bet*/
            playGame(); /*play game again*/
        }
        else if (yesno == "n")
        {
            printf("Thank you for playing\n");
            printf("You won %d games and lost %d games!\n");
            exit(EXIT_SUCCESS); /*exit with "EXIT_SUCCESS"*/
            break;              /*break while loop*/
        }
        else
        {
            printf("Please enter only y or n\n");
        }
    } /*while end*/
} /*playGame end*/

/**
 *
 *
 */
int sumUp(int a, int b)
{
    int s = a + b;

    if (s == 7 || s == 11)
    {
        return WON; /*return won(0)*/
    }
    else if (s == 2 || s == 3 || s == 12)
    {
        return LOST; /*return lose(1)*/
    }
    else
    {

    } /*if-else end*/

    return s; /*return sum*/
}

int yesno(char *question)
{
    char yesno;
    while (1)
    {
        printf("%s", question);
        scanf("%c", yesno);
        getchar();
        if (yesno == 'y')
        {
            return 0; /*if yes return 0*/
        }
        else if (yesno == 'n')
        {
            return 1; /*if no return 1*/
        }
        else
        {
            printf("please enter only y or n\n");
        }
    } /*while end*/
} /*yesno*/

/**
 *
 *
 */
void bet()
{
    char *question = "Would you like to bet? [y/n] ";
}