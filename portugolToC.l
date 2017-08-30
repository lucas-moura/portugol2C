/**********	Definições *********/
numero			[0-9]
letra			[a-zA-Z]
alphanum  		[a-zA-Z0-9_]
int				(-)?{numero}+
real			({numero}+(\.{numero}+))
string			(\"([^"])*\")
logico			VERDADEIRO|FALSO
tipo			{int}|{real}|{string}|{logico}
identificador 	({letra}{alphanum}*)
espacos         [ ]*
intervalo       {numero}+\.\.{numero}+
stringvar       ({espacos}{string}{espacos}[,]{espacos}{identificador})|({espacos}{identificador}{espacos}[,]{espacos}{string}{espacos})
declaracaoVars  {espacos}({identificador})({espacos},{espacos}{identificador})*{espacos}:{espacos}({tipoVariavel}|(vetor{espacos}\[{intervalo}{espacos}\]{espacos}de{espacos}{tipoVariavel}))


/* Operadores artiméticos */
soma			(\+)
subtracao		(\-)
multiplicacao	(\*)
divisao			(\/)
resto			mod|MOD|\%

/* Operadores de caracteres */
concatena		+

/* Operadores relacionais */
igual			=
menor			<
maior			>
menorIgual		<=
maiorIgual		>=
diferente		<>
opRelacional	{igual}|{menor}|{maior}|{menorIgual}|{maiorIgual}|{diferente}

/* Operadores lógicos */
opNao			nao
opE				e
opOu			ou
opXou			xou
opLogico		{opNao}|{opE}|{opOu}|{opXou}

/* Comando de atribuição */
recebe			(<\-)

/* Cabeçalhos */
hAlgoritmo		algoritmo
hFimAlgoritmo	fimalgoritmo
hVar			var
hInicio			inicio

/* Declaração de variáveis */
tipoVariavel	inteiro|real|logico|caractere

/* Função e procedimento */
/*funcao, fimfuncao, procedimento, fimprocedimento, retorne, var*/

/** Cabeçalhos */
/* algoritmo, fimalgoritmo, var, inicio (fim do var) */

/********** FIM	Definições *********/
%%

leia{espacos}\({espacos}{identificador}{espacos}\)     {printf("leia var\n");}

escreva{espacos}\({stringvar}|{identificador}\)        {printf("escreva\n");}
escreval{espacos}\({stringvar}|{identificador}\)       {printf("escreval\n");}

{declaracaoVars}                                       {printf("Declarou variaveis");}

{int}				{printf("inteiro\n");}
{real}				{printf("real\n");}
{string}			{printf("string\n");}
{logico}			{printf("logico\n");}
{opLogico}			{printf("operador logico\n");}
{opRelacional}		{printf("operador relacional\n");}
{recebe}			{printf("recebe\n");}
{tipoVariavel}		{printf("tipo de variavel");}
{identificador}		{printf("identificador: %s\n", yytext);}



%%
int main(int argc, char **argv)
{
yylex();
}
