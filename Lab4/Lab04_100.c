/**
 * Title: Lab04_100
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due date: 11/21/2021
 * Submission date: 11/14/2021
 */
#include "Lab04_100.h" /*include own file*/
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
 * @purpose: if open then close. if close then open
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
            for(x=0;x<SIZE;x++)
            {
                a[x] = OPEN; /*open all doors*/
            } /*for end*/
        }
        else if(i > 1)
        {
            for (j = i; j <= SIZE; j+=i)
            {
                if (a[j-1] == CLOSE) /*if close*/
                {
                    a[j-1] = OPEN; /*open*/
                }  
                else if(a[j-1] == OPEN) /*if open*/
                {
                    a[j-1] = CLOSE; /* close it*/
                } /*if-else end*/
            }                        /*for end*/
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
    int i;
    int temp;
    for (i = 0; i < SIZE; i++)
    {
        printf("  %d", a[i]);
    } /*for end*/

    return 0; /*return with zero*/
} /*doors_state end*/