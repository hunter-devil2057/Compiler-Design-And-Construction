// write a C program to test a given identifier is valid or not
//logic
//1. Read the input string.
//2. Check the start character of the string is numerical or any special character except '_'
//then print it is not a valid identifier.
//3.Otherwise: print it is valid identifier if remaining character of string does't contain any special character except '_'.

//Assignment: WRITE A C PROGRAM TO SIMULATE LEXICAL ANALYZER FOR VALIDATING OPERATORS.

#include<stdio.h>
//#include<conio.h>
#include<ctype.h>

void main()
{
 char identifier[20];
 int flag, i = 1;
 //clrscr();
 printf("Enter an identifier :");
 gets(identifier);
 if(isalpha(identifier[0]))
   flag = 1;
 else
   printf("It is not valid identifier");

 while(identifier[i] != '\0')
    {
      if(!isdigit(identifier[i])&&!isalpha(identifier[i]))
        {
          flag = 0;
          break;
        }
      i++;
    }
  if(flag == 1)
    printf("It is a valid identifier");
  //getch();
}
