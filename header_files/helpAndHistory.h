void main(void);
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
