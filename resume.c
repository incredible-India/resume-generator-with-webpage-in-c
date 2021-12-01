/*Himanshu Sharma B.E 5th sem */
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>

//user-define header files
#include "./header_files/menu.h"
#include "./header_files/helpAndHistory.h"
#include "./header_files/userinfo.h"
//global variables
int i,j;
char choice;

//function declarations
int showMenu();
void helpToUser(void);
void CreateResume(void);
void ShowUserHistory(void);


//start
void main()
{

extern int i;

  i = showMenu();

  if(i == 1)
  {
      CreateResume();

  }else if (i == 2)
  {
      ShowUserHistory();

  }else
  {
      helpToUser();
  }




}
