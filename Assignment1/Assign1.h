#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define WON 1 /*win = 1*/
#define LOST 0 /*lost = 0*/
#define DICETOTAL 2 /*total dice = 2*/


int rollNum=1; /*roll number starts with 1*/
int betMoney = 0; /*bet money starts with 0*/
int winBetMoney = betMoney * 3; /*wining bet is 3 times*/
