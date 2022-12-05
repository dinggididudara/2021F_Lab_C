#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*define macro*/
#define MAX_NAME_LENGTH 100
#define MAX_JOB_LENGTH 100
#define MAX_EMPLOYEE 150
#define SUCCEED 1
#define FAILED 3


/*define struct*/
typedef struct Employee
{
    /*Employee details*/
    char name[MAX_NAME_LENGTH];
    char gender;
    int age;
    char job[MAX_JOB_LENGTH];

    /*pointers to next employee structures in the linked list*/
    struct Employee *next;
} Employee;

/*function prototype*/
void menu();

int checkAge();
char checkGender();
int checkFeature(char*);
void cleanBuffer();
char *checkName(char name[MAX_NAME_LENGTH],char*m);
char *checkJob(char job[MAX_JOB_LENGTH]);

void modifiying(Employee* a, int);
Employee *insertEmployee(Employee *head, char name[MAX_NAME_LENGTH], char gender, int age, char job[MAX_JOB_LENGTH]);
Employee *sortList(Employee *front);
Employee *swapInfo(Employee *head);
int listLength(Employee *head);
Employee *removeEmployee(char *name);
Employee *deleteEmployee(Employee *head, int indexDelete);
Employee *searchEmployee(Employee *head, char name[]);
void printing(Employee*);
void printList(Employee *head);
Employee *delete (Employee *head);









