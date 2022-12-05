#include "main.h"
/**
 * Function Name: insertNode
 * @purpose: insert node for the employee list
 * @param : front : first node
 * @param : name : employee name
 * @param : gender : employee gender
 * @param : age : employee age
 * @param : job : employee's job
 * @return: struct employee : return the next node
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
 * Function Name: printNode
 * @purpose: print all employee's list
 * @param : p : pointer for first employee node
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
void printNode(struct employee *p)
{
    printf("%s %c %d %s.\n", p->empName, p->empGender, p->empAge, p->jobDescription);
}

/**
 * Function Name: deleteNode
 * @purpose: delete the node
 * @param : head : pointer for first node
 * @param : indexDelete : index number (count number) to delete
 * @return: struct employee : return the first node
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
struct employee *deleteNode(struct employee *head, int indexDelete)
{
    struct employee *tempPointer = head;
    struct employee *headPointer = head;
    int counter = totalNode(head);
    if (indexDelete == 1)
    {
        printf("Deletion Successful\n");
        rewind(stdin);
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
 * Function Name: totalNode
 * @purpose: count the length of list
 * @param : head : pointer for first node
 * @return: int : total length (total node in the list)
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int totalNode(struct employee *head)
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

/**
 * Function Name : deleteOrModify
 * @purpose : find node for delete/modify and delete/modify
 * @param : head : pointer of first node
 * @param : mode : modify = 2 / delete = 3
 * @return : struct employee : return the pointer of first node
 */
struct employee *deleteOrModify(struct employee *head, int mode)
{
    struct employee *pointer = head;
    int index = totalNode(head);
    int counter = 0;
    char *chooseEmployee = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
    char yesno;
    int a = 0;
    rewind(stdin);
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
                rewind(stdin);
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
                                job = getJob(job);
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
 * Function Name: displayList
 * @purpose: print all list
 * @param : head : pointer of first node
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
 * Function Name: menu
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
void menu()
{

    printf("Choose one of the following options\n");
    printf("[1] Insert data of another employee\n");
    printf("[2] Modify existing employee information\n");
    printf("[3] Delete an employee's data\n");
    printf("[4] Shows all database entries\n");
    printf("[5] To quit\n");
}

/**
 * Function Name: getOption
 * @purpose: choose option validation
 * @param : void
 * @return: char : option the user chosen
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
char getOption()
{
    char choice;
    printf("\nYou Pressed: \n");
    switch (choice = getchar())
    {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
        rewind(stdin);
        return (choice);
    }
    return choice;
}

/**
 * Function Name: getName
 * @purpose: name validation
 * @param : name : space for the name
 * @param : message : message need to print before get the user's input
 * @return: char* : name that user input
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
 * Function Name: getGender
 * @purpose: gender input validation
 * @param : gender : variable to save gender
 * @return: char : gender (either f or m)
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
 * Function Name: getAge
 * @purpose: age input validation
 * @param : age : to save age
 * @return: int : validate age (1-99)
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
 * Function Name: getJob
 * @purpose: job input validation
 * @param : job : to save job
 * @return: char * : string of job that user input
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
char *getJob(char job[MAX_JOB_LENGTH])
{
    printf("Job profile : \n");
    return fgets(job, MAX_JOB_LENGTH + 1, stdin);
}
/**
 * Function Name: main
 * @purpose: main function
 * @param : void
 * @return: int : EXIT_SUCCESS
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int main()
{
    struct employee *linkList;
    char *name;
    char *jobType;
    char gender;
    char choice;
    int age;
    name = malloc(MAX_NAME_LENGTH * sizeof(char));
    jobType = malloc(MAX_JOB_LENGTH * sizeof(char));
    linkList = NULL;

    do
    {
        menu();
        choice = getOption();
        switch (choice)
        {
        case '1':
            name = getName(name, "Enter name: ");  
            name[strlen(name)-1]='\0'; /*remove the enter*/
            gender = getGender(gender);
            age = getAge(age);
            jobType = getJob(jobType);
            jobType[strlen(jobType)-1]='\0'; /*remove the enter*/
            linkList = insertNode(linkList, name, gender, age, jobType);
   
            while ((getchar()) != '\n')
                ;
            break;
        case '2': /*modify*/
            if (linkList == NULL)
            {
                printf("List empty\n");
                while ((getchar()) != '\n')
                    ;
                break;
            }

            linkList = deleteOrModify(linkList, 2);
            break;
        case '4': /*print all*/
            if (linkList == NULL)
            {
                printf("List empty\n");
                break;
            }
            displayList(linkList);
            break;
        case '3': /*delete*/
            linkList = deleteOrModify(linkList, 3);
            break;
        case '5':
            printf("Bye\n");
            exit(EXIT_SUCCESS);
            break;
        case 'q':
            printf("Bye\n");
            exit(EXIT_SUCCESS);
            break;
        case 'Q':
            printf("Bye\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Invalid input. Please retry!\n\n");
        }
        printf("\nWhat would you like to do next?\n");
     
    } while (choice != '5');

    return EXIT_SUCCESS;
}