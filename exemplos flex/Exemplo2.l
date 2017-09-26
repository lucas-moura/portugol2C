%{
	#include <stdio.h>
%}

digito	[0-9]
letra	[A-Za-z]
id		{letra}({letra}|{digito})*

%%

{digito}* {
	printf("Inteiro %s \n", yytext);
}

{id}	printf("Identificador %s \n", yytext);

.		printf("Caracter nao reconhecido %s \n", yytext);

"//"	printf("Final do código %s \n", yytext); return 0;


%%
int yywrap(void)
{
    return 0;
}

int main(){
	yylex();
	printf("Fim \n");
}