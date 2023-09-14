#include<stdio.h>
#include<ctype.h>

void main()
{
	FILE *ptr;
	char arr[100];
	ptr =fopen("/home/student/Desktop/abhay/text.txt","w+");
	fprintf(ptr,"a=1-b+2;\nx=y+z;");
	fclose(ptr);

	ptr =fopen("/home/student/Desktop/abhay/text.txt","r");
	fscanf(ptr,"%s",arr);
	fclose(ptr);
	printf("The expression is :%s",arr);
	printf("\n");
	printf("Lexeme \tToken\t\tLineno\n");
	int count=1;
	for(int i=0;arr[i]!='\0';i++)
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


