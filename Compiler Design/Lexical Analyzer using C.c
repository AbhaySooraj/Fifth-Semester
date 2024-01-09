#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX_TOKEN_LENGTH 100

int isKeyword(char *str)
{
	char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default","do", "double", "else", "enum", "extern", "float", "for","goto", "if", "int", "long", "register", "return", "short","signed", "sizeof", "static", "struct","switch", "typedef","union", "unsigned", "void", "volatile", "while"};
	int numkeywords=sizeof(keywords)/sizeof(keywords[0]);
	for(int i=0;i<numkeywords;i++)
	{
		if(strcmp(str,keywords[i])==0)
		{
			return 1;
		}
	}
	return 0;
}

int isPunc(char ch)
{
	char punc[]={"\",;:?!|&~`'"};
	for(int i=0;i<strlen(punc);i++)
	{
		if(ch==punc[i])
		{
			return 1;
		}
	}
	return 0;
}

int isOperator(char ch)
{
	char op[] = "+-*/=<>^";
	for(int i=0;i<strlen(op);i++)
	{
		if(ch==op[i])
		{
			return 1;
		}
	}
	return 0;
}

int isIdentifier(char *str)
{
	if(isalpha(str[0])||str[0]=='_')
	{
		for(int i=1;i<strlen(str);i++)
		{
			if(!isalnum(str[i]))
			{
				return 0;
			}
		}		
		return 1;
	}
	else
	{
		return 0;
	}
}

int isNumber(char *str)
{
	for(int i=0;i<strlen(str);i++)
	{
		if(!isdigit(str[i]))
		{
			return 0;
		}
	}
	return 1;
}

int isOpeningBracket(char ch)
{
	char ob[] = {"({["};
	for(int i=0;i<strlen(ob);i++)
	{
		if(ch==ob[i])
		{
			return 1;
		}
	}
	return 0;
}

int isClosingBracket(char ch)
{
	char cb[] = {")}]"};
	for(int i=0;i<strlen(cb);i++)
	{
		if(ch==cb[i])
		{
			return 1;
		}
	}
	return 0;
}

void toktab(char fn[])
{
	FILE *fp=fopen(fn,"r");
	if(fp==NULL)
	{
		printf("\nError opening file\n");
	}
	else
	{
		int ln=1;
		printf("\n Token\t\tType\t\tLine No.\n");
		char line[MAX_TOKEN_LENGTH];
		
		while(fgets(line,sizeof(line),fp))
		{
			char *token=strtok(line," \t\n");
			while(token!=NULL)
			{
				if(isKeyword(token))
				{
					printf("%s\t\tKeyword\t\t\t%d\n",token,ln);
				}
				
				else if(isPunc(token[0]))
				{
					printf("%s\t\tPunctuation\t\t%d\n", token, ln);
				}
				
				else if(isOperator(token[0]))
				{
					printf("%s\t\tOperator\t\t\%d\n", token, ln);
				}
				
				else if(isIdentifier(token))
				{
					printf("%s\t\tIdentifier\t\t%d\n", token, ln);
				}
				
				else if(isNumber(token))
				{
					printf("%s\t\tNumber\t\t\t%d\n", token, ln);
				}
				
				else if(isOpeningBracket(token[0]))
				{
					printf("%s\t\tOpening Brackets\t%d\n", token, ln);
				}
				
				else if(isClosingBracket(token[0]))
				{
					printf("%s\t\tClosing Brackets\t%d\n", token, ln);
				}
				
				else
				{
					printf("%s\t\tInvalid\t\t\t%d\n", token, ln);
				}
								
				token=strtok(NULL," \t\n");
			}
			ln++;
		}			
	}
}



int main()
{
	char filename[20];
	printf("Enter the file name:");
	scanf("%s",filename);
	printf("file name :%s",filename);
	toktab(filename);
}
