/**
 * Title: Assignment2, A2.c
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due date: 12/5/2021
 * Submission date: 11/30/2021
 */
#include "A2.h" /*include own header file*/
#include "Employee.c"

/**
 * Function Name: main
 * @purpose: main function display main menu
 * @param : void
 * @return: 0
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int main()
{
    char option;
    Employee *list = NULL;
    char *name;
    char *job;
    char gender;
  
    int age;
    name = malloc(MAX_NAME_LENGTH * sizeof(char));
    job = malloc(MAX_JOB_LENGTH * sizeof(char));
    while (SUCCEED)
    {
        menu();
        printf("You pressed:");
        option = getchar();
        printf("\n");
        if (option == '1') /*insert data*/
        {
            name= checkName(name,"Enter Name:");
            gender = checkGender();
            age = checkAge();
            job = checkJob(job);
            list = insertEmployee(list, name, gender, age, job);
            list = sortList(list);
        }
        else if (option == '2') /*modify data*/
        {
            name = checkName(name, "\nEnter the name of: ");
            searchEmployee(list, name);
            int a = checkFeature("modify");
            modifying(list, a);
        }
        else if (option == '3') /*delete*/
        {
            list = delete (list);
            cleanBuffer();
        }
        else if (option == '4') /*print all*/
        {
            printList(list);
            cleanBuffer();
        }
        else if (option == '5' || option == 'q' || option == 'Q')
        {
            printf("Have a good day\n");
            free(list);
            exit(EXIT_SUCCESS); /*Exit with EXIT_SUCCESS*/
            break;
        }
        else
        {
            printf("Invalid Option in main menu. Please try again\n");
        } /*if else end*/
    }     /*while end*/
    return 0;
} /*main end*/

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
} /*menu end*/

void printList(Employee *head)
{
    Employee *temp = head;
    while (temp != NULL)
    {
        printf("================\nEmployee List\n================\n");
        printing(temp);
        temp = temp->next;
    }
}

/**
 * Function Name: delete
 * @purpose:
 * @param :
 * @return:
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
Employee *delete (Employee *head)
{
    Employee *found = head;
    char *name;
    int feature;
    char yesno;

    feature = checkFeature("delete");

    name = checkName(name, "the name of Employee you wish to delete");
    found = removeEmployee(name);

    if (found != NULL) /*search employee and if not null continue*/
    {
        while (SUCCEED) /*until type right answer*/
        {
            printf("Is this the employee you wish to discard from the database? Please confirm [Y/N] \n");
            /*print all information that user chosen */
            printf("%s %c %d %s", found->name, found->gender, found->age, found->job);
            cleanBuffer();
            scanf("You entered: %c", &yesno);
            cleanBuffer();
            if (strcmp(yesno, 'Y') == 0 || strcmp(yesno, 'y') == 0)
            {
                destroyEmployee(found);
                break;
            }
            else if (strcmp(yesno, 'N') == 0 || strcmp(yesno, 'n') == 0)
            {
                printf("Cancle your request\n");
                break;
            }
            else
            {
                printf("Plese enter y or n\n");
                break;
            } /*if else end*/
        }     /*while end*/
    }
    else if (found == NULL)
    {
        printf("Cannot find in the list\n");
    } /*if else end*/

} /*printAll end*/

/**
 * Function Name:
 * @purpose:
 * @param :
 * @return:
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int checkAge()
{
    int ageIn;
    while (1)
    {
        cleanBuffer();
        printf("Enter Age:");
        scanf("%d", &ageIn);

        if (ageIn > 5 && ageIn < 99)
        {
            return ageIn;
        }
        else if (isalpha(ageIn))
        {
            printf("Please enter number\n");
        }
        else
        {
            printf("Invalid age, please try again (3-98)\n");
        } /*if else end*/

    } /*while end*/
    return FAILED;
} /*checkAge end*/

/**
 * Function Name:
 * @purpose:
 * @param :
 * @return:
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
char checkGender()
{
    char genderIn = malloc(sizeof(char));
    while (SUCCEED)
    {
        cleanBuffer();
        printf("Enter Gender:");
        scanf("%c", &genderIn);

        if (genderIn == 'f' || genderIn == 'F' || genderIn == 'm' || genderIn == 'M')
        {
            return genderIn; /*if valid input return that*/
            free(genderIn);
        }
        else
        {
            printf("Please enter f or m\n");
        }
    } /*while end*/
    return FAILED;
}

/**
 * Function Name:
 * @purpose:
 * @param :
 * @return:
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int checkFeature(char *mode)
{
    char feature[100];
    int temp;
    while (SUCCEED)
    {
        printf("Enter the employee feature you wish to %s (name, gender, age, job profile): ", mode);
        scanf("%s", feature);
        cleanBuffer();
        if (strcmp(feature, "name") == 0 || strcmp(feature, "1") == 0)
        {
            temp = 1;
            break;
        }
        else if (strcmp(feature, "gender") == 0 || strcmp(feature, "2") == 0)
        {
            temp = 2;
            break;
        }
        else if (strcmp(feature, "age") == 0 || strcmp(feature, "3") == 0)
        {
            temp = 3;
            break;
        }
        else if (strcmp(feature, "job profile") == 0 || strcmp(feature, "4") == 0)
        {
            temp = 4;
            break;
        }
        else
        {
            printf("Invalid. Please try again (name, gender, age, job profile)\n");
        } /*if else end*/
    }     /*while end*/

    return temp;
} /*checkFeature end*/

void cleanBuffer()
{
    while (getchar() != '\n')
        ;
}

char *checkName(char name[MAX_NAME_LENGTH], char *message)
{
    printf("%s", message);
    return fgets(name, MAX_NAME_LENGTH + 1, stdin);
}

char *checkJob(char job[MAX_JOB_LENGTH])
{
    printf("Enter employee job : ");
    return fgets(job, MAX_JOB_LENGTH + 1, stdin);
}
void modifying(Employee* e, int a)
{
    char gender;
    char *name;
    int age;
    char *job;
    name = malloc(MAX_NAME_LENGTH * sizeof(char));
    job = malloc(MAX_JOB_LENGTH * sizeof(char));
    switch (a)
    {
    case 1:
        name = checkName(name, "Enter the new name of the employee: ");
        strcpy(e->name, name);
        break;
    case 2:
        gender = checkGender();
        e->gender = gender;
        break;
    case 3:
        age = checkAge();
        e->age = age;
        break;
    case 4:
        e = checkJob(job);
        strcpy(e->job, job);
        break;
    case 5:
        printf("===== Returning to main menu =====\n");
        break;
    default:
        printf("Invalid input! please retry!\n");
    }
}