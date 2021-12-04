//creating node (*Linked List concept)
struct node
{
    char *userInformation;
    char *InformationTitle;
    int indexNumber;

    struct node *next;


};

//function declarations..
struct node* inserDataForUser(struct node *,char[],int,int,int,int,int);
void SaveInformationInTXTFile(struct node *);
int  ConfirmationResponse(struct node *);
int ImageConfimation(void);
void  createHTMLFileResume(struct node *);
void appendInHTML(struct node *,int,FILE *);
int checkUserImageForResume(struct node *);

//functions...
void CreateResume()
{

  struct  node *userFName;
   int j,i;
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
        userFName->indexNumber = 0;
           userFName->next = NULL;
    }





  //  free(userinfo); causes garbage value inside this





//user last name


   userFName = inserDataForUser(userFName,"Last Name",40,12,4,1,1);

  //Father`s name

   userFName = inserDataForUser(userFName,"Father`s Name",40,12,5,1,2);

//Date-of-birth

 userFName = inserDataForUser(userFName,"D.O.B",40,12,7,1,3);

 //email

 userFName = inserDataForUser(userFName,"Email ",40,12,5,1,4);

  //skills

 userFName = inserDataForUser(userFName,"Skills ",40,12,8,1,5);

 //about

 userFName = inserDataForUser(userFName,"About ",40,12,4,0,6);

  //city

 userFName = inserDataForUser(userFName,"City ",40,12,9,1,7);

   //State

 userFName = inserDataForUser(userFName,"State ",40,12,10,1,8);


   //Address

 userFName = inserDataForUser(userFName,"Address",40,12,4,0,9);


   //phone

 userFName = inserDataForUser(userFName,"Phone",40,12,12,1,10);

 //for the image confirmation..

 i = ImageConfimation();

 if(i == 2)
 {
     //image..
    //  userFName = inserDataForUser(userFName,"Image Name",40,12,7,0,11);

 }else
 {
       userFName = inserDataForUser(userFName,"Image Name",40,12,7,1,11);

 }

    //show confirmation message

    j = ConfirmationResponse(userFName);

    if(j)
    {
        SaveInformationInTXTFile(userFName);
        //now time to create html file...
        createHTMLFileResume(userFName);

        system("start MyResume/user.html");
        exit(0);





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

struct node * inserDataForUser(struct node *head,char title[],int x,int y,int colorCode,int Options,int IndexInfo)
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
         printf("%s (optional, hit \'Enter\' to skip) :\t",title);

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

 ptr->indexNumber = IndexInfo;

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

      fclose(writeData);
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

int ImageConfimation()
{

   char IMGchoice;

    gotoxy(40,12);

    system("cls");

    printf("Do You want to add Image. (yes : y or no : n)");

    gotoxy(40,14);

    imfINfo:

    IMGchoice = getch();

    if(IMGchoice == 'n' || IMGchoice == 'N')
    {
        return 2;

    }else if(IMGchoice == 'y' || IMGchoice == 'Y')
    {
        system("cls");
        gotoxy(40,12);
        printf("paste your image in MyResume folder in main directory, and write name with extension (ex : user.jpg)\n");
        getch();

        return 1;

    }else
    {

        printf("\a");
        goto imfINfo;
    }



}


//here we will create html file file

void  createHTMLFileResume(struct node *ptr)
{

    FILE *existingFILE,*towrite,*lasttext,*aboutTEXT;

    existingFILE = fopen("./impFiles/base1.txt","r");

     lasttext = fopen("./impFiles/last.txt","r");

    towrite =  fopen("./MyResume/user.html","w");

    aboutTEXT = fopen("./impFiles/about.txt","r");

    char datareading;
    char lastline;
    char aboutUser;
    int isUserIMG;

//starting;



    if(existingFILE == NULL)
    {
        system("cls");
        gotoxy(40,12);
        printf("File Error !");
        getch();
        exit(0);
    }else
    {

         while(!feof(existingFILE))
    {

       datareading=fgetc(existingFILE);

        fputc(datareading,towrite);

    }


    }
    //in between data need to be inserted..

      fprintf(towrite,"<h1 class=\'fname\'>");
        appendInHTML(ptr,0,towrite);
         fprintf(towrite,"<span class=\"else\">");
           appendInHTML(ptr,1,towrite);
           fprintf(towrite," \t</span> </h1>\n<div class=\"con\">\n <h6><a href=\"tel:+91");
            appendInHTML(ptr,10,towrite);
             fprintf(towrite,"\"> <i class=\"fas fa-phone\"></i>");
             appendInHTML(ptr,10,towrite);
             fprintf(towrite,"</a></h6>\n<h6><a href=\"mailto:");
             appendInHTML(ptr,4,towrite);
              fprintf(towrite,"\"> <i class=\"fas fa-envelope-open\"></i> mail us</a></h6>\n</div>\n</div>\n</div>\n</div>");
                 fprintf(towrite,"<!-- About  -->\n<div class=\"about container\" >\n<h1 class=\"og harsh\"><a name=\"education\" class=\"og\">");
                   appendInHTML(ptr,0,towrite);
                    fprintf(towrite," ");
                       appendInHTML(ptr,1,towrite);
                    fprintf(towrite,"</a></h1>\n<h4 class=\"og harsh\"><a name=\"about\" class=\"og\">");
                     appendInHTML(ptr,3,towrite);
                     fprintf(towrite,"( Father : ");
                     appendInHTML(ptr,2,towrite);
                      fprintf(towrite,")</a>\n</h4>\n<p>");
                        appendInHTML(ptr,6,towrite);

            if(aboutTEXT == NULL)
            {
                system("cls");
        gotoxy(40,12);
        printf("File Error !");
        getch();
        exit(0);

            }else
            {


        while(!feof(aboutTEXT))
    {

      aboutUser=fgetc(aboutTEXT);

        fputc(aboutUser,towrite);

    }

            }

             appendInHTML(ptr,5,towrite);
              fprintf(towrite," </h3></div>\n<!-- adderess   -->\n<div class=\"about container\" ><hr>\n<h1 class=\"og harsh\"><a name=\"address\" class=\"og\">Address</a></h1><h3 class=\"skills\">");
                appendInHTML(ptr,7,towrite);
                fprintf(towrite,", ");
                 appendInHTML(ptr,8,towrite);
                   fprintf(towrite,"</h3>\n<h3 class=\"skills\">");
                    appendInHTML(ptr,9,towrite);
                    fprintf(towrite,"\n</h3>\n</div>");

                    //first we will check user Image

    isUserIMG = checkUserImageForResume(ptr);

    if(isUserIMG)
    {
         fprintf(towrite,"<script>\nlet Userimg = document.getElementById(\'userimg\');\nUserimg.remove()\nlet USERIMG = document.getElementsByClassName(\'userimgInsert\')[0];\n USERIMG.innerHTML = `<img src=\"");
          appendInHTML(ptr,11,towrite);
          fprintf(towrite, "\" alt=\"\" class=\"img-fluid mainimg\" width=\"150\" height=\"110px\" id=\"userimg\">`</script>\n");
    }



    //last file

     if(lasttext == NULL)
    {
        system("cls");
        gotoxy(40,12);
        printf("File Error !");
        getch();
        exit(0);
    }else
    {
        fflush(stdin);
        while(!feof(lasttext))
    {

      lastline=fgetc(lasttext);

        fputc(lastline,towrite);

    }

    }

        fclose(existingFILE);
        fclose(aboutTEXT);
        fclose(lasttext);
        fclose(towrite);



}

//this will append the user data....
void appendInHTML(struct node *ptr,int index,FILE *pk)
{
    //FILE *appendData;

   // appendData = fopen("./MyResume/user.html","a");



    while(ptr != NULL)
    {
        if(ptr->indexNumber == index)
        {

               if(ptr->userInformation == "0")
               {
                    fprintf(pk,"Not Available");

               }else
               {
                   fprintf(pk,"%s",ptr->userInformation);
               }
        }
          ptr = ptr->next;
        }



    }


//this function will check user image

int checkUserImageForResume(struct node *ptr)
{

    while(ptr != NULL)
    {
        if(ptr->indexNumber == 11)
        {
            if(ptr->userInformation == "0")
            {
                return 0;

            }else
            {

                return 1;
            }

        }

        ptr = ptr->next;


    }



}



