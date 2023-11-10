#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i=0,state=1;
	char input[20];
	char c;
	printf(" Enter the string :");
	scanf("%s",input);
	
	while(input[i]!='\0')
	{
		
		switch(state)
		{	
			case 0:
			{
				printf(" Invalid String !!!\n");
				exit(0);
			}
			
			case 1:
			{
				c=input[i++];
				if(c=='a' && input[i]=='\0' )
				{
					state=5;
				}
				else if(c=='a')
				{
					state=2;
				}
				else
				{
					state=0;
				}
				break;
			}
			
			case 2:
			{
				c=input[i++];
				if(c=='a')
				{
					state=3;
				}
				else
				{
					state=4;
				}
				break;
			}
			
			case 3:
			{
				c=input[i++];
				if(c=='a')
				{
					state=3;
				}
				else if(c=='b' && input[i]=='\0')
				{
					state=6;
				}
				else
				{
					state=4;
				}
				break;
			}
			
			case 4:
			{
				c=input[i++];
				if(c=='a')
				{
					state=0;
				}
				else if(c=='b' && input[i]=='\0')
				{
					state=6;
				}
				else
				{
					state=4;
				}
				break;
			}			
		}
	}
	
	if(state==5)
	{
		printf("\n The string is recognised as a");
	}
	if(state==6)
	{
		printf("\n The string is recognised as a*b+");
	}
}						
