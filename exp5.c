#include<stdio.h>

void main()
{
	int is,states,fstates;
	printf(" Enter the number of input symbols :");
	scanf("%d",&is);
	
	char sym[is];
	for(int i=0;i<is;i++)
	{
		printf(" Enter the %d symbol :",i+1);
		scanf("%s",&sym[i]);
	}
	
	printf(" Enter the number of states :");
	scanf("%d",&states);
	
	printf(" Enter the number of final states :");
	scanf("%d",&fstates);
	
	char input[100];
	printf(" Enter the input string :");
	scanf("%s",input);
	
	char trans[states][is];
	printf(" Enter the transition table :\n");
	for(int i=0;i<states;i++)
	{
		for(int j=0;j<is;j++)
		{
			printf(" State %d symbol %c ->",i,sym[j]);
			scanf("%s",&trans[i][j]);
		}
	}
	char ch=input[0];
	int ip=0,state=0,ip_index=0;
	do
	{
	        for(int i=0;i<states;i++)
        	{
        	    if(ch==sym[i])
	            {
                	ip_index=i;
	            }
        	}
        	state=trans[state][ip_index];
	        ip++;
        	printf("Character:%c\n",ch);
	        printf("Current state:%d\n",state);
        	ch=input[ip];
        }while(ch!='\0');
}

