//Student1: Mohamad Atef Rabiee	    Section:3	BN:40
//Student2: Mohamad Ahmed Taha	    Section:3	BN:29

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//N is the initial size of array/list
int N;
// A linked list node
typedef struct Node {
    char name[50];
    int id;
    int dd, mm, yy; //Date of Birth
    int score_prev; //Last year's score
    struct Node* next;
}Node;
//list struct
 typedef struct list {
struct Node* head;
struct Node* tail;
int size;
}list;

typedef struct arrayblock {
    char name[50];
    int id;
    int dd, mm, yy; //Date of Birth
    int score_prev; //Last year's score
}arrayblock;


//*********************array insertion*************************

//------------------insert in the middle of array--------------------

void insertMidArray(arrayblock* arrptr)
{
    puts("Type the position to add after");
    printf("the position must be > 0 && < %i\n", N);
    int p; //position
    scanf("%i", &p);

    if (p <= 0 && p >= N)
    {
        puts("You Entered the wrong position");
        return;
    }
    else
    {
        arrptr = (arrayblock*) realloc(arrptr, (N + 1) * sizeof(arrayblock));
        int temp = N;
        for(int i = temp; i >= p + 1; --i)
        {
            *(arrptr + i) = *(arrptr + i - 1);
        }
        puts("Add the new middle student's data");


        read_student_info_arr((arrptr + p));
    }

    N++;
}

//------------------insert in the beginning of array--------------------

void insertBegArray(arrayblock* arrptr)
{

        arrptr = (arrayblock*) realloc(arrptr, (N + 1) * sizeof(arrayblock));
        int temp = N;
        for(int i = temp; i >= 1; --i)
        {
            *(arrptr + i) = *(arrptr + i - 1);
        }
        puts("Add the new beginning student's data");


        read_student_info_arr(arrptr);

    N++;
}
//------------------insert in the end of array--------------------
void insertEndArray(arrayblock* arrptr)
{

        arrptr = (arrayblock*) realloc(arrptr, (N + 1) * sizeof(arrayblock));
        puts("Add the new end student's data");


        read_student_info_arr(arrptr+N);

    N++;
}


//----------------------------------List------------------------------------------

//------------------insert a student at the beginning of list------------------------
void insertBegList(list *listptr, Node* nodeptr)
{
    Node* newPtr = (Node*) malloc(sizeof(Node));
    newPtr = nodeptr;
    newPtr->next = listptr->head;
    listptr->head = newPtr;
    (listptr->size)++;
}


//------------------insert a student at the end------------------------

void insertEndList(list *listptr, Node* nodeptr)
{
    Node* newPtr = (Node*) malloc(sizeof(Node));

    newPtr = nodeptr;
    newPtr->next = listptr->tail->next;
    listptr->tail->next = newPtr;
    listptr->tail = newPtr;
    (listptr->size)++;
}

//------------------insert a student in the middle------------------------
void insertMidList(list *listptr, int position, Node* nodeptr)
{   Node* cptr;
    cptr = listptr->head;
    Node* newPtr = (Node*) malloc(sizeof(Node));
    newPtr = nodeptr;
    for(int i = 0; i < position - 1; ++i)
    {
        cptr = cptr->next;
    }
    newPtr->next = cptr->next;
    cptr->next = newPtr;
    (listptr->size)++;
}

//--------------------function to enter data to list--------------
Node* read_student_info_list()
{

    fflush(stdin);
    Node* nodeptr = (Node*) malloc(sizeof(Node));
    printf("enter student's name : ");
    fgets(nodeptr->name, 50, stdin);

    printf("enter student's ID : ");
    scanf("%i", &(nodeptr->id));

    bool id_is_correct = false;
    while (!id_is_correct)
    {
        if (nodeptr->id >= 0)
            id_is_correct = true;
        else
            {
                puts("The ID is wrong");
                printf("enter a valid ID : ");
                scanf("%i", &(nodeptr->id));
            }
    }

    printf("enter student's last year score ");
    scanf("%i", &(nodeptr->score_prev));
    bool score_is_correct = false;
    while (!score_is_correct)
    {
        if (nodeptr->score_prev >= 0)
            score_is_correct = true;
        else
            {
                puts("INVALID SCORE");
                printf("Enter a valid score : ");
                scanf("%i", &(nodeptr->score_prev));
            }
    }

    printf("enter student's date of birth\n");
    printf("%s","DAY: ");
    scanf("%i", &(nodeptr->dd));
    printf("%s", "MONTH: ");
    scanf("%i", &(nodeptr->mm));
    printf("%s", "YEAR:  ");
    scanf("%i", &(nodeptr->yy));
    bool date_is_correct = false;
    while (!date_is_correct)
    {
        if ((nodeptr->dd > 0 && nodeptr->dd <= 31) && ((nodeptr->mm) > 0
            && (nodeptr->mm) <=12) && ((nodeptr->yy) >= 0))
                date_is_correct = true;
        else
            {
                puts("INVALID DATE");
                printf("%s","enter a valid day ");
                scanf("%i", &(nodeptr->dd));
                printf("%s", "enter a valid month");
                scanf("%i", &(nodeptr->mm));
                printf("%s", "enter a valid year ");
                scanf("%i", &(nodeptr->yy));
            }
    }
    printf("\n\n");
    return nodeptr;
}

//List Initialization
void initlist(list *listptr)
{
    listptr->head = NULL;
    listptr->tail = NULL;
    listptr->size = 0;
}
//------make a list--------
void makelist(int size,list *listptr)
{
    for(int i = 0; i < size; ++i)
    {
        printf("type student number %i's data \n", i + 1);
        if(listptr->head != NULL)
        {
            Node* newPtr = (Node*) malloc(sizeof(Node));

            newPtr = read_student_info_list();
            newPtr->next = listptr->tail->next;
            listptr->tail->next = newPtr;
            listptr->tail = listptr->tail->next;
        }
        else
        {
            Node* newPtr = (Node*) malloc(sizeof(Node));

            newPtr = read_student_info_list();
            newPtr->next = listptr->head;
            listptr->head = newPtr;
            listptr->tail = newPtr;
        }

        (listptr->size)++;
    }
}
//-------------------array----------------------

//--------------------function to enter data to array-------------

void read_student_info_arr(arrayblock *arrayptr)
{

    fflush(stdin);
    printf("Enter the name of your student : ");
    fgets(arrayptr->name, 50, stdin);
    printf("Enter the ID of of your student : ");
    scanf("%i", &(arrayptr->id));

    bool id_is_correct = false;
    while (!id_is_correct)
    {
        if (arrayptr->id >= 0)
            id_is_correct = true;
        else
            {
                puts("ID is wrong");
                printf("Enter a new ID : ");
                scanf("%i", &(arrayptr->id));
            }
    }

    printf("Enter the score of last year of of your student : ");
    scanf("%i", &(arrayptr->score_prev));
    bool score_is_correct = false;
    while (!score_is_correct)
    {
        if (arrayptr->score_prev >= 0)
            score_is_correct = true;
        else
            {
                puts("The Score is wrong");
                printf("Enter a new score : ");
                scanf("%i", &(arrayptr->score_prev));
            }
    }

    printf("Enter date of birth\n");
    printf("%s","Day : ");
    scanf("%i", &(arrayptr->dd));
    printf("%s", "Month :");
    scanf("%i", &(arrayptr->mm));
    printf("%s", "Year : ");
    scanf("%i", &(arrayptr->yy));
    bool date_is_correct = false;
    while (!date_is_correct)
    {
        if ((arrayptr->dd > 0 && arrayptr->dd <= 31) && ((arrayptr->mm) > 0
            && (arrayptr->mm) <=12) && ((arrayptr->yy) >= 0))
                date_is_correct = true;
        else
            {
                puts("The Date is not valid");
                printf("%s","enter a valid day : ");
                scanf("%i", &(arrayptr->dd));
                printf("%s", "enter a valid month :");
                scanf("%i", &(arrayptr->mm));
                printf("%s", "enter a valid year : ");
                scanf("%i", &(arrayptr->yy));
            }
    }
    printf("\n\n");
}

//-------------program to print a list---------------
void printlist(list *listptr)
{   printf("\n");
    printf("List Size : %i !\n\n", listptr->size);
    if (listptr->size == 0)
    {
        puts("EMPTY");
        return;
    }
    Node *cptr = listptr->head;
    puts("The current nodes : ");  printf("\n");
    int count = 1;
    while(cptr != NULL)
    {
        printf("The name of student %i is : %s",count, cptr->name);
        printf("The ID of this student is : %i\n", cptr->id);
        printf("The score of last year of this student is : %i\n", cptr->score_prev);
        printf("The date of birth of this student is : %i.%i.%i\n" , cptr->dd, cptr->mm
               , cptr->yy);
        cptr = cptr->next;
        count++;
        printf("\n\n");
    }
}

//------program to print the dynamic array------
void printdynamicarray(arrayblock* arrayptr)
{
    printf("The number of elements of the array is : %i\n", N);
    for (int i = 0; i < N; ++i)
    {
        printf("The name of student %i is : %s",i + 1, (arrayptr + i)->name);
        printf("The ID of this student is : %i\n", (arrayptr + i)->id);
        printf("The score of last year of this student is : %i\n", (arrayptr + i)->score_prev);
        printf("The date of birth of this student is : %i.%i.%i\n\n\n" , (arrayptr + i)->dd, (arrayptr + i)->mm
               , (arrayptr + i)->yy);
    }
}


//-------------------main------------------------------------
int main () {
printf("----Linked Lists Assignments----\n");
printf("To use a linked list, Enter 0.\tTo use an array, Enter 1\n");
int listOrArr;
scanf("%d",&listOrArr);
if (listOrArr!=0 && listOrArr!=1)
{
  printf ("INVALID ENTRY\n");
  return;
}
printf("Insert the initial size of the list/array, which has to be >=1\n");
scanf("%d",&N);

if (listOrArr==0)
{
list newlist;
initlist(&newlist);
makelist(N,&newlist);
bool terminate=false;
while (!terminate){
printf("Enter 0 to insert in the beginning\tEnter 1 to insert in the middle\tEnter 2 to insert in the end\tEnter 3 to print the list\n");
int bme;
scanf("%d",&bme);
if (bme!=0 && bme!=1 && bme != 2 && bme !=3)
{
  printf ("INVALID ENTRY\n");
  return;
}
Node* nodeptr;
switch (bme){
   case 0:
       nodeptr=read_student_info_list();
       insertBegList(&newlist,nodeptr);
       break;
   case 1:
if (newlist.size <= 1)
{
    puts("Not enough nodes in the list\n");
    break;
                    }
printf("%s", "enter position of insertion : ");
int position;
scanf("%i", &position);
bool positionIscorrect = false;
while (positionIscorrect == false)
    {
    if(position > 0 && position < (newlist.size))
    {
    nodeptr = read_student_info_list();
    insertMidList(&newlist, position, nodeptr);
    positionIscorrect = true;
                                }
    else {
        puts("IINVALID ENTRY");
        puts("enter a VALID position");
        scanf("%i", &position);
                                }
                                            }
        break;
   case 2:
        nodeptr=read_student_info_list();
        insertEndList(&newlist,nodeptr);
        break;
   case 3:
        printlist(&newlist);
        break;

}
printf("To terminate the program enter -1\nEnter anything else to continue\n");
        int t;
        scanf("%d",&t);
        if (t==-1)
            terminate=true;
        else printf("Continuing the program\n");
    }

                    }//end of while
else if (listOrArr==1) {
 arrayblock *dynamic_array= (arrayblock*) malloc (N * sizeof(arrayblock));
for (int i=0; i<N; i++){
read_student_info_arr(dynamic_array+i); }
bool terminate=false;
while (!terminate){
printf("Enter 0 to insert in the beginning\tEnter 1 to insert in the middle\tEnter 2 to insert in the end\tEnter 3 to print the array\n");
int bme; //
scanf("%d",&bme);
if (bme!=0 && bme!=1 && bme != 2 && bme !=3)
{
  printf ("INVALID ENTRY\n");
  return;
}
switch (bme){
   case 0:
       insertBegArray(dynamic_array);
       break;
   case 1:
       insertMidArray(dynamic_array);
       break;
   case 2:
        insertEndArray(dynamic_array);
        break;
   case 3:
        printdynamicarray(dynamic_array);
        break;
   }

            printf("To terminate the program enter -1\nEnter anything else to continue\n");
        int t;
        scanf("%d",&t);
        if (t==-1)
            terminate=true;
        else printf("Continuing the program\n");
                                                    }//end of while
}//end of else if

    return 0;
}
