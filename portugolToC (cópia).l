/**********	Definições *********/
numero			[0-9]
letra			[a-zA-Z]
alphanum  		[a-zA-Z0-9_]
int				{numero}+
real			({numero}+(\.{numero}+))
string			(\"([^"])*\")
logico			VERDADEIRO|FALSO
tipo			{int}|{real}|{string}|{logico}
identificador 	({letra}{alphanum}*)

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
tipoVariavel	inteiro|real|logico|caractere|vetor

/* Função e procedimento */
/*funcao, fimfuncao, procedimento, fimprocedimento, retorne, var*/

/** Cabeçalhos */
/* algoritmo, fimalgoritmo, var, inicio (fim do var) */

/********** FIM	Definições *********/
%%
{int}				{printf("inteiro\n");}
{real}				{printf("real\n");}
{string}			{printf("string\n");}
{logico}			{printf("logico\n");}
{opLogico}			{printf("operador logico\n");}
{opRelacional}		{printf("operador relacional\n");}
{recebe}			{printf("recebe\n");}
{tipoVariavel}		{printf("tipo de variavel");}
{identificador}		{printf("identificador: %s\n", yytext);}

/** Comandos de entrada
/*leia */

/* Comandos de saída */
/* escreva, escreval */

/* Condições */
/* se, senao, fimse, entao */

/* Comando de seleção múltipla */
/* escolha, caso, outrocaso, fimescolha /*

/* Estruturas de repetição */
/* para, faca, fimpara, enquanto, fimenquanto, repita, ate, interrompa, fimrepita */

/* Outras funções */
/* limpatela */

%%
int main(int argc, char **argv)
{
yylex();
}
