/**
 * Title: Assignment #1
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 014
 * Professor: Surbhi Bahri
 * Due date: 11/09/2021
 * Submission date: 11/02/2021
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
    char *option = ""; /*initialize option for main menu*/
    printf("\t\tROLL THE DICE [ENTER] QUIT TO [q]\n");
    scanf("%s", option);
    menu();       /*display menu*/
    while(option == "q") /*until quit*/
    {
        if (option == "\n") /*if enter*/
        {
            if (playGame() == 0) /*if true*/
            {
                if (bet() == 0) /*if true*/
                {
                    if (checkSum(sumRoll) != -1) /*if checkSum is not -1(false)*/
                    {
                        break; /*if succeed break while loop*/
                    } /**/
                } /**/
            } /**/
        }
        else if (option == "q") /*if q for quit*/
        {
            printf("Thank you for playing\n");
            printf("You won %d gams and lost %d games!\n", winCount, lostCount);
            displayRemaining(); /*remaining money total*/
            exit(EXIT_SUCCESS); /*quit with EXIT_SUCCESS*/
        }
        else
        {
            printf("Please ");
        } /*if-else end*/
    }
    

    return 0; /*return 0 for main function*/
} /*main end*/

/**
 * Function Name: menu
 * @purpose: print main menu
 * @parms : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
void menu()
{
    line();
    printf("  ROLL NUM \t DICE#1 \t DICE#2 \t TOTAL ROLL \t\t POINT MATCH");
    line();
    printf("%10d %8d %8d %10d %10d",);
} /*menu end*/
/**
 * Function Name: line
 * @purpose: print line for display menu
 * @parms : void
 * @return: 0 / EXIT_SUCCESS
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
void line()
{
    int i;
    for (i = 0; i < 80; i++)
    {
        printf("-");
    }
    printf("\n"); /*new line*/
} /*line end*/
/**
 * Function Name: main
 * @purpose: main function display main menu
 * @parms : void
 * @return: 0(yes) / 1(no) / -1(fail)
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
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
            return YES; /*if yes return 0*/
        }
        else if (yesno == 'n')
        {
            return NO; /*if no return 1*/
        }
        else
        {
            printf("please enter only y or n\n");
        }
    } /*while end*/
    return -1; /*if not succeed return -1*/
} /*yesno end*/
