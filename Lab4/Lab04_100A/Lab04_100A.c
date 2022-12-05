/**
 * Title: Lab04_100A
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due date: 11/21/2021
 * Submission date: 11/14/2021
 */
#include "Lab04_100A.h" /*include own file*/
/**
 * Function Name: main
 * @purpose: main function display main menu
 * @param : void
 * @return: 0
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int main()
{
    char door[SIZE] = {0}; /*define array, default value is closed*/
    toogle_door(door);     /*knock the door*/
    doors_state(door);     /*display doors' state*/

    exit(EXIT_SUCCESS); /*Exit with EXIT_SUCCESS*/

    return 0;
}
/**
 * Function Name: toogle_door
 * @purpose: knock the door,
 * @param : char a[] door array
 * @return: int
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int toogle_door(char a[])
{
    int i, j, x;
    for (i = 1; i <= SIZE; i++) /*start from first time and repeat until size of array*/
    {
        if (i == 1) /*if first time*/
        {
            for (x = 0; x < SIZE; x++)
            {
                a[x] = OPEN; /*open all doors*/
            }                /*for end*/
        }
        else if (i > 1)
        {
            for (j = i; j <= SIZE; j += i)
            {
                if (a[j - 1] == CLOSE) /*if close*/
                {
                    a[j - 1] = OPEN; /*open*/
                }
                else if (a[j - 1] == OPEN) /*if open*/
                {
                    a[j - 1] = CLOSE; /* close it*/
                }                     /*if-else end*/
            }                         /*for end*/
        }

    } /*for end*/

    return 0;
} /*toogle_door end*/
/**
 * Function Name: doors_state
 * @purpose: print the doors' state
 * @param : char a[] door array
 * @return: int
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int doors_state(char a[])
{
    int i, j, z, x;
    int temp;
    printf("\n    "); /*new line*/
    for (j = 0; j < 10; j++)
    {
        printf("  %d", j + 1);
    }             /*for end*/
    printf("\n"); /*new line*/
    for (z = 0; z < 35; z++)
    {
        printf("-"); /*print lines*/
    }             /*for end*/
    printf("\n"); /*new line*/
    for (i = 0; i < SIZE; i += 10)
    {
        printf("  %2d", i);
        for (x = i; x < i+10; x++)
        {
            if(a[x] == OPEN) /*if open (1)*/
            {
                a[x] = 'o';
            }
            else if(a[x] == CLOSE) /*if close (0)*/
            {
                a[x] = 'c';
            }
            printf("  %c", a[x]);
        } /*for end*/
        printf("\n"); /*new line*/
    } /*for end*/

    return 0; /*return with zero*/
} /*doors_state end*/