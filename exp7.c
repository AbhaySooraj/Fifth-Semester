#include<stdio.h>
#include<stdlib.h>
int fcount=0;
int notin(char x,char nterminals[],int n)
{
	int f=0;
	for(int i=0;i<n;i++)
	{
		if(x==nterminals[i])
		{
			f++;
		}
	}
	if(f==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}	

void first(char x,int count,int n,char nterminals[],char productions[][100])
{
	if(notin(productions[i][2],nterminals,n))
	{
		first[fcount]=productions[i][2];
	}
	else
	{
		first(productions[i][2],
void main()
{
	int n,count=0;
	printf(" Enter the number of rules :");
	scanf("%d",&n);
	
	printf(" Enter the productions :\n");
	char productions[n][100];
	for(int i=0;i<n;i++)
	{
			scanf("%s",productions[i]);
		
	}
	
	char nterminals[n];
	for(int i=0;i<n;i++)
	{
		if(notin(productions[i][0],nterminals,n))
		{
			nterminals[i]=productions[i][0];
			count++;
		}
	}
	
	printf("\n The Non Terminals are :\n");
	for(int i=0;i<count;i++)
	{
		printf("%c\n",nterminals[i]);
	}
	
	for(int i=count;i>0;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(nterminals[i]==production[j][0])
			{
				first(nterminals[i],count,n
					
}
