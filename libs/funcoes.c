#include "funcoes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int getFirstIndexChar(char letra, char *texto)
{
    int i = 0;
    for(int i=0; i < strlen(texto); i++)
    {
        if(texto[i] == letra)
            return i;
    }
    return -1;
}

// Ignora se estiver dentro da string
char* getConteudoEntreParenteses(char *texto)
{
    int i = getFirstIndexChar('(', texto);
    int indiceFinal = -1;
    int estaEntreAspas = -1;
    char *stringRetorno = (char*)malloc((strlen(texto)+1) * sizeof(char));
    int cont = 0;
    for(i=i+1; i < strlen(texto); i++)
    {
        printf("caracter: %c\n", texto[i]);
        if(texto[i] == '"')
        {
            estaEntreAspas *= -1;
        }

        //  Não Está entre aspas
        if(estaEntreAspas == 1)
        {
            stringRetorno[cont++] = texto[i];
            printf("stringRetorno[%d] = %c\n", (cont-1), stringRetorno[cont-1]);
        }
        else
        {
            if(texto[i] == ')')
                indiceFinal = i;
            else
            {
                stringRetorno[cont++] = texto[i];
                printf("stringRetorno[%d] = %c\n", (cont-1), stringRetorno[cont-1]);
            }
        }
    }
    stringRetorno[cont] = '\0';
    return stringRetorno;
}


void escreva(char *texto)
{
    //printf("teta %s", texto);
    int i = getFirstIndexChar('(', texto);
    int indiceFinal = -1;
    printf("%d", i);
    int estaEntreAspas = -1; // não está entre aspas
    char *teste = getConteudoEntreParenteses(texto);
    printf("Final: %s\n", teste);
    //printf("%s\n", getConteudoEntreParenteses(texto));
    /*for(i=0; i < strlen(texto); i++)
    {
        printf("caracter: %c\n", texto[i]);
        if(texto[i] == '"')
        {
            estaEntreAspas *= -1;
        }

        // Está entre aspas
        if(estaEntreAspas == 1)
        {

        }
        else // Não Está entre aspas
        {
            if(texto[i] == ')')
                indiceFinal = i;
        }

        printf("%d\n", estaEntreAspas);
    }*/
}
