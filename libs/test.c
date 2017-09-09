#include "funcoes.h"
#include <stdio.h>

int main()
{

    char *texto = "v1, v2, v3: real";
    declararVariavel(texto);
    char *texto2 = "n1, n2, n31234123_x: inteiro";
    declararVariavel(texto2);
    char *texto3 = "textao, msg, saida: caractere";
    declararVariavel(texto3);

    imprimirVariaveis();
    escreva("escreva(\"       Resultado da operacao: \", textao)");
    escreval("escreval(\"Teste : \", n1)");

    return 0;
}
