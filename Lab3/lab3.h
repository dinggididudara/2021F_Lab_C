#define NO 0 /*just one time count*/
#define REGISTER 1 /* register mode is 1*/
#define DROP -1 /* drop mode is -1*/

int *students;   /*studnts pointer*/
char **courses;  /*courses pointer*/
int **registerT; /*register table pointer*/ 
int indexArr[20][3]; /*save index in array*/ /*   students index | courses index | R(1) or D(-1) */
/***********************************************
 * Function prototypes.
 ***********************************************/
void menu();
void displayRegisterTable(int studentTotal, int courseTotal);
void displayStudentTable(int studentTotal);
void displayCourseTable(int courseTotal);
void updateTable(int studentTotal, int courseTotal, int mode);
int studentId();
int courseCode();
int checkStudentId(int studentTotal);
int checkCourseCode(int courseTotal);
int checkRD(int idIndex, int codeIndex);
int intInput(int index, char *what, int min, int max);
char *stringInput(int index);
void emptyCourse(int courseTotal);
void emptyRegister(int courseTotal);