#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ENTER 13

int main()
{
    char ch;

    printf("Enter any key to get its ASCII code \n");
    do
    {
        ch = getch();

        if(ch == -32)
        {
            ch = getch();
            printf("Extended ASCII is --> %d \n", ch);
        }
        else{printf("ASCII of %c is --> %d \n", ch, ch);}

    }while(ch != ENTER);

    return 0;
}
