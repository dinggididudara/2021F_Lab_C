/**
 * Title: Lab Assessment #3 - Student Registration System
 * Course: CST8234 C Language
 * @Author: Soomin Lee (040899389)
 * Lab Section: 014
 * Professor: Surbhi Bahri
 * Due date: Oct/17/2021
 * Submission date: Oct/10/2021
 *
 * Demo malloc(), memset(), calloc() and free() in C, Ansi-style
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define REGISTER 1 // register mode is 1
#define DROP 0     // drop mode is 0
// #include "lab3.h" //including private header file

int studentId();
int checkStudentId(int num);
int courseCode();
int checkCourseCode(int courseTotal);
void updateTable(int num, int courseTotal, int mode);
void display(int num, int courseTotal);
void menu();
void emptyStudent(int num);
void emptyCourse(int courseTotal);
void emptyRegister(int num);
// arrays for students id, course code and register table
int* students;
char* courses;
char** registerT;
/*****************************************************************
 * Function Name: main
 * purpose: main function
 * @parms void
 * @return 0 int type return 0
 * Version: 1
 * Author: Soomin
 * ****************************************************************
 */
int main(int argc, char *argv[])
{
    int num = 0;         // number of students
    int courseTotal = 0; // total total course number
    int option = -1;     // user's option

    students = (int *)calloc(num, sizeof(int)); // students id array pointer

    courses = (char *)calloc(courseTotal, sizeof(int)); // set the length for course code array

    // registerT = (char*) calloc(sizeof(char) * courseTotal, sizeof(char)); // register table column
    // registerT[0] = (char*) calloc(sizeof(char)*num*courseTotal, sizeof(char));
    registerT = malloc(num * sizeof(char *)); // malloc register table array
    // struct registerT registerT[20]; //struct size 20 register table

    printf("Welcome to the Student Register System (SRS)\n\n");

    num = studentId();          // get total number of students
    courseTotal = courseCode(); // get total number of courses

    
    for (int q = 0; q < num; q++)             // set to zero the elements
    {
        registerT[q] = malloc(courseTotal * sizeof(char)); // register table row
    }                                                      // for end

    while (1) // do until quit
    {
        menu();               // printing menu
        scanf("%d", &option); // scan the option

        if (option < 5 && isdigit(option) == 0) // if option is under 5, and if it is number
        {
            switch (option)
            {
            case 1: // if user choose to register student
                updateTable(num, courseTotal, REGISTER);
                break;
            case 2: // if user choose to drop student
                updateTable(num, courseTotal, DROP);
                break;
            case 3: // if user choose to print registration table
                display(num, courseTotal);
                break;
            case 4: // if user choose to quit
                printf("EXIT_SUCCESS");
                exit(0);
                break;
            default: // if invalid input
                printf("Error: unknown action: %d\n", option);
                printf("Try again...");
                break;
            } // switch end
        }
        else
        {
            printf("Error: unknown action: %d\n", option);
        } // if-else end
    }     // while end
    // free three arrays
    emptyStudent(num);
    emptyCourse(courseTotal);
    free(registerT);

    return 0;
} // main end
// struct registerT { int studentId; char courseCode[10]; };
/*****************************************************************
 * int studentNumber(): scan total student
 *
 *
 *
 * ***************************************************************
 **/
int studentId()
{
    int num = 0;     // total number of students
    int idInput = 0; // id input
    int count = 0; //count for escape while loop

    printf("How many students would you like to register:");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) // student id into array
    {
        while (count == 0)
        {
            printf("Please enter the student ID for student:");
            scanf("%d", &idInput);

            // && isdigit(idInput)!=0
            if (idInput <= 99999 && idInput > 9999) // if length is 5 and it is number
            {
                students[i] = idInput;
                if (i == num - 1)
                { // if i is last index
                    count = 1;
                }      // if end
                break; // break for loop
            }
            else
            {
                idInput = 0;
                printf("Invalid student Id. Try again...\n");
            } // if-else end
        }     // while end
    }         // for end

    // print all numbers
    printf("[");
    for (int i = 0; i < num; i++)
    {
        printf(" %d ", students[i]);
    } // for end
    printf("]\n");

    return num; // return total of students
} // studentNumber end
/*****************************************************************
 * int checkStudentId(): scan total student
 *
 *
 *
 * ***************************************************************
 **/
int checkStudentId(int num)
{
    int idInput; // student id input
    int index;
    int count = 0;                // count for validation
    for (int i = 0; i < num; i++) // student id into array
    {
        while (count == 0) // until get the right id from user
        {
            printf("Please enter the student ID for student:");
            scanf(" %d", &idInput);
            // && isdigit(idInput)!=0
            if (idInput <= 99999 && idInput > 9999) // if length is 5 and it is number
            {
                if (students[i] == idInput)
                {
                    index = i;
                    count = 1;
                    break; // break for loop
                }
                else
                {
                    printf("Error: student ID %d not found. Try again.\n", idInput);
                    break;
                } // if-else end
            }
            else
            {
                idInput = 0;
                printf("Invalid student Id. Try again...\n");
            } // if-else end
        }     // while end
    }         // for end
    return index;
} // checkStudentId end
/*****************************************************************
 * int courseCode(): scan total student
 * ***************************************************************/
int courseCode()
{
    int courseTotal = 0; // total numbers of course
    char* courseInput;   // course input from user
    int count = 0; //count for escape while loop

    printf("How many courses are you offering?:");
    scanf(" %d", &courseTotal);           // scan courses total
    for (int i = 0; i < courseTotal; i++) // course code into array
    {
        while (count == 0)
        {
            printf("%s",courseInput);
            printf("Please enter the course code for course:");
            scanf(" %7s", courseInput);
            printf("%s",courseInput);

            if (strlen(courseInput) == 7) // length is 7
            {
                strcpy(courses[i], courseInput);
                if (i = courseTotal-1) // if i is last element
                {
                    count = 1;
                } //if end
                break;
            }
            else
            {
                printf("Invalid course code. Try again...\n");
            } // if-else end
        }     // while end
    }         // for end

    // print all courses' code
    printf("[");
    for (int i = 0; i < courseTotal; i++)
    {
        printf(" %s ", courses[i]);
    } // for end
    printf("]\n");

    return courseTotal;
} // courseCode end

/*****************************************************************
 * int checkCourseCode(): scan total student
 * @parm courseTotal total number of courses
 * @return index number
 * ****************************************************************/
int checkCourseCode(int courseTotal)
{
    char courseInput[20]; // course input from user
    int index = -1;       // index for course array
    int count = 0; //count for escape for loop

    while (count == 0) // until get the right course code from user
    {
        for (int i = 0; i < courseTotal; i++) // course code into array
        {
            printf("Please enter the course code for course:");
            scanf(" %s", courseInput);

            if (strlen(courseInput) == 7) // length is 7
            {
                if (strcmp(courses[i], courseInput))
                {
                    index = i; // break if found
                    count = 1;
                    break;
                }
                else // if not found
                {
                    printf("Error: course code %s not found. Try again.\n", courseInput);
                    break;
                } // if-else end
            }
            else
            {
                printf("Invalid course code. Try again...\n");
            } // if-else end
        }     // for end
    }         // while end
    return index;
} // checkCourseCode end
/*****************************************************************
 * int studentNumber(): scan total student
 * @parm num : total number of students
 * @parm courseTotal : total number of courses
 * @parm mode : register 1, drop 0
 * ***************************************************************/
void updateTable(int num, int courseTotal, int mode)
{
    int idIndex = checkStudentId(num);            // check student id and get index
    int codeIndex = checkCourseCode(courseTotal); // check course code and get index

    if (mode == 1) // if mode is register
    {
        // retister all students in register array
        for (int i = 0; i < num; i++)
        {
            strcpy(registerT[i][0], students[idIndex]); // cast int to string
            for (int j = 0; j <= courseTotal; j++)
            {
                strcpy(registerT[i][j], "0"); // copy zero to array
            }
        } // for end

        for (int x = idIndex; x < num; x++)
        {
            for (int y = 1; y <= courseTotal; y++) // first element is student id
            {
                if (registerT[idIndex][y] != NULL) // if the value is null then add coursecode and break
                {                                  // copy course code to register table
                    strcpy(registerT[idIndex][y], courses[y]);
                    break;
                } // if end

            } // for end
        }     // for end
    }
    else if (mode == 0) // if mode is drop
    {
        for (int i = idIndex; i < num; i++)
        {
            for (int j = 1; j <= courseTotal; j++)
            {
                if (strcmp(registerT[idIndex][j], &courses[codeIndex])) //if string compare is matching
                {
                    free(registerT[idIndex][j]);
                    break;
                } // if end
            }     // for end
        }         // for end
    }             // if-else end
} // updateTable end
/*****************************************************************
 * Function Name: display
 * Purpose : printing registration table
 * @parms num : total number of students
 * @parms courseTotal : total number of courses
 * ***************************************************************/
void display(int num, int courseTotal)
{
    for (int i = 0; i < num; i++)
    {
        printf("Student %d : id %d, courses: ", (i + 1), registerT[i][0]); //[][0] always store student id
        for (int j = 1; j <= courseTotal; j++)                             // starting from [][1] is registered course code
        {
            printf(" %d ", registerT[i][j]);
        } // for end
    }     // for end
    printf(".\n");
} // display end
/*****************************************************************
 * menu(): menu display until user input
 * ***************************************************************/
void menu()
{
    printf("Please choose one of the following options\n");
    printf("1- Register a student in a course\n");
    printf("2- Drop a student from a course\n");
    printf("3- Print Registration table\n");
    printf("4- Quit\n");
    printf("Please enter action number: ");
} // menu end
/*****************************************************************
 * emptyCourse(): empty courses array
 * @parm courseTotal : total number of courses
 * ***************************************************************/
void emptyStudent(int num)
{
    free(students);
}
/*****************************************************************
 * emptyCourse(): empty courses array
 * @parm courseTotal : total number of courses
 * ***************************************************************/
void emptyCourse(int courseTotal)
{
    free(courses); // free course array
} // emptyCourse end

/*****************************************************************
 * emptyRegister(): empty register table
 * @parm courseTotal : total number of courses
 * ***************************************************************/
void emptyRegister(int num)
{
    for (int i = 0; i < num; i++)
    {
        free(registerT[i]);
    }
    free(registerT); // free array memory
} // emptyRegister end
