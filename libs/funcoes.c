#include "funcoes.h"
#include <string.h>
#include <stdio.h>

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


void escreva(char *texto)
{
    printf("teta %s", texto);

    /*int i = getFirstIndexChar('(', texto);
    int estaEntreAspas = 0;

    for(i=0; i < strlen(texto); i++)
    {
        if(texto[i] == '"')
        {

        }
    }*/

}
