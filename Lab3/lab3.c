/**
 * Title: Lab Assessment #3 - Student Registration System
 * Course: CST8234 C Language
 * @Author: Soomin Lee (040899389)
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due date: Oct/18/2022
 * Submission date: Oct/13/2022
 *
 * Demo malloc(), calloc() and free() in C, Ansi-style
 *
 * Status:
 * Requirement #1: valid student id input                               complete
 * Requirement #2: students sotred in own array                         complete
 * Requirement #3: valid code input                                     complete
 * Requirement #4: course code stored in own array                      complete
 * Requirement #5: prompt 3 actions                                     compelte
 * Requirement #6: register/drop -> prompt student id, course code      complete
 * Requirement #7: display table                                        complete
 * Requirement #8: quit action                                          complete
 * Requirement #9: error message                                        complete
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lab3.h" /*header*/

/*****************************************************************
 * Function Name: main
 * purpose: student register system, register student id with course code
 * @parms void
 * @return 0 exit with zero
 * Version: 2
 * Author: Soomin
 * ****************************************************************
 */
int main()
{
    int x;                /* for count*/
    int studentTotal = 0; /* total number of students*/
    int courseTotal = 0;  /* total number of courses*/
    int option;

    printf("Welcome to the Student Registation System.\n\n");

    studentTotal = studentId(); /* get total students number*/

    printf("\n");

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

        printf("  Enter an option from the menu: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1: /* if user choose to register student*/
            displayStudentTable(studentTotal);
            displayCourseTable(courseTotal);
            updateTable(studentTotal, courseTotal, REGISTER);
            break;
        case 2: /* if user choose to drop student*/
            displayRegisterTable(studentTotal, courseTotal);
            updateTable(studentTotal, courseTotal, DROP);
            break;
        case 3: /* if user choose to print registration table*/
            displayRegisterTable(studentTotal, courseTotal);
            break;
        case 4: /* if user choose to quit*/
            /* free memory for all arrays*/
            free(students);
            students = NULL;
            emptyCourse(courseTotal);
            emptyRegister(courseTotal);
            printf("Exiting...\n");
            exit(0); /*exit with zero*/
            break;
        default: /* if invalid input*/
            printf("Error: Unknown Option: %d\n", option);
            printf("Try again...\n");
            break;
        } /* switch end*/
    }     /* while end*/
    return 0;
} /* main end*/
/*****************************************************************
 * Function Name : menu
 * Purpose : print menu
 * @param void
 * @return void
 * ***************************************************************/
void menu()
{
    printf("\nMain Menu:\n");
    printf("  [1]- Register a student into a course\n");
    printf("  [2]- Drop a student from a course\n");
    printf("  [3]- Display Registration table\n");
    printf("  [4]- Exit\n");
} /* menu end*/
/*****************************************************************
 * Function Name: display student table
 * Purpose : printing registration table
 * @param studentTotal total number of students
 * @return void
 * ***************************************************************/
void displayStudentTable(int studentTotal)
{
    int i;
    printf("List of Student Ids\n");
    for (i = 0; i < studentTotal; i++)
    {
        printf("Index [%d] \t %d\n", i, students[i]);
    }
    printf("\n");
}
/*****************************************************************
 * Function Name: display course table
 * Purpose : printing registration table
 * @param courseTotal total number of courses
 * @return void
 * ***************************************************************/
void displayCourseTable(int courseTotal)
{
    int i;
    printf("List of Available Course Id\n");
    for (i = 0; i < courseTotal; i++)
    {
        printf("Index [%d] \t %s\n", i, courses[i]);
    }
}
/*****************************************************************
 * Function Name: displayRegisterTable
 * Purpose : printing registration table
 * @param num : total number of students
 * @param courseTotal : total number of courses
 * @return void
 * ***************************************************************/
void displayRegisterTable(int num, int courseTotal)
{
    int i, j;

    printf("\n\t\t\tRegistration Table\n");
    printf("Registration Index \t Student ID \t Course ID \t Status\n");
    for (i = 0; i < 20; i++) /*find 1 in registration table*/
    {
        if (indexArr[i][2] != 0) /*if last row is zero (registered or drop)*/
        {
            printf("\t %d\t\t %d \t\t %s \t ", i, students[indexArr[i][0]], courses[indexArr[i][1]]);
            if (indexArr[i][2] == REGISTER)
            {
                printf("R\n");
            }
            else if (indexArr[i][2] == DROP)
            {
                printf("D\n");
            }
        }
    } /* for end*/
} /* display end*/
/*****************************************************************
 * Function Name : updateTable
 * Purpose : update registeration table with register mode and drop mode
 * @param studentTotal : total number of students
 * @param courseTotal : total number of courses
 * @param mode : register mode(1) / drop mode(-1)
 * @return void
 * *****************************************************************/
void updateTable(int studentTotal, int courseTotal, int mode)
{
    int idIndex, codeIndex, checking, select, i; /* student index, course code index, select index*/
    int t = 0;

    if (mode == REGISTER) /* if it is registering mode*/
    {
        idIndex = checkStudentId(studentTotal);
        codeIndex = checkCourseCode(courseTotal);
        checking = checkRD(idIndex, codeIndex);
        if (checking == REGISTER) /*if already registered*/
        {
            printf("Student id %d already on record.\n", students[idIndex]);
            t = -1;
        }
        else if (checking == DROP) /*if already dropped*/
        {
            printf("Student id %d have dropped out from course %s", students[idIndex], courses[codeIndex]);
            t = -1;
        }
        else if (checking == 0)
        {
            registerT[idIndex][codeIndex] = REGISTER;
            for (i = 0; i < 20; i++)
            {
                if (indexArr[i][2] == 0) /*if last row is zero*/
                {
                    indexArr[i][0] = idIndex;
                    indexArr[i][1] = codeIndex;
                    indexArr[i][2] = REGISTER;
                    break; /*escape loop*/
                }          /*if end*/
            }              /*for end*/
            printf("Registration Successful.\n");
        }

        if (t == -1) /*error message*/
        {
            printf("Student id %d cannot register to course %s\n", students[idIndex], courses[codeIndex]);
            printf("Registration Unsuccessful\n");
        }
    }
    else if (mode == DROP)
    {
        while (1)
        {
            printf("Please select Index Number to Drop Student Registration: ");
            scanf("%d", &select);
            if (select >= 0 && select < 20)
            {
                checking = checkRD(indexArr[select][0], indexArr[select][1]);
                if (checking == DROP)
                {
                    printf("already dropped out.\n");
                    printf("Drop Course Unsuccessful.\n");
                    break;
                }
                else if (checking == REGISTER)
                {
                    indexArr[select][2] = DROP; /*change to drop (-1)*/
                    registerT[indexArr[select][0]][indexArr[select][1]] = DROP;
                    printf("Drop course Successful.\n");
                    break;
                } /*if else end*/

            }                                           /*if end*/
            printf("Wrong Index Number. Try again.\n"); /*Error message*/
        }                                               /*while end*/
    }
} /* updateTable end*/
/*****************************************************************
 * int studentId(): scan total student
 * @param void
 * @return studentTotal : total number of students
 * *****************************************************************/
int studentId()
{
    int idInput;      /*id input from user*/
    int studentTotal; /*student total*/
    char *what = "Student Id";
    int i;

    printf("Enter the number of students to register: ");
    scanf("%d", &studentTotal);

    students = (int *)calloc(studentTotal, sizeof(int)); /* allocate memory and initialize to zero*/

    for (i = 0; i < studentTotal; i++) /* get all student id*/
    {
        idInput = intInput(i, what, 10000, 99999);
        students[i] = idInput;
    }                    /*for end*/
    return studentTotal; /* return student total*/

} /* studentId end*/

/*****************************************************************
 * int courseCode(): scan total student
 * @param void
 * @return courseTotal : total number of courses
 * ***************************************************************/
int courseCode()
{
    int courseTotal; /*course number input*/
    int i;           /*for for loop*/
    char *temp;      /* pointer for course input*/

    printf("Enter the number of courses available: ");
    scanf("%d", &courseTotal);

    courses = malloc(courseTotal * sizeof(char *)); /* allocate memory for courses*/

    for (i = 0; i < courseTotal; i++)
    {
        courses[i] = malloc((courseTotal + 1) * sizeof(char *));
        temp = stringInput(i);    /* user input temp*/
        strcpy(courses[i], temp); /* copy to courses array*/

        free(temp);  /* free memory for temporary storage*/
        temp = NULL; /* and set null*/
    }                /* for end*/
    printf("\n");
    return courseTotal;
} /* courseCode end*/

/*****************************************************************
 * checkStudentId : checking if it is registered student id
 * @param studentTotal : total number of students
 * @return index of students
 ******************************************************************/
int checkStudentId(int studentTotal)
{
    int idInput;   /* id input from user*/
    int index;     /* index for students array*/
    int found = 0; /* if found, will change to 1*/
    char *what = "Student Id";
    int i;
    while (1)
    {
        idInput = intInput(-1, what, 10000, 99999); /*get student id from user*/
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
 * @param courseTotal : total number or courses
 * @return codeInput : index of course code
 *****************************************************************/
int checkCourseCode(int courseTotal)
{
    char *codeInput; /* course input from user*/
    int index;       /* index for courses*/
    int found = 0;   /*if found=1*/
    int i;
    while (1)
    {
        codeInput = stringInput(-1);

        for (i = 0; i < courseTotal; i++) /*check if it is registered or not*/
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
 * checkRD : check if it is already registered or dropped
 * @param idIndex : index of students
 * @param codeIndex : index of courses
 * @return REGISTER(1) / DROP(-1) / 0
 * ***************************************************************/
int checkRD(int idIndex, int codeIndex)
{
    int i;
    for (i = 0; i < 20; i++)
    {
        if (registerT[idIndex][codeIndex] == REGISTER)
        {
            return REGISTER;
        }
        else if (registerT[idIndex][codeIndex] == DROP)
        {
            return DROP;
        }
        else
        {
            return 0;
        }

    } /*for end*/
}
/*****************************************************************
 * Function Name : intInput
 * Purpose : scan int type input (student id)
 * @param index : index
 * @param min : minimum of value
 * @param max : maximum of value
 * @return numInput : user input
 * ***************************************************************/
int intInput(int index, char *what, int min, int max)
{
    int numInput; /* number input from user*/

    while (1)
    {
        if (index < 0) /*if index is -1*/
        {
            printf("Enter the Student's Id to register a course: ");
        }
        else
        {
            printf("Enter the student index[%d] student id [5-digits]: ", index);
        }

        if (scanf("%d", &numInput) != 1) /* if number input not valid (1 is true)*/
        {
            printf("%s must be 5 digits\n", what); /* invalid msg*/
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
            {                                          /*if out of range */
                printf("%s must be 5 digits\n", what); /* invalid msg*/
                while (getchar() != '\n')
                    ; /* remove new line*/
            }
        } /* if-else end*/
    }     /* while end*/
} /* intInput end*/

/*****************************************************************
 * Function Name : stringInput
 * Purpose : scan string type input (course code)
 * @param index : maximum of value
 * @return strInput : string input from user
 * ***************************************************************/
char *stringInput(int index)
{
    char *strInput;    /*array for string input*/
    char inputArr[10]; /*input array for checking*/
    int len = 0;       /*length for inputArr*/
    int ok1 = 0;
    int ok2 = 0; /*if it is valid=1*/
    int i, j;

    while (1)
    {
        if (index < 0) /*if index is -1*/
        {
            printf("Enter the Course Code [3-Alphas][4-digits]: ");
        }
        else
        {
            printf("Enter the course index[%d] course id [3-Alphas][4-digits]: ", index);
        }                       /*if-else end*/
        scanf("%s", inputArr);  /*read string input*/
        len = strlen(inputArr); /*get length for input*/
        if (len == 7)           /*if length is 7*/
        {
            for (i = 0; i < 3; i++) /*first three should be alphabets*/
            {
                if (!isalpha(inputArr[i])) /*if it is not alphabet*/
                {
                    ok1 = 1; /*ok=1 (false), escape*/
                    break;   /*break for loop*/
                }            /*if end*/
            }                /*for end*/

            for (j = 3; j < 7; j++) /*last four should be numbers*/
            {
                if (!isdigit(inputArr[j])) /*if it is not number*/
                {
                    ok2 = 1; /*ok=1 (false), escape*/
                    break;   /*break for loop*/
                }            /*if end*/
            }                /*for end*/
            if ((ok1 == 0) && (ok2 == 0)) /*if string is valid*/
            {
                strInput = malloc(sizeof(char) * len + 1); /*allocate string input*/
                strcpy(strInput, inputArr);                /*and copy input to array*/
                return strInput;                           /*return user input*/
            }
            else
            {
                printf("Incorrect Course Code input [3-Alphas][4-digits]\n");
                ok1=0; /*reset ok1*/
                ok2=0; /*reset ok2*/
            } /*if-else end*/
        }
        else
        {
            printf("Incorrect Course Code length [7-character Id]\n");
        } /*if-else end*/
    }     /*while end*/
} /*stringInput end*/

/*****************************************************************
 * Fuction Name : emptyCourses
 * Purpose : free the memory for courses
 * @param courseTotal : total number of courses
 * @return void
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
 * Function Name : emptyRegister
 * Purpose : free the memory for register table
 * @param courseTotal : total number of courses
 * @return void
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

} /*emptyRegister end*/
