//creating node (*Linked List concept)
struct node
{
    char *userInformation;
    char *InformationTitle;

    struct node *next;


};

//function declarations..
struct node* inserDataForUser(struct node *,char[],int,int,int,int);
void SaveInformationInTXTFile(struct node *);
int  ConfirmationResponse(struct node *);

//functions...
void CreateResume()
{

  struct  node *userFName;
    extern int j;
   char *userinfo;

   userFName = (struct node *) malloc(sizeof(struct node));

   userinfo = (char*) malloc(100 * sizeof(char));

   //takking first name


    userFName->InformationTitle = "*First Name";

    enterNameAg:

      system("cls");

    gotoxy(40,12);

    setcolor(2);

    printf("First Name (min 3 char) :\n");

    fflush(stdin);

    gotoxy(40,14);
     setcolor(2);
    gets(userinfo);

    if(strlen(userinfo) < 3)
    {
        printf("\a");
        goto enterNameAg;
    }else
    {
        userFName->userInformation = userinfo;//(char*)userinfo;
           userFName->next = NULL;
    }





  //  free(userinfo); causes garbage value inside this





//user last name


   userFName = inserDataForUser(userFName,"Last Name",40,12,4,1);

  //Father`s name

   userFName = inserDataForUser(userFName,"Father`s Name",40,12,5,1);

//Date-of-birth

 userFName = inserDataForUser(userFName,"D.O.B",40,12,7,1);

 //email

 userFName = inserDataForUser(userFName,"Email ",40,12,5,1);

  //skills

 userFName = inserDataForUser(userFName,"Skills ",40,12,8,1);

 //about

 userFName = inserDataForUser(userFName,"About ",40,12,4,0);

  //city

 userFName = inserDataForUser(userFName,"City ",40,12,9,1);

   //State

 userFName = inserDataForUser(userFName,"State ",40,12,10,1);


   //Address

 userFName = inserDataForUser(userFName,"Address",40,12,4,0);


   //phone

 userFName = inserDataForUser(userFName,"Phone",40,12,12,1);

    //show confirmation message

    j = ConfirmationResponse(userFName);

    if(j)
    {
        SaveInformationInTXTFile(userFName);



    }else
    {
        //user denied
          system("cls");
         MenuContents("Thanx For Visiting US..",40,12,8);
         getche();
         exit(0);
    }

 //displayUserInformation(userFName);

}

struct node * inserDataForUser(struct node *head,char title[],int x,int y,int colorCode,int Options)
{

 struct node *ptr = (struct node *)malloc(sizeof(struct node));

 char *tempUserdata = (char *) malloc(1000*sizeof(char));

 EnterAgain:

  system("cls");

 gotoxy(x,y);

 setcolor(colorCode);

    if(Options)
    {
         printf("%s (*required) :\t",title);
    }else
    {
         printf("%s (optional) :\t",title);

    }




    fflush(stdin);

    setcolor(colorCode);

 gets(tempUserdata);

 if(Options)
 {
     if(strlen(tempUserdata) < 3)
     {
         printf("\a");

         goto EnterAgain;
     }

 }else
 {
     if(strlen(tempUserdata) == 0)
     {
         tempUserdata = "0";
     }


 }

 ptr->userInformation = tempUserdata;  //(char*) tempUserdata;

 ptr->InformationTitle = title;

 ptr->next = head;




 return ptr;


}
//this function save the userinformation..
void SaveInformationInTXTFile(struct node *ptr)
{
    FILE *writeData;

    writeData = fopen("./UserHistory/user.txt","a");

    fprintf(writeData,"\n%s\n ",__DATE__);

    while(ptr != NULL)
    {

        fprintf(writeData,"\n%s  ---> %s\n",ptr->InformationTitle,ptr->userInformation);

        ptr = ptr->next;
    }
      fprintf(writeData,"---END---");
}

//this function will confirm that data has to be send or not

int ConfirmationResponse(struct node *ptr)
{
    extern int i,j;

    char UserChoice;

    system("cls");

    setcolor(7);

    while(ptr != NULL)
    {
        gotoxy(10,2+j);

        j +=2;

        if(ptr->userInformation == "0"){

             printf("%s : Not Available ",ptr->InformationTitle);

        }else
        {
             printf("%s : %s ",ptr->InformationTitle,ptr->userInformation);
        }


        ptr = ptr->next;
    }

     printf("\n");
    printf("\n 1 : For Confirm \t\t 2 : Exit");

    enterData:

    UserChoice = getch();

    if(UserChoice == '1')
    {
        return 1;

    }else if (UserChoice == '2')
    {
         return 0;

    }else
    {
        printf("\a");

        goto enterData;

    }

}
