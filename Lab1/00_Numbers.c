/*
 * Soomin Lee
 * 040899389
 * Lab 1 - program #1
 * CST8234
 * 012
 * Surbhi Bahri
 * Sep - 19
 * 00_Numbers.c, digits.c, reverse.c, bin2dec.c
 */
#include <stdio.h>

void main()
{
    int i;
    for (i = 1; i <= 100; i++)
    {
        if (i >= 3) /*except 1 and 2*/
        {
            printf("%d ", i);
            if (i % 3 == 0 && i % 5 != 0) /*if 3 not 5*/
            {
                printf("I'm a multiple of 3!!!\n");
            }
            else if (i % 5 == 0 && i % 3 != 0) /*if 5 not 3*/
            {
                printf("I'm multiple of 5!!!\n");
            }
            else if (i % 3 == 0 && i % 5 == 0) /*if 3 and 5*/
            {
                printf("I'm multiple of 3 && 5!!!\n");
            }
            else
            {
                printf("\n"); /*if not 3 or 5, line break*/

            } /*if-else end*/
        } else {
            printf("%d \n", i);
        }     
    } /*for end*/
} /*main end*/