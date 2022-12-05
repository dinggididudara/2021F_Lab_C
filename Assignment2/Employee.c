/**
 * Title: Assignment2, A2.c
 * Course: CST82345 C Language
 * @author: <<< Soomin Lee (040899389) >>>
 * Lab Section: 012
 * Professor: Surbhi Bahri
 * Due date: 12/5/2021
 * Submission date: 11/30/2021
 */

/**
 * Function Name:
 * @purpose:
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
Employee *insertEmployee(Employee *head, char name[MAX_NAME_LENGTH], char gender, int age, char job[MAX_JOB_LENGTH])
{
    Employee *p;

    p = (Employee *)malloc(sizeof(Employee));

    if (p == NULL)
    {

        printf("\failed\n");
    }
    p->age = age;
    p->gender = gender;
    strcpy(p->name, name);
    strcpy(p->job, job);
    p->next = head;
    head = p;
    return head;
    free(p);
}
Employee *sortList(Employee *front)
{
    Employee *temp = front;
    while (temp != NULL && temp->next != NULL)
    {
        if (strcmp(temp->name, temp->next->name) > 0)
        {
            temp = swapInfo(temp);
        }
        else if (strcmp(temp->name, temp->next->name) == 0)
        {
            if (temp->age > temp->next->age)
            {
                temp = swapInfo(temp);
            }
        }
        temp = temp->next;
    }
    return front;
}

Employee *swapInfo(Employee *head)
{
    char tempName[MAX_NAME_LENGTH], tempGender, tempJob[MAX_JOB_LENGTH];
    int tempAge;
    Employee *temp = head;
    strcpy(tempName, temp->name);
    strcpy(temp->name, temp->next->name);
    strcpy(temp->next->name, tempName);

    tempAge = temp->age;
    temp->age = temp->next->age;
    temp->next->age = tempAge;

    tempGender = temp->gender;
    temp->gender = temp->next->gender;
    temp->next->gender = tempGender;

    strcpy(tempJob, temp->job);
    strcpy(temp->job, temp->next->job);
    strcpy(temp->next->job, tempJob);

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
Employee *searchEmployee(Employee *head, char name[])
{
    Employee *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printing(temp);
            return temp;
        }                  /*if end*/
        temp = temp->next; /*if not, go to next node*/
    }                      /*while end*/
    if (temp == NULL)
    {
        printf("\n%s is not in the database!\n", name);
    }
} /*searchEmloyee end*/

/**
 * Function Name:
 * @purpose:
 * @param :
 * @return:
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
void printing(Employee *current)
{

    printf("%s %c %d %s\n", current->name, current->gender, current->age, current->job);
} /*printAll end*/
/**
 * Function Name:
 * @purpose:
 * @param :
 * @return:
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
int listLength(Employee *head)
{
    Employee *temp = head;
    int counter = 0;
    while (temp != NULL)
    {
        counter++;
        printf("[%d]", counter);
        printing(temp);
        temp = temp->next;
    }
    return counter;
}
/**
 * Function Name:
 * @purpose: print the main menu
 * @param : void
 * @return: void
 * @version: 1
 * @author: Soomin Lee (040899389)
 */
Employee *deleteEmployee(Employee *head, int indexDelete)
{
    Employee *tempPointer = head;
    Employee *headPointer = head;
    int counter = listLength(head);
    if (indexDelete == 1)
    {

        printing(head);
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
