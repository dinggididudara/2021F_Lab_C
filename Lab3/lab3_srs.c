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
#include "lab3_srs.h" /*header*/

/*****************************************************************
 * Function Name: main
 * purpose: student register system, register student idInput with course code
 * @parms void
 * @return 0 int type return 0
 * Version: 1
 * Author: Soomin
 * ****************************************************************
 */
int main()
{
    int x;                /* loop for count*/
    int studentTotal = 0; /* total number of students*/
    int courseTotal = 0;  /* total number of courses*/
    char *question = "Please enter a action number:";
    char *what = "entry...";
    int option;

    printf("Welcome to the Student Registation System (SRS)\n\n");

    studentTotal = studentId(); /* get total students number*/
    courseTotal = courseCode(); /* get courses total number*/

    registerT = (int **)malloc(sizeof(int *) * studentTotal); /* allocate the memory for register table array*/

    for (x = 0; x < studentTotal; x++)
    { /* initialize to zero for register table array*/
        registerT[x] = (int *)calloc(courseTotal, sizeof(int));
    } /* for end*/

    while (1)
    {
        menu();
        getchar();
        option = intInput(question, what, 1, 4, NO);

        switch (option)
        {
        case 1: /* if user choose to register student*/
            updateTable(studentTotal, courseTotal, REGISTER);
            break;
        case 2: /* if user choose to drop student*/
            updateTable(studentTotal, courseTotal, DROP);
            break;
        case 3: /* if user choose to print registration table*/
            display(studentTotal, courseTotal);
            break;
        case 4: /* if user choose to quit*/
            /* free memory for all arrays*/
            free(students);
            students = NULL;
            emptyCourse(courseTotal);
            emptyRegister(courseTotal);
            printf("EXIT_SUCCESS");
            exit(0); /*exit with zero*/
            break;
        default: /* if invalid input*/
            printf("Error: unknown action: %d\n", option);
            printf("Try again...\n");
            break;
        } /* switch end*/
    }     /* while end*/
    return 0;
} /* main end*/
/*****************************************************************
 * menu(): menu display until user input
 * ***************************************************************/
void menu()
{
    printf("\nPlease choose one of the following options\n");
    printf("1- Register a student in a course\n");
    printf("2- Drop a student from a course\n");
    printf("3- Print Registration table\n");
    printf("4- Quit\n");
} /* menu end*/

/*****************************************************************
 * Function Name: display
 * Purpose : printing registration table
 * @parms num : total number of students
 * @parms courseTotal : total number of courses
 * ***************************************************************/
void display(int num, int courseTotal)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        printf("[ ");
        for (j = 1; j <= courseTotal; j++)
        {
            printf(" %d ", registerT[i][j]);

        } /* for end*/
        printf(" ] ");
    } /* for end*/
    printf("\n");
} /* display end*/
/*****************************************************************
 * updateTable : update registeration table with register mode and drop mode
 * @parm studentTotal : total of students
 * @parm courseTotal : total of courses
 * @parm mode : register mode(1) / drop mode(0)
 * *****************************************************************/
void updateTable(int studentTotal, int courseTotal, int mode)
{
    int idIndex;   /* index for students*/
    int codeIndex; /* index for courses*/
    int rd = 0;    /*0(drop), 1(register)*/

    idIndex = checkStudentId(studentTotal);
    codeIndex = checkCourseCode(courseTotal);

    if (mode == 1) /* if it is registering mode*/
    {
        rd = 1;
    } /* if end*/

    registerT[idIndex][codeIndex + 1] = rd; /* if drop will save zero*/

} /* updateTable end*/
/*****************************************************************
 * int studentId(): scan total student
 * @return num student total number
 * *****************************************************************/
int studentId()
{
    int idInput;      /*id input from user*/
    int studentTotal; /*student total*/
    char *question1 = "How many students would you like to register:";
    char *question2 = "Please enter the student ID for student:";
    char *what = "student id";
    int i;

    studentTotal = intInput(question1, what, 1, 20, NO); /* total number of students, ask just one time*/
    students = (int *)calloc(studentTotal, sizeof(int)); /* allocate memory and initialize to zero*/

    for (i = 0; i < studentTotal; i++) /* get all student id*/
    {
        idInput = intInput(question2, what, 10000, 99999, i + 1);
        students[i] = idInput;
    } /*for end*/

    return studentTotal; /* return student total*/
} /* studentId end*/

/*****************************************************************
 * int courseCode(): scan total student
 * @return courseTotal total number of courses
 * ***************************************************************/
int courseCode()
{
    int courseTotal = 0; /*course number input*/
    int i;
    char *question1 = "How many courses are you offering?:"; /* scan total number of courses*/
    char *question2 = "Please enter the course code:";       /* scan all course codes*/
    char *p;                                                 /* pointer for course input*/
    char *what = "course code";

    courseTotal = intInput(question1, what, 0, 20, NO); /* scan total courses, one time. how many courses are you offering?*/
    courses = malloc(courseTotal * sizeof(char *));     /* allocate memory for courses*/

    for (i = 0; i < courseTotal; i++)
    {
        courses[i] = malloc((courseTotal + 1) * sizeof(char *));
        p = stringInput(question2, what, i + 1); /* user input temp*/
        strcpy(courses[i], p);                   /* copy to courses array*/

        free(p);  /* free memory for temporary storage*/
        p = NULL; /* and set null*/
    }             /* for end*/
    return courseTotal;
} /* courseCode end*/

/*****************************************************************
 * checkStudentId : checking if it is valid student id
 * @parm studentTotal : total numver of students
 * @return index of students
 ******************************************************************/
int checkStudentId(int studentTotal)
{
    char *question = "Please enter the student id:";
    int idInput;   /* id input from user*/
    int index;     /* index for students array*/
    int found = 0; /* if found 1*/
    char *what = "student id";
    int i;
    while (1)
    {
        idInput = intInput(question, what, 10000, 99999, NO); /* get int input, no for only one time*/
        for (i = 0; i < studentTotal; i++)
        {
            if (students[i] == idInput)
            {
                found = 1; /* found=1*/
                index = i; /* save index number*/
                break;
            }           /*if end*/
        }               /*for end*/
        if (found == 1) /*if found*/
        {
            return index;
        }
        else /* if not found*/
        {
            printf("Error: student id %d not found. Try again.\n", idInput);
        } /*if-else end*/
    }     /*while end*/
} /*checkStudentId end*/
/*****************************************************************
 * checkCourseCode : checking course code
 * @parm courseTotal : total number or courses
 * @return index of course code
 *****************************************************************/
int checkCourseCode(int courseTotal)
{
    char *question = "Enter a valid course code:";
    char *codeInput; /* course input from user*/
    int index;       /* index for courses*/
    int found = 0;   /* found=1*/
    char *what = "course code";
    int i;
    while (1)
    {
        codeInput = stringInput(question, what, NO); /*no for only one time*/

        for (i = 0; i < courseTotal; i++)
        {
            if (strcmp(courses[i], codeInput) == 0)
            {              /* compare if found*/
                found = 1; /* found*/
                index = i; /* save index*/
                break;     /*No need to go through array anymore*/
            }              /* if end*/
        }                  /* for end*/

        if (found == 1) /* if found*/
        {
            free(codeInput); /* free code input memory*/
            return index;
        }
        else
        {
            printf("Error: course code %s not found. Try again\n", codeInput);
            free(codeInput);  /* free code input*/
            codeInput = NULL; /* and set to null*/
        }                     /* if-else end*/
    }                         /* while end*/
} /* checkCourseCode end*/

/*****************************************************************
 * intInput : scan int type input (student id, menu option, courses total, students total)
 * @parm question : question about what are you scanning
 * @parm min : minimum of value
 * @parm max : maximum of value
 * @count : add count number for question
 * @return input number(int)
 * ***************************************************************/
int intInput(char *question, char *what, int min, int max, int count)
{
    int numInput; /* number input from user*/

    while (1)
    { /* if count is bigger than zero, ask question*/
        (count > 0) ? (printf("%s %d: ", question, count)) : (printf("%s ", question));
        if (scanf("%d", &numInput) != 1) /* if number input not valid (1 is true)*/
        {
            printf("Invalid %s.\n", what); /* invalid msg*/
            while (getchar() != '\n')
                ; /* remove new line*/
        }
        else /*if valid*/
        {
            if (numInput >= min && numInput <= max) /* if it is valid range*/
            {
                return numInput;
            }
            else
            { /*if out of range */
                 printf("Invalid %s.\n", what); /* invalid msg*/
                while (getchar() != '\n')
                    ; /* remove new line*/
            }
        } /* if-else end*/
    }     /* while end*/
} /* intInput end*/

/*****************************************************************
 * stringInput : scan string type input (course code)
 * @parm question : question about what are you scanning
 * @parm min : minimum of value
 * @parm max : maximum of value
 * @count : add count number for question
 * @return input number(int)
 * ***************************************************************/
char *stringInput(char *question, char *what, int count)
{
    char *strInput;    /*array for string input*/
    char inputArr[20]; /*input array for checking*/
    int len = 0;       /*length for inputArr*/
    int ok = 0;        /*if it is valid=1*/
    int i;

    while (1)
    {
        (count > 0) ? (printf("%s %d: ", question, count)) : (printf("%s: ", question));
        scanf("%s", inputArr);  /*read string input*/
        len = strlen(inputArr); /*get length for input*/
        if (len == 7)           /*if length is 7*/
        {
            for (i = 0; i < 7; i++)
            {
                if (!isalnum(inputArr[i])) /*if it is not alphabet and number*/
                {
                    ok = 1; /*ok=1, escape*/
                    break;  /*break for loop*/
                }           /*if end*/
            }               /*for end*/
            if (ok == 0)    /*if string is valid*/
            {
                strInput = malloc(sizeof(char) * len + 1); /*allocate string input*/
                strcpy(strInput, inputArr);                /*and copy input to array*/
                return strInput;                           /*return user input*/
            }
            else
            {
                printf("Invalid %s\n", what);
            } /*if-else end*/
        }
        else
        {
            printf("Invalid %s\n", what);
        } /*if-else end*/
    }     /*while end*/
} /*stringInput end*/

/*****************************************************************
 * emptyCourses : free the memory for courses
 * @parm courseTotal : total course
 *****************************************************************/
void emptyCourse(int courseTotal)
{
    int i;
    for (i = 0; i < courseTotal; i++)
    {
        free(courses[i]);
    } /*for end*/
    free(courses);
    courses = NULL;
    return;
} /*emptyCourses end*/

/*****************************************************************
 * emptyRegister : free the memory for register table
 * @parm courseTotal : total course
 *****************************************************************/
void emptyRegister(int courseTotal)
{
    int i;
    for (i = 0; i < courseTotal; i++)
    {
        free(registerT[i]);
    } /*for end*/
    free(registerT);
    registerT = NULL;
    return;
} /*emptyRegister end*/