/*
 * Soomin Lee
 * 040899389
 * Lab 1 - program #2
 * CST8234
 * 012
 * Surbhi Bahri
 * Sep - 19
 * 00_Numbers.c, digits.c, reverse.c, bin2dec.c
 */
#include <stdio.h>

int main()
{
    int digits;   /*long long type digits*/
    int count = 0; /*count how many digits*/
    printf("Enter an Integer:  ");
    scanf("%d", &digits); /*scan digits from keyboard*/

    printf("Number of digits in %d is ", digits);

    if (digits < 0)
    { /*if scanned number is under zero*/
        digits *= -1;
    } /*if end*/

    do
    {
        digits /= 10;      /*keep dividing digits*/
        count++;           /**/
    } while (digits != 0); /*do-while end*/

    printf("%d\n", count);

    return 0; /*finish value of 0*/
} /*main end*/