#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void main()
{
	FILE *ptr;
	char arr[100];
	ptr =fopen("/home/rajagiri/Desktop/abhay/text.txt","w+");
	fprintf(ptr,"a=1-b+2;\nx=y+z;\np=t/u;");
	fclose(ptr);

	ptr =fopen("/home/student/Desktop/abhay/text.txt","r");
    int j=0;
    do
    {
    	arr[j]=fgetc(ptr);
    	j++;
    }
    while(arr[j-1]!=EOF);
    
    
	//fscanf(ptr,"%s",arr);
	fclose(ptr);
	printf("The expression is :\n%s",arr);
	printf("\n");
	printf("Lexeme \tToken\t\tLineno\n");
	int count=1;
	for(int i=0;arr[i]!=EOF;i++)
	{
		if (arr[i]=='+' ||arr[i]=='-' ||arr[i]=='*' ||arr[i]=='/' ||arr[i]=='%'||arr[i]=='=')
		{
			printf("%c \tOperator\t %d\n",arr[i],count);
		}
		else if(isalpha(arr[i]))
		{
			printf("%c \tIdentifier\t %d\n",arr[i],count);
		}
		else if(isdigit(arr[i]))
		{
			printf("%c \tNumeric\t\t %d\n",arr[i],count);
		}
		else if(arr[i]=='\n')
		{
			count++;
		}
		else
		{
			printf("%c \tPunctuation\t %d\n",arr[i],count);
		}
	}
}
