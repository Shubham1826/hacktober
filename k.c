#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int n, c;
    bool z=1;
    c=0;
    system("cls");      // using "cls" for VScode
    FILE *fp;
    char value[8];
    fp=fopen(argv[1], "r");         // opens redable file
    if(argc != 2)           // check proper argument
    {
        printf("Argument Invalid\n");       // if no proper argument is given then exit the file
        exit(z);
    }
    if(fp == NULL)      // if no such file present then return print statement
        printf("Not able to open target file\n");
    else
        {
            int index=0;        //to get the index of diamond
            fseek(fp, 0L, SEEK_END);        // fseek to check from end of file
            int l=ftell(fp);        // stores the length of file
            while(z)
            {
                n=(rand()-(RAND_MAX/2))%l;      //in order to have a random number randing from -ve length to +ve length, max rand no. is divided by strinf length and subtracted with random generated no., to make sure only valid moves are possible and you don't cross the file boundaries.
                fseek(fp, index, SEEK_SET);
                fgets(value, 8, fp);
                if(strcmp(value,"diamond") == 0)
                {
                    printf("Diamond found at Index %d and it took %d moves for it\n", index, c);
                    fclose(fp);     //closing the file
                    exit(z);
                }
                if((index+n) < l-7 && (index+n) >= 0)       //checks whether the move is within file's limit or not
                {
                    index=index+n;
                    c++;
                }
                else
                    continue;
            }
        }
    return 0;
}
