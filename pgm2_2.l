%{
	#include<stdio.h>
	int vc=0;
	int cc=0;
%}
%%
[aeiouAEIOU] {vc++; printf("%s is a VOWEL\n",yytext);}
[a-zA-Z] {cc++; printf("%s is a CONSONANT\n",yytext);}
[ \t\n];

%%

int main()
{
	printf("Enter string :");
	yylex();
	printf("The number of vowels :%d\n",vc);
	printf("The number of consonants:%d\n",cc);
	return 0;
	
}

int yywrap()
{
	return 1;
}
