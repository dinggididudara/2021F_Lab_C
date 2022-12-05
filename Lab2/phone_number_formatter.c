/**
 * @file phone_number_formatter.c
 * @author Soomin Lee, 040899389
 *
 * Status:
 *        Compiles without warning(s):               True
 *         Requirement #1 - exit on input of 0:      Complete
 *         Requirement #2 - not a 7-digit number:    Complete
 *         Requirement #3 - invalid phone number:    Complete
 *         Requirement #4 - formatted phone number:  Complete
 *         Requirement #5 - loops until input of 0:  Complete
 */
#include <stdio.h>
#include <string.h>
#define INVALID -1
#define VALID 1
#define QUIT 0

int check(int n); /*define function*/
printFormattedNumber(int n); /*define function*/

int main()
{
    int num; /*number string from user's input*/
    int result;

    while (1)
    {
        printf("Please enter a phone number: ");
        scanf("%d", &num); /*scanning numbers*/
      
        result = check(num); /*result of check function*/
      
        if (result == QUIT)
        {
            printf("Quit signal received\nProgram ended with exit code: 0\n");
            return QUIT; /*return zero*/
        }
        else if (result == INVALID)
        {
            printf("Invalid phone number\n");
        }
        else if (result == VALID)
        {
            printFormattedNumber(num);
        }
    } /*while end*/  
} /*main end*/
/**
 * @brief check if the scanned number is valid, invalid or quit
 * 
 * @param n user input number
 * @return int quit, invalid, or valid
 */
int check(int n)
{
        if (n == 0) /*if input is zero*/
        {
            return QUIT;
        } /*if end*/
        else if (n > 0)
        {
            if((n >= 1 && n <= 1999999)||(n >= 10000000)) /*if less/more than 7 digits*/
            {
                return INVALID;
            }
            else if(n <= 9999999 && n >= 2000000) /*if within valid range = 7 digits and not start with one*/
            {
                return VALID;
            } /*else-if end*/
        }
        else /*if minus or something else*/
        {
            return INVALID;
        } /*if else end*/
} /*check end*/
/**
 * @brief printing Formatted Number
 * 
 * @param n user input number
 */
printFormattedNumber(int n)
{
   printf("the formatted phone number is : %d-%d%d%d%d\n",(n/10000),(n/1000-((n/10000)*10)),(n/100-((n/1000)*10)),(n/10-((n/100)*10)),(n-((n/10)*10))); /*format 000-0000*/
} /*printFormattedNumber end*/