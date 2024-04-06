#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_INPUT_NUMBER 5


//This Function to get the power
int Pow(int base,int pow)
{
    int number=1;
    while(pow>0)
    {
     number=number*base;
     pow--;
    }
return number;
}

//This function to Draw the table
void Draw_table(int number_of_inputs)
{
    int counter=0,column=0;
    int table_number=Pow(2,number_of_inputs);
    int max_number=Pow(2,MAX_INPUT_NUMBER);
    int Digit=0;
    while(counter<max_number)
     {
         Digit|=(table_number&counter);
         if(Digit!=0)
         {
             printf("%3d  |",counter);
             column++;

             if(column%4==0)
             printf("\n");
         }
         Digit=0;

       counter++;
     }
}
int main()
{

//Number variable to count the number of the user in it
//Number of inputs to loop on the 5 tables
//Play to replay after finishing the game
//approval character to get the input character from the user
int Number,Number_Of_Inputs,Play=1;
char approval='/';

      while(Play==1)
      {

                  Number_Of_Inputs=0;
                  Number=0;
                  system("cls");
                  printf("Choose any integer number from 0 to 31 in your brain\n\n\n");
                  system("pause");

                  while(Number_Of_Inputs<MAX_INPUT_NUMBER)
                  {
                           system("cls");

                           Draw_table(Number_Of_Inputs);

                           printf("\n\nIs your number here?{y/n}\n\n");

                           do
                           {
                                 approval=getch();
                                 if((approval=='Y'||approval=='y'))
                                 {
                                          Number=Number+Pow(2,Number_Of_Inputs);
                                 }
                           }while(approval!='Y'&&approval!='y'&&approval!='n'&&approval!='N');


                           Number_Of_Inputs++;
                   }

            system("cls");

            printf("I think your Number is %d\n\n\n",Number);

            printf("challenge me again?{y/n}");

            do
            {
                  approval=getch();
                   if((approval=='Y'||approval=='y'))
                   {
                          Play=1;
                   }
                   else if(approval!='n'||approval!='N')
                   {
                       Play=0;
                   }
            }while(approval!='Y'&&approval!='y'&&approval!='n'&&approval!='N');


    }

    system("cls");
    printf("See ya loser ;)");
    sleep(3);

    return 0;
}
