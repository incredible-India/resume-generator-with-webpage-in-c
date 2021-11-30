struct node
{
    char *userInformation;
    char *InformationTitle;

    struct node *next;


};

struct node* inserDataForUser(struct node *,char[],int,int,int);
void displayUserInformation(struct node *);

void CreateResume()
{

  struct  node *userFName;

   char *userinfo;

   userFName = (struct node *) malloc(sizeof(struct node));

   userinfo = (char*) malloc(100 * sizeof(char));

   system("cls");

    userFName->InformationTitle = "First Name";

        gotoxy(40,12);

 setcolor(2);

 printf("First Name :\n");

 fflush(stdin);

    gets(userinfo);

    userFName->userInformation = userinfo;//(char*)userinfo;



  //  free(userinfo); causes garbage value inside this

    userFName->next = NULL;




   system("cls");

    userFName = inserDataForUser(userFName,"Last Name",40,12,4);

  system("cls");
  userFName = inserDataForUser(userFName,"Father`s Name",40,12,4);

 system("cls");
 userFName = inserDataForUser(userFName,"D.O.B",40,12,4);

system("cls");
 displayUserInformation(userFName);

}

struct node * inserDataForUser(struct node *head,char title[],int x,int y,int colorCode)
{

 struct node *ptr = (struct node *)malloc(sizeof(struct node));

 char *tempUserdata = (char *) malloc(1000*sizeof(char));

         gotoxy(x,y);

 setcolor(colorCode);

 printf("%s",title);

 fflush(stdin);

 gets(tempUserdata);

 ptr->userInformation = tempUserdata;  //(char*) tempUserdata;

 ptr->InformationTitle = title;

    ptr->next = head;




 return ptr;


}

void displayUserInformation(struct node *ptr)
{

    while(ptr != NULL)
    {

        printf("\n%s---> %s",ptr->userInformation,ptr->InformationTitle);
        ptr = ptr->next;
    }
}
