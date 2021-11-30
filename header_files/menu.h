//function declarations
void gotoxy(int,int);
void setcolor(int);
void MenuContents(char[],int,int,int);
void helpToUser(void);
void CreateResume(void);
//functions
int showMenu()
{
    extern char choice;
  system("cls");

  SetConsoleTitle("Resume Generator");

  MenuContents("1 : Create Resume",10,5,1);
   MenuContents("2 : SEE History",10,7,2);
    MenuContents("3 : Help",10,9,3);
     MenuContents("4 : Give Contribution to this project",10,11,6);
      MenuContents("5 : Exit ",10,13,4);
     MenuContents("Your Choice ->",16,15,6);

     enterAgain:

     choice = getch();

     if(choice == '1')
     {
         return 1;

     }else if (choice == '2')
     {
        return 2;


     }else if (choice == '3')
     {

      return 3;

     }else if (choice == '4')
     {
         system("start https://github.com/incredible-India/resume-generator-with-webpage-in-c");
            exit(0);
     }else if(choice == '5')
     {
         system("cls");
         MenuContents("Thanx For Visiting US..",40,12,8);
         getche();
         exit(0);

     }

     else
     {
        printf("\a");
        goto enterAgain;

     }


}

//Menu Contents takes data ,x-cord ,y-cord, and the colour code

void MenuContents(char data[],int x,int y,int colorCode)
{

    gotoxy(x,y);
    setcolor(colorCode);
    printf("%s",data);

}


//for changing the co-ordinates of the console window...

void gotoxy(int a ,int b)
{

    COORD x;

    x.X =a;
    x.Y=b;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

void setcolor(int ForgC)
{
     WORD wColor;


     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;


     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {

          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
