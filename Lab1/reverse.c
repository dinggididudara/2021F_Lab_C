/*
 * Soomin Lee
 * 040899389
 * Lab 1 - program #3
 * CST8234
 * 012
 * Surbhi Bahri
 * Sep - 19
 * 00_Numbers.c, digits.c, reverse.c, bin2dec.c
 */
#include <stdio.h>

int main()
{
    int num; /*number for scanner*/
    int reverse = 0; /*reverse number*/
    int i; /*temporary number*/

    printf("Enter an Integer:  ");
    scanf("%d",&num); /*scan number from keyboard*/

    do {
        i = num % 10;
        reverse = reverse * 10 + i; 
        num /= 10;      /*go to next digit*/
    } while (num != 0); /*do-while end*/

    printf("The reserved number is %d\n", reverse); /*print reversed number*/

    return 0;
}