/*
 * Soomin Lee
 * 040899389
 * Lab 1 - program #4
 * CST8234
 * 012
 * Surbhi Bahri
 * Sep - 19
 * 00_Numbers.c, digits.c, reverse.c, bin2dec.c
 */
#include <stdio.h>

int main()
{
    int binary, i, decimal = 0, start = 1;
    printf("Enter a binary number:  ");
    scanf("%d",&binary);
    printf("The decimal equibvalent of %d is ", binary);

    do {
        i = binary % 10; /*check if it is zero or one*/
        decimal = decimal + i * start;
        binary /= 10; /*binary except last digit*/
        start *= 2; /*go to next*/
    } while(binary > 0);

    printf("%d\n",decimal);

    return 0;
}