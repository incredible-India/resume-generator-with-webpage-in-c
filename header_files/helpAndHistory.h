void main(void);
void ShowUserHistory(void);
int showMenu();


void helpToUser()
{

    FILE *openFile;

    char datareading;

    openFile = fopen("./help/help.txt","r");

    if(!openFile)
    {
        system("cls");

        MenuContents("Sorry Help File Not Found !",40,12,4);

        getch();

        main();

    }else
    {
        system("cls");
        while(!feof(openFile))
    {

       datareading=fgetc(openFile);
        printf("%c",datareading);

    }
            fclose(openFile);
            getch();
            main();
    }

}

//show the user history
void ShowUserHistory()
{
    FILE *showdata;

    char datareading;

    showdata =  fopen("./UserHistory/user.txt","r");

    if(showdata == NULL)
    {

            system("cls");

         printf("Sorry File Not Found !");
         getche();
         main();
    }else
    {
         system("cls");

          while(!feof(showdata))
    {

       datareading=fgetc(showdata);
        printf("%c",datareading);

    }
            fclose(showdata);
            getch();
            main();
    }

}
