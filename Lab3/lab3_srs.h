#define NO 0 /*just one time count*/
#define REGISTER 1 /* register mode is 1*/
#define DROP 0 /* drop mode is 0*/

int *students;   /*studnts pointer*/
char **courses;  /*courses pointer*/
int **registerT; /*register table pointer*/
/***********************************************
 * Function prototypes.
 ***********************************************/
void menu();
void display(int studentTotal, int courseTotal);
void updateTable(int studentTotal, int courseTotal, int mode);
int studentId();
int courseCode();
int checkStudentId(int studentTotal);
int checkCourseCode(int courseTotal);
int intInput(char *question, char *what, int min, int max, int count);
char *stringInput(char *question, char *what, int pCount);
void emptyCourse(int courseTotal);
void emptyRegister(int courseTotal);