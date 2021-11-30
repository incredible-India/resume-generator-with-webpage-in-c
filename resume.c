/*Himanshu Sharma B.E 5th sem */
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>

//user-define header files
#include "./header_files/menu.h"
//global variables
int i,j;
char choice;
struct node
{
    char userInformation[500];
    int index;
    int *next;


} ;

//function declarations
int showMenu();

void main()
{

extern int i;

  i = showMenu();

    printf("%d",i);

}
