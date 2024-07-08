//  Implement a DFA for L = { set of all strings over {0,1} such that  string end with 01
#include<stdio.h>

enum states { q0, q1, qf};
enum states delta(enum states, char);

int main()
{
	char input[20];
	enum states curr_state = q0;
	int i =0;
	
	printf("Enter a binary string: ");
	gets(input);
	char ch = input[i];
	while( ch !='\0')
	{
	    curr_state = delta(curr_state,ch);
		ch = input[++i];
  	}
  	
	if(curr_state == qf)
	   printf("The string %s is accepted.",input);
	else 
	    printf("The string %s is not accepted.",input);	    
		
   return 0;			
}


enum states delta(enum states s, char ch)
{
       enum states curr_state;
	   switch(s)
		{
			case q0:
				if(ch=='0')
				   curr_state = q1;
				else
				   curr_state = q0;
				break;
			case q1:
				if(ch=='1')
				   curr_state = qf;
				else
				   curr_state = q1;
				break;
			case qf:
				if(ch=='0')
				   curr_state = q1;
				else
				   curr_state = q0;
				break;
		}	
	return curr_state;
}