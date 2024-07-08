// to identify valid identifiers and keywords in C
#include<stdio.h>
#include<string.h>

char keyword[32][10]= {"auto","double","int","struct","break","else","long", "switch","case", "enum", "register", "typedef","char", "extern", "return", "union", "const", 				"float", "short",  "unsigned","continue","for","signed","void","default", "goto", "sizeof", "volatile", "do","if","static","while"} ;

enum states { q0, qf, qd};
enum states delta(enum states, char);
int iskeyword(char []);

int main()
{
	enum states curr_state = q0;
	char string[20], ch;
	int i=0;
	
	printf("Enter a string: ");
	gets(string);

	ch = string[i];
	if(iskeyword(string))
	   printf("The string %s is keyword.",string);
	else 
	{	
		while(ch!='\0')
		{
			curr_state = delta(curr_state,ch);
			ch = string[++i];
		}
		if(curr_state==qf)
	 		 printf("The string %s is valid identifier.",string);
		else 
	 		 printf("The string %s is neither keyword nor valid identifier.",string);	
	 }	 
	return 0;
} //end of the main

//transition function
enum states delta(enum states s, char ch)
{
	enum states curr_state;
	switch(s)
	{
		case q0:
			if(ch>='A' && ch<='Z'||ch>='a'&&ch<='z'||ch=='_')
			   curr_state = qf;
			else
			   curr_state = qd;
			break;
		case qf:
			if(ch>='A' && ch<='Z'||ch>='a'&&ch<='z'||ch=='_'||ch>='0'&&ch<='9')
			   curr_state = qf;
			else
			   curr_state = qd;
			break;
		case qd:
			curr_state = qd;
	}
			
		return curr_state;
}

int iskeyword(char str[])
{
	for(int i=0;i<32;i++)
	{
		if(strcmp(str,keyword[i])==0)
		   return 1;
	}
	return 0;
	
}
