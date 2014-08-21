#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char str[])
{
    int i=0;
    char ch=str[i];
    int k=0;
    printf("str = [%s], len = %d\n",str, (int)strlen(str));

    while(str[i])
    {
        printf("\n entered while %d:\n",i);
        if(ch == str[i])
        {
            k++; // repeat counter
        }
        else
        {
            printf("%c%d",str[i-1],k);
            k=1;
            ch=str[i];
        }
        i++;
    }          
    printf("%c%d",str[i-1],k);
}

int main()
{
    char str[100];
    printf("Enter the string: \n");
    fgets(str, 100, stdin);
    compress(str);
    return 0;
 }
