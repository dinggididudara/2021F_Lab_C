/*  
 * CST8234_010 C Language
 * Soomin Lee  040899389
 * finding 3,5,15 numbers' multiple between 1 to 100
 */
#include <stdio.h>

void main()
{
    int i;
    for (i = 0; i < 100; i++)
    {
        printf("%d ", (i + 1));
        if (i % 3 == 0 && i % 5 != 0) /*if 3 and 5*/
        {
            printf("I'm a multiple of 3!!!\n");
        }
        else if (i % 5 == 0 && i % 3 != 0) /*if 5 not 3*/
        {
            printf("I'm multiple of 5!!!\n");
        }
        else if (i % 3 == 0 && i % 5 == 0) /*if 3 not 5*/
        {
            printf("I'm multiple of 3 && 5!!!\n");
        }
        else
        {
            printf("\n"); /*if not 3 or 5, line break*/
            
        } /*if-else end*/
    } /*for end*/
    return ;
} /*main end*/