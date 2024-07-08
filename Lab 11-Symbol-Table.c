// Write a C program to implement a symbol table.
#include<stdio.h>
//#include<conio.h>

#include<malloc.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

void main()
{
  int i=0, j=0, x=0, n, flag=0;
  void *p, *add[15];
  char ch, srch, b[15], d[15], c;
  printf("Enter expression terminate by $ :-");
  while((c = getchar())!='$')
   {
     b[i];
     i++;
   }
  n = i-1;
  printf("Given expression is :");
  i = 0;
  while(i <= n)
     {
       printf("%c",b[i]);
       i++;
     }
  printf("Symbol table :-\n");
  printf("Symbol\t addr\t type\n");
  while(j <= n)
     {
       c = b[j];
       if(isalpha(toascii(c)))
          {
             if(j == n)
               {
                 p = malloc(c);
                 add[x] = p;
                 d[x] = c;
                 printf("%c\t %p\t identifier\n",c,p);
               }
             else
               {
                 ch = b[j+1];
                 if(ch =='+'|| ch=='-'|| ch =='*' || ch == '=')
                   {
                    p = malloc(c);
                    add[x]=p;
                    d[x]= c;
                    printf("%c\t %p\t identifier \n",c,p);
                    x++;
                   }
               }
          }
       j++;
     }
   printf("The symbol is to be searched \n");
   srch = getch();
   for(i=0; i<=x; i++)
      {
        if(srch ==d[i])
          {
            printf("Symbol table :-\n");
            printf("%c %s %p\n",srch, "@address", add[i]);
            flag = 1;
          }
      }
    if(flag == 0)
     printf("Symbol table not found \n");
   getch();
}
//}
