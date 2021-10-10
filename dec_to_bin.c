#include <stdio.h>                 //header file

char *dec_bin(unsigned int n, int s);                 //declaring function dec_bin()

int main()
{
    unsigned int n;           //declaring unsigned integer
    int s;
    printf("Number to be converted: ");
    scanf("%u",&n);
    printf("No of bits: ");
    scanf("%d",&s);
    char* binary=dec_bin(n,s);              //calling function dec_bin()
    printf("Binary string: ");
    for(int i=0;i<s;i++)                   //printing binary form
    {
        printf("%c",binary[i]);
    }
    
}
char *dec_bin(unsigned int n, int s)             //defining function dec_bin()
{
    static char arr[1234];                       //string array is declared
    for(int i=s-1; i>=0;i--)                     //loop to calculate binary form
    {
        if(n%2 == 0)
        {
        arr[i]='0';
        n/=2;
        }
        else
        {
            arr[i]='1';
            n/=2;
        }
    }
   
    return arr;              //returns arr 

}
