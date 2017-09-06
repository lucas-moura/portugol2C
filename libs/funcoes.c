#include "funcoes.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct variavel variaveis[20];
int qtdVariaveis = 0;

char* declararString(int tamanho)
{
    char *stringRetorno = (char*)malloc((tamanho+1) * sizeof(char));
    return stringRetorno;
}

int getPrimeiroIndiceChar(char letra, char *texto)
{
    int i = 0;
    for(i=0; i < strlen(texto); i++)
    {
        if(texto[i] == letra)
            return i;
    }
    return -1;
}

char* getConteudoEntreParenteses(char *texto)
{
    int i = getPrimeiroIndiceChar(ABRE_PARENTESES, texto);
    int indiceFinal = -1, estaEntreAspas = -1, cont = 0;
    char *stringRetorno = declararString(strlen(texto));
    for(i=i+1; i < strlen(texto); i++)
    {
        if(texto[i] == ASPAS_DUPLAS)
            estaEntreAspas *= -1;

        if(estaEntreAspas == 1) //  Está entre aspas
        {
            stringRetorno[cont++] = texto[i];
        }
        else //  Não está entre aspas
        {
            if(texto[i] == FECHA_PARENTESES)
                indiceFinal = i;
            else
                stringRetorno[cont++] = texto[i];
        }
    }
    stringRetorno[cont] = FIM_STRING;
    return stringRetorno;
}

char * getNomeVariavel(char *texto, int indiceInicial)
{
    char *nomeVar = declararString(100);
    int i = 0, cont = 0;
    for(i=indiceInicial; i < strlen(texto) && texto[i] != VIRGULA; i++)
    {
        if(texto[i] != ESPACO) // Ignora espaço e vírgula
            nomeVar[cont++] = texto[i];
    }
    nomeVar[cont] = FIM_STRING;
    return nomeVar;
}

char* removerEspacosForaDaString(char *conteudo)
{
    char *stringRetorno = declararString(strlen(conteudo));
    int estaEntreAspas = -1, i = 0, cont = 0;
    for(i=0; i < strlen(conteudo); i++)
    {
        if(conteudo[i] == '"')
            estaEntreAspas *= -1;

        // Não está entre aspas
        if(estaEntreAspas == -1 && conteudo[i] != ESPACO)
            stringRetorno[cont++] = conteudo[i];
        else if(estaEntreAspas == 1)
            stringRetorno[cont++] = conteudo[i];
    }
    stringRetorno[cont] = FIM_STRING;
    return stringRetorno;
}

char getOperadorVariavel(char *nomeVariavel)
{
    return 's';
}

void concatVariavelEncontrada(char *textoDentro, char *conteudo, char *nomesVariaveis, int indiceTxtDentro, int *cont)
{
    char *nomeVar = getNomeVariavel(textoDentro, indiceTxtDentro+1);
    char operador = getOperadorVariavel(nomeVar);
    conteudo[(*cont)++] = '%';
    conteudo[(*cont)++] = operador;
    sprintf(nomesVariaveis, "%s, %s", nomesVariaveis, nomeVar);
}


void escreva(char *texto)
{
    int i = 0, indiceFinal = -1, cont = 0, estaEntreAspas = -1; // não está entre aspas
    char *textoDentro = getConteudoEntreParenteses(texto);
    textoDentro = removerEspacosForaDaString(textoDentro);
    char conteudo[700];
    char nomesVariaveis[700];
    conteudo[cont++] = ASPAS_DUPLAS;
    printf("Texto dentro[%d]: %s\n", strlen(textoDentro), textoDentro);
    for(i=0; i < strlen(textoDentro); i++)
    {
        if(textoDentro[i] == ASPAS_DUPLAS)
            estaEntreAspas *= -1; // Inverte

        // Está entre aspas
        if(estaEntreAspas == 1 && textoDentro[i] != ASPAS_DUPLAS)
        {
            conteudo[cont++] = textoDentro[i];
        }
        else // Não Está entre aspas
        {
            if(textoDentro[i] == ',' && textoDentro[i+1] != ASPAS_DUPLAS)
                concatVariavelEncontrada(textoDentro, conteudo, nomesVariaveis, i, &cont);
        }

    }
    conteudo[cont++] = ASPAS_DUPLAS;
    conteudo[cont] = FIM_STRING;
    strcat(conteudo, nomesVariaveis);
    printf("Conteudo:\n %s\n", conteudo);
}

char* getStringAteCharLimitador(char *original, char charLimitador, int *indice)
{
    original = removerEspacosForaDaString(original);
    char *stringRetorno = declararString(strlen(original));
    int cont = 0;
    for(*indice=*indice; *indice < strlen(original) && original[*(indice)] != charLimitador; (*indice)++)
        stringRetorno[cont++] = original[*indice];
    stringRetorno[cont] = FIM_STRING;
    printf("oi");
    //printf("%s", stringRetorno);
    return stringRetorno;
}

void declararVariavel(char *linha)
{
    int i = 0, somenteNomesVars = 1;
    linha = removerEspacosForaDaString(linha);
    for(i=0; i < strlen(linha); i++)
    {
        if(linha[i] == VIRGULA)
        {
            qtdVariaveis++;
        }
        else if(linha[i] == DOIS_PONTOS)
        {
            somenteNomesVars = 0;
        }
        else
        {
            if(somenteNomesVars == 1)
            {
                // nomes das variáveis

            }
            else
            {
                // tipo da variável
            }
        }
    }
    //adicionarVariavel(textoDentro);
}
