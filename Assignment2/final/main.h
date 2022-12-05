/**
 * Title: Lab Assignment #2 - employee singly linked list
 * Course: CST8234 C Language
 * @Author: Soomin Lee (040899389)
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due date: Dec/04/2022
 * Submission date: Dec/03/2022
 *
 *
 * Status:
 * Requirement #1: maximum 20 chars for name and job                    complete
 * Requirement #2: sufficient memory to hold employees                  complete
 * Requirement #3: specific order                                       incomplete
 * Requirement #4: .c .h files                                          complete
 * Requirement #5: header comments                                      compelte
 * Requirement #9: error message                                        complete
 * Issue : somehow buffer is not clear very well. In some input stage, program will stuck with endless enter.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*define macro*/
#define MAX_NAME_LENGTH 20
#define MAX_JOB_LENGTH 20
#define MAX_EMPLOYEE 150

/* employee structure */
struct employee
{
    char empName[MAX_NAME_LENGTH];
    char empGender;
    int empAge;
    char jobDescription[MAX_JOB_LENGTH];
    struct employee *next;
};

/* Functions prototype */
char *getName(char name[MAX_NAME_LENGTH], char *message);
char getGender(char gender);
int getAge(int age);
char *getJob(char job[MAX_JOB_LENGTH]);
int totalNode(struct employee *head);
struct employee *insertNode(struct employee *front, char name[MAX_NAME_LENGTH], char gender, int age, char job[MAX_JOB_LENGTH]);
void printNode(struct employee *p);
struct employee *deleteNode(struct employee *head, int indexDelete);
struct employee *deleteOrModify(struct employee *head, int);
void displayList(struct employee *head);
void menu();
char getOption();

