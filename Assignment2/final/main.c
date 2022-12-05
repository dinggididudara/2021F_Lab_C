#include "main.h"
/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
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
        menuDisplay();
        choice = chooseOption();
        switch (choice)
        {
        case '1':
            name = getName(name, "Enter name: ");  
            name[strlen(name)-1]='\0'; /*remove the enter*/
            gender = getGender(gender);
            age = getAge(age);
            jobType = getJobDescription(jobType);
            jobType[strlen(jobType)-1]='\0'; /*remove the enter*/
            linkList = insertNode(linkList, name, gender, age, jobType);
            linkList = sortList(linkList);
   
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
                while ((getchar()) != '\n')
                    ;
                break;
            }
            displayList(linkList);
            while ((getchar()) != '\n')
                ;
            break;
        case '3': /*delete*/
            while ((getchar()) != '\n')
                ;
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