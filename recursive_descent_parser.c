#include <stdio.h>
#include <string.h>

int E(), Edash(), T(), Tdash(), F();

const char *cursor;
char string[64];

int main()
{
	printf("Enter the string :");
	scanf("%s", string);
	//sscanf("i+(i+i)*i", "%s", string);
	cursor = string;  
	printf("\n");
	printf("Input		Action");
	printf("\n");  

	if (E() && *cursor == '\0')
	{  
            printf("String is successfully parsed");  
            return 0;  
        }
        else
        {
            printf("Error in parsing String");  
            return 1;  
        }  
}  
      
int E()  
{  
	printf("%-16s E -> T E'\n", cursor);  
	if (T())
	{  
            if (Edash())
            {  
                return 1;
            }  
            else
            {  
                return 0;
            }  
        } 
        else
        {  
            return 0;
        }  
}

int Edash()  
{  
	if (*cursor == '+')
	{  
		printf("%-16s E' -> + T E'\n", cursor);  
		cursor++;  
		if (T())
		{  
			if (Edash())
			{  
				return 1;
			}
			else
			{  
				return 0;
			}
		}  
		else
		{ 
			return 0;  
		}
	
	}
	else
	{  
            printf("%-16s E' -> $\n", cursor);  
            return 1;  
        }  
}  
      
int T()  
{
	printf("%-16s T -> F T'\n", cursor);  
	if (F())
	{  
		if (Tdash())
		{  
			return 1;
		}
		else
		{ 
			return 0;
		}  
	}
	else
	{
		return 0;
	}
}  
      
int Tdash()  
{  
	if (*cursor == '*')
	{  
		printf("%-16s T' -> * F T'\n", cursor);
		cursor++;  
		if (F())
		{  
			if (Tdash())
			{  
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}  
        }
        else
        {  
            printf("%-16s T' -> $\n", cursor);  
            return 1;  
        }
}
      
int F()  
{
	if (*cursor == '(')
	{  
		printf("%-16s F -> ( E )\n", cursor);  
		cursor++;  
		if (E())
		{
			if (*cursor == ')')
            		{
            			cursor++;
            			return 1;  
                	}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else if (*cursor == 'i')
	{
		cursor++;
		printf("%-16s F ->i\n", cursor);
		return 1;
        }
        else
        {
		return 0;  
	}
}
