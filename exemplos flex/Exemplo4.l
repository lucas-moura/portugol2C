%{
	#include <string.h>
	
	char* copiar(char*	texto){
		int final = sizeof(texto) - 3;
		char parte[final];
		memcpy(parte, &texto[3], final);
		return parte;
	}
	 
	 
%}

/* definição de digito */
digito	[0-9]

%%

se  			{printf("if "); printf(yytext);printf("\n\n");}
[0-9]+		{printf("Encontrado inteiro: %s\n",yytext);}
[^ \t\n]+	{printf("Encontrado não inteiro: %s\n",yytext);}
[ \t\n]		; /* são ignorados */
<<EOF>>		{printf("Fim de dados\n");return 0;} /* ctrl+D*/

%%

/* se definir esta funÃ§Ã£o nÃ£o necessita compilar com o parÃ¢metro -lfl */
int yywrap()
{
	return(1);
}


int main()
{
  printf("Insira dados:\n");
  yylex();
  return 1;
}
