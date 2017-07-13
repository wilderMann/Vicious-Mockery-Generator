#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CHECK printf("Line: %d\n", __LINE__);
#define ERLOG fprintf(stderr,"Error in Line %d \n",__LINE__);

/*
IT IS NECESSARY THAT THERE IS A FILE NAMED Insults.txt IN THE SAME FOLDER AS THE .exe FILE!
*/
void insult(long rand, FILE *insults);

int main()
{
    char eingabe = 0;
    FILE *insults = 0;
    if(insults = fopen("Insults.txt","r"))      //opening Insults.txt
    {

    }
    else
    {
        fprintf(stderr,"Could not open Insult.txt!\nPlease make sure that Insult.txt is in the same folder with Vicious Mockery Generator!\n");
        return 0;
    }
    char zeichen[2];
    long anzahl = 0;
    long stop = 1;
    do                                          //first run through Insult.txt, so it knows how long the text is.
    {
        int i = 0;
        int durchlauf = 0;
        char *line = malloc(2*sizeof(char));
        char *newline;
        stop = fgets(zeichen,2,insults);
        i = (zeichen[0] == '\n') ? 0 : 1;
        strcpy(line,zeichen);
        do
        {


            stop = fgets(zeichen,2,insults);
            i = (zeichen[0] == '\n') ? 0 : 1;

            newline = realloc(line, (durchlauf*2+3)*sizeof(char));

            line = newline;

            strncat(line,zeichen,1);

            durchlauf++;
        }
        while(i==1);
        anzahl++;
    }
    while(stop);
    printf("%ld Insults found.\n",anzahl);       //Tells you how many insults are defined
    srand(time(NULL));                          //seeds the pseudo random number generator with the actual time
    do
    {
        fseek(insults,SEEK_SET,0);
        long random = 0;
        printf("\nPress Enter to insult!\nor press q to quit.\n");
        scanf("%c",&eingabe);
        (eingabe == '\n') ? :getc(stdin);
        if(eingabe == '\n')
        {

            random = rand()%anzahl;            //makes a random number between 0 and "anzahl"
            insult(random,insults);             //Searches for the insult
        }
        else
        {
            if(eingabe == 'q')
            {
                break;                          //quitting the program
            }
            printf("I said \"ENTER\"...\n");
        }
    }
    while(1);

    fclose(insults);                            //close the stream
    return 0;
}

void insult(long rand, FILE *insults)           //pretty the same code as above, terminates when "rand" is found.
{
    char zeichen[2];
    long anzahl = 0;
    long stop = 1;
    do
    {
        int i = 0;
        int durchlauf = 0;
        char *line = malloc(2*sizeof(char));
        char *newline;
        stop = fgets(zeichen,2,insults);
        i = (zeichen[0] == '\n') ? 0 : 1;
        strcpy(line,zeichen);
        do
        {


            stop = fgets(zeichen,2,insults);
            i = (zeichen[0] == '\n') ? 0 : 1;

            newline = realloc(line, (durchlauf*2+3)*sizeof(char));

            line = newline;

            strncat(line,zeichen,1);

            durchlauf++;
        }
        while(i==1 && stop);
        anzahl++;
        if(anzahl == rand)
        {
            stop = 0;
            printf("%s",line);
        }
    }
    while(stop);

}
