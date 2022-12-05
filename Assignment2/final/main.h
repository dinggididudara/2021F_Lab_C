#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*define macro*/
#define MAX_NAME_LENGTH 100
#define MAX_JOB_LENGTH 100
#define MAX_EMPLOYEE 150

/* Structure required for the program with attributes */
struct employee
{
    char empName[MAX_NAME_LENGTH];
    char empGender;
    int empAge;
    char jobDescription[MAX_JOB_LENGTH];
    struct employee *next;
};

/* Functions required for the program */
char *getName(char name[MAX_NAME_LENGTH], char *message);
char getGender(char gender);
int getAge(int age);
char *getJobDescription(char job[MAX_JOB_LENGTH]);
int listLength(struct employee *head);
struct employee *insertNode(struct employee *front, char name[MAX_NAME_LENGTH], char gender, int age, char job[MAX_JOB_LENGTH]);
struct employee *sortList(struct employee *front);
void printNode(struct employee *p);
struct employee *deleteNode(struct employee *head, int indexDelete);
struct employee *swapInfo(struct employee *head);
char searchList(struct employee *head, char name[]);
struct employee *deleteOrModify(struct employee *head, int);
void displayList(struct employee *head);
void menuDisplay();
char chooseOption();

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
struct employee *insertNode(struct employee *front, char name[MAX_NAME_LENGTH], char gender, int age, char job[MAX_JOB_LENGTH])
{
    struct employee *p;

    p = (struct employee *)malloc(sizeof(struct employee));

    if (p == NULL)
    {

        printf("\nInsertion failed!\n");

        exit(1);
    }
    p->empAge = age;
    p->empGender = gender;
    strcpy(p->empName, name);
    strcpy(p->jobDescription, job);
    p->next = front;
    front = p;
    return front;
    free(p);
}

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
struct employee *sortList(struct employee *front)
{
    struct employee *temp = front;
    while (temp != NULL && temp->next != NULL)
    {
        if (strcmp(temp->empName, temp->next->empName) > 0)
        {
            temp = swapInfo(temp);
        }
        else if (strcmp(temp->empName, temp->next->empName) == 0)
        {
            if (temp->empAge > temp->next->empAge)
            {
                temp = swapInfo(temp);
            }
        }
        temp = temp->next;
    }
    return front;
}

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
struct employee *swapInfo(struct employee *head)
{
    char tempName[MAX_NAME_LENGTH], tempGender, tempJob[MAX_JOB_LENGTH];
    int tempAge;
    struct employee *temp = head;
    strcpy(tempName, temp->empName);
    strcpy(temp->empName, temp->next->empName);
    strcpy(temp->next->empName, tempName);

    tempAge = temp->empAge;
    temp->empAge = temp->next->empAge;
    temp->next->empAge = tempAge;

    tempGender = temp->empGender;
    temp->empGender = temp->next->empGender;
    temp->next->empGender = tempGender;

    strcpy(tempJob, temp->jobDescription);
    strcpy(temp->jobDescription, temp->next->jobDescription);
    strcpy(temp->next->jobDescription, tempJob);

    return head;
}

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
void printNode(struct employee *p)
{
    printf("%s %c %d %s.\n", p->empName, p->empGender, p->empAge, p->jobDescription);
}

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
struct employee *deleteNode(struct employee *head, int indexDelete)
{
    struct employee *tempPointer = head;
    struct employee *headPointer = head;
    int counter = listLength(head);
    if (indexDelete == 1)
    {
        printf("Deletion Successful\n");
        head = head->next;
        free(tempPointer);
        return head;
    }
    else if (indexDelete > 1 && indexDelete < counter)
    {
        int i;
        for (i = 2; i < counter; i++)
        {
            headPointer = tempPointer;
            tempPointer = tempPointer->next;
            if (tempPointer == NULL)
            {
                break;
            }
        }

        if (tempPointer != NULL)
        {
            if (tempPointer == head)
            {
                head = head->next;
            }
            headPointer->next = tempPointer->next;
            tempPointer->next = NULL;
            free(tempPointer);
        }
        return head;
    }
    else
    {
        while (tempPointer->next->next != NULL)
        {
            tempPointer = tempPointer->next;
        }
        tempPointer->next = NULL;
        return head;
    }

    return head;
    free(tempPointer);
}

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int listLength(struct employee *head)
{
    struct employee *temp = head;
    int counter = 0;
    while (temp != NULL)
    {
        counter++;
        printNode(temp);
        temp = temp->next;
    }
    return counter;
}

/*
 * The method is used to delete or modify the employee
 * entry in the given Linked List
 */
struct employee *deleteOrModify(struct employee *head, int mode)
{
    struct employee *pointer = head;
    int index = listLength(head);
    int counter = 0;
    char *chooseEmployee = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
    char yesno;
    int a = 0;
    rewind(stdio);
    chooseEmployee = getName(chooseEmployee, "Enter the name of employee to modify/delete:");
    chooseEmployee[strlen(chooseEmployee) - 1] = '\0'; /*remove enter*/

    while (pointer != NULL || a == 0)
    {
        counter++;
        if (pointer == NULL)
        {
            printf("%s is not in the list\n", chooseEmployee);
        }

        if (strcmp(pointer->empName, chooseEmployee) == 0) /*if found the name in the list*/
        {
            printNode(pointer);
            while (a == 0) /*check if user inputs y/n*/
            {

                printf("Is this the employee you wish to modify/delete from the database? Please confirm y/n\nYou entered:");
                scanf("%c", &yesno);

                if (yesno == 'y' || yesno == 'Y')
                {
                    free(chooseEmployee);
                    if (mode == 3) /*delete*/
                    {
                        head = deleteNode(head, counter);
                        a = 1;
                    }
                    else if (mode == 2) /*modify*/
                    {
                        char gender;
                        char *name;
                        int age;
                        char *job;
                        name = malloc(MAX_NAME_LENGTH * sizeof(char));
                        job = malloc(MAX_JOB_LENGTH * sizeof(char));

                        char *feature = malloc(100 * sizeof(char));
                        while (1)
                        {
                            printf("Enter the employee feature you wish to modify (name, gender, age, job profile): \n");
                            while ((getchar()) != '\n')
                                ; /*clear buffer*/
                            fgets(feature, 101, stdin);
                            feature[strlen(feature) - 1] = '\0';

                            if (strcmp(feature, "name") == 0 || strcmp(feature, "1") == 0)
                            {
                                name = getName(name, "Enter the new name of the employee: ");
                                strcpy(pointer->empName, name);
                                a = 1;

                                break;
                            }
                            else if (strcmp(feature, "gender") == 0 || strcmp(feature, "2") == 0)
                            {
                                gender = getGender(gender);
                                pointer->empGender = gender;
                                a = 1;
                                break;
                            }
                            else if (strcmp(feature, "age") == 0 || strcmp(feature, "3") == 0)
                            {
                                age = getAge(age);
                                pointer->empAge = age;
                                a = 1;
                                break;
                            }
                            else if (strcmp(feature, "job profile") == 0 || strcmp(feature, "4") == 0)
                            {
                                job = getJobDescription(job);
                                strcpy(pointer->jobDescription, job);
                                free(job);
                                a = 1;
                                break;
                            }
                            else
                            {
                                printf("Invalid. Please try again (name, gender, age, job profile)\n");
                            } /*if else end*/
                        }     /*while end*/
                    }         /*if else end*/
                }
                else if (yesno == 'n' || yesno == 'N')
                {
                    a = 1;
                    break;
                }
            } /*while end*/
            pointer = pointer->next;
        } /*if end*/
    }     /*while end*/

    return head;
    free(pointer);
}
/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
void displayList(struct employee *head)
{
    struct employee *temp = head;
    while (temp != NULL)
    {
        printNode(temp);
        temp = temp->next;
    }
    while ((getchar()) != '\n')
        ; /*clear buffer*/
}

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
void menuDisplay()
{

    printf("Choose one of the following options\n");
    printf("[1] Insert data of another employee\n");
    printf("[2] Modify existing employee information\n");
    printf("[3] Delete an employee's data\n");
    printf("[4] Shows all database entries\n");
    printf("[5] To quit\n");
}

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
char chooseOption()
{
    char choice;
    printf("\nYou Pressed: ");
    switch (choice = getchar())
    {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
        return (choice);
    }
    return choice;
}

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
char *getName(char name[MAX_NAME_LENGTH], char *message)
{
    printf("%s\n", message);
    while ((getchar()) != '\n')
        ; /*clear buffer*/

    return fgets(name, MAX_NAME_LENGTH + 1, stdin);
}

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
char getGender(char gender)
{
    do
    {
        printf("Enter Gender: ");
        scanf("%c", &gender);
        if (tolower(gender) != 'm' && tolower(gender) != 'f')
        {
            printf("Invalid input\n");
            while ((getchar()) != '\n')
                ; /*clear buffer*/
        }

    } while (tolower(gender) != 'm' && tolower(gender) != 'f');
    while ((getchar()) != '\n')
        ; /*clear buffer*/
    return gender;
}

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int getAge(int age)
{
    int isTrue = -1;
    do
    {
        printf("\nEnter Age: ");
        isTrue = scanf("%d", &age);

        if (isTrue != 1)
        {
            printf("Invalid input. Please retry!\n");
            age = -1;
        }
        else if (age < 0)
        {
            printf("Invalid entry Please enter a positive number!\n");
            age = -1;
        }
        else if (age > 99)
        {
            printf("Invalid entry Please enter a invalid number!(1-99)\n");
            age = -1;
        }
        while ((getchar()) != '\n')
            ; /*clear buffer*/

    } while (isTrue != 1 || age < 0);

    return age;
}

/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
char *getJobDescription(char job[MAX_JOB_LENGTH])
{
    printf("Job profile : \n");
    return fgets(job, MAX_JOB_LENGTH + 1, stdin);
}