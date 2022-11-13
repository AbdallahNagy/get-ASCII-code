#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define SIZE 60
#define LINE 10

#define EXTENDED -32
#define ENTER 13
#define ESC 27
#define END 79
#define HOME 71
#define RIGHT 77
#define LEFT 75
#define UP 72
#define DOWN 80
#define BACKSPACE 8
#define DELETE 83

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void gotoxy(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

void addEditorNumbers()
{
    for(int i=0; i<LINE; i++)
    {
        gotoxy(1, (i + 1) * 2);
        printf("%d", i+1);
    }
}

char* lineEditor(int size, int i, int linePos)
{
    int first = 5, current = 5, last = 5;
    char exit = 'n', ch;
    char* arrptr[LINE];
    char* pf[LINE];
    char* pc[LINE];
    char* pl[LINE];

    for(int i=0; i<LINE; i++)
        arrptr[i] = malloc(size * sizeof(char));

    for(int i=0; i<LINE; i++)
    {
        pf[i] = arrptr[0];
        pc[i] = arrptr[0];
        pl[i] = arrptr[0];
    }

    do
    {
        gotoxy(current, linePos);
        _flushall();
        ch = getch();

        switch(ch)
        {
        case EXTENDED:
            ch = getch();

            switch(ch)
            {
            case LEFT:
                if(current > first)
                {
                    pc[i]--;
                    current--;
                }
                break;

            case RIGHT:
                if(current < last)
                {
                    pc[i]++;
                    current++;
                }
                break;

            case HOME:
                current = first;
                pc[i] = pf[i];
                break;

            case END:
                current = last;
                pc[i] = pl[i];
                break;
            case DELETE:

                break;
            }
            break;
        case BACKSPACE:
            if(current > first)
            {

            }
            break;

        case ESC:
        case ENTER:
            pl[i] = '\0';
            exit = 'y';
            break;

        default:
            if(isprint(ch))
            {
                if(pc[i] == pl[i]){
                    if(pc[i] < pf[i] + size-1)
                    {
                        *pc[i] = ch;
                        printf("%c", *pc[i]);

                        pc[i]++;
                        pl[i]++;
                        current++;
                        last++;
                    }
                }
                else
                {
                    *pc[i] = ch;
                    printf("%c", *pc[i]);

                    pc[i]++;
                    current++;
                }
            }
        }
    }
    while(exit != 'y');

    return arrptr[i];
}

int main()
{
    char* line[LINE];
    addEditorNumbers();

    for(int i=0; i<LINE; i++)
    {
        line[i]= lineEditor(SIZE, i, (i + 1) * 2 );
    }

    system("cls");
    gotoxy(30, 30);

    for(int i=0; i<LINE; i++)
    {
        for(int j=0; j<SIZE; j++)
            printf("%c", line[i][j]);

        printf("\n");
    }
    for(int i=0; i<LINE; i++)
        free(line[i]);

    return 0;
}
