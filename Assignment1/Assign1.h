#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define WON 1 /*win = 1*/
#define LOST 0 /*lost = 0*/
#define DICETOTAL 2 /*total dice = 2*/
#define YES 0 /*YES is 0(true)*/
#define NO 1 /*NO is 1(false)*/
#define BETMONEY 5 /*bet money is $5*/

int leftMoney; /*left money for betting*/
int counting; /*counting for the game*/
/*main.c*/
int yesno(char *question);
/*playGame.c*/
int rollDice();
int playGame();
void menu();
void line();
/*betMoney.c*/
int bet();
