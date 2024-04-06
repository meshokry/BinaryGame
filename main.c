#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void MaximizeOutputWindow(void)
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
}
void start()
{
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
COORD NewSBSize = GetLargestConsoleWindowSize(hOut);
SetConsoleScreenBufferSize(hOut, NewSBSize);
//HWND hwnd = GetConsoleWindow();
MaximizeOutputWindow();

}
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int Pow(int base,int pow)
{
    int i,number=1;
    while(pow>0)
    {
     number=number*base;
     pow--;
    }
return number;
}
int main()
{
int table0[4][4] ={{1, 3, 5, 7},{9, 11, 13,15},{17, 19,21, 23},{25,27,29,31}};
int table1[4][4]={{2, 3, 6, 7},{10, 11, 14,15},{18, 19,22, 23},{26,27,30,31}};
int table2[4][4]={{4, 5, 6, 7},{12, 13, 14,15},{20, 21,22, 23},{28,29,30,31}};
int table3[4][4]={{8, 9, 10, 11},{12, 13, 14,15},{24, 25,26, 27},{28,29,30,31}};
int table4[4][4]={{16, 17, 18, 19},{20, 21, 22,23},{24, 25,26, 27},{28,29,30,31}};

int i,j,k=0,counter=0;
int number=0;
char approval;
start();
gotoxy(60,18);
printf("Choose any integer number from 0 to 31 in your brain");
gotoxy(70,26);
system("pause");
up1:
system("cls");
    k=0;
    approval='/';
    for(int i = 0; i<4; i++)
    {
        gotoxy(65,i+18);
         printf("%c",186);
         for(int j = 0; j < 4; j++)
         {
              //gotoxy(65,k+18);
              if(counter==0)
              printf("%5d", table0[i][j]);
              else if(counter==1)
              printf("%5d", table1[i][j]);
              else if(counter==2)
              printf("%5d", table2[i][j]);
              else if(counter==3)
              printf("%5d", table3[i][j]);
              else if(counter==4)
                printf("%5d", table4[i][j]);
              printf("   |");
         }

k+=4;
    }

while(approval!='y'&&approval!='Y'&&approval!='n'&&approval!='N'&&counter<5)
{
printf("\e[?25l");
gotoxy(71,14);
printf("Is your number here?{y/n}");
approval=getch();
}
if((approval=='Y'||approval=='y'))
{
 number=number+Pow(2,counter);
}
if(counter<5)
{
    counter++;
    goto up1;
}
else
{
    system("cls");
    gotoxy(71,14);
    system("pause");
    system("cls");
    gotoxy(71,14);
    printf("I think your number is %d",number);
    gotoxy(73,18);
    printf("press any key to exit");
    getch();
}
    return 0;
}
