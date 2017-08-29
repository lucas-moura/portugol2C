%%
Se						 printf("if");
se						 {return(IF);};
(-|\+)*{digits}+         printf("found number: ’%s’\n", yytext);
{ltr}(_|{alphanum})*     printf("found identifer: ’%s’\n", yytext);
’.’                      printf("found character: {%s}\n", yytext);
.                        { /* absorb others */ }

/** Valores */
	numero		[0-9]
	letra		[a-zA-Z]
	alphanum   	[a-zA-Z0-9]
	int 		(numero)+
	real		(\numero+(\.\numero+))
	string		("([^"])*")
	logico		VERDADEIRO|FALSO

/** Cabeçalhos */
	// algoritmo, fimalgoritmo, var, inicio (fim do var)

/** Comandos de entrada */
	// leia

/* Comandos de saída */
	// escreva, escreval

/* Declaração de variáveis */
	// inteiro, real, logico, caractere, vetor

/* Função e procedimento */
	// funcao, fimfuncao, procedimento, fimprocedimento, retorne, var

/* Condições */
	// se, senao, fimse, entao

/* Comando de seleção múltipla */
	// escolha, caso, outrocaso, fimescolha

/* Operadores aritméticos */
	// +, - (unários +3, -3)
	// +, -, *, / (op aritmeticos tradicionais)
	// MOD ou % (resto da divisão inteira)

/* Operadores de Caracteres */
	// + (concatenação)

/* Operadores relacionais */
	// =, <, >, <=, >=, <>

/* Operadores lógicos */
	// nao, ou, e, xou

/* Comando de atribuição */
	// <-

/* Estruturas de repetição */
	// para, faca, fimpara, enquanto, fimenquanto, repita, ate, interrompa, fimrepita

/* Funções matemáticas */


/* Outras funções */
  // rand, limpatela...
  // aleatorio on (opcional o on), aleatorio off
  // timer on, timer <tempo-de-atraso>, timer off
  // pausa
  // debug <expressao-logica>
  // eco on, eco off
  // cronometro on, cronometro off
  // limpatela


%%
int main(int argc, char **argv)
{
yylex();
}
