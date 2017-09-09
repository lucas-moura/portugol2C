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
    int i = 0;
    for(i=0; i < qtdVariaveis; i++)
    {
        if(strcmp(variaveis[i].nome, nomeVariavel) == 0)
        {
            return variaveis[i].operador;
        }
    }
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


void escrevaFunc(char *texto, int temNovalinha)
{
    int i = 0, indiceFinal = -1, cont = 0, estaEntreAspas = -1; // não está entre aspas
    char *textoDentro = getConteudoEntreParenteses(texto);
    textoDentro = removerEspacosForaDaString(textoDentro);
    char conteudo[200];
    char nomesVariaveis[700];
    nomesVariaveis[0] = FIM_STRING;
    conteudo[cont++] = ASPAS_DUPLAS;
    //printf("Texto dentro[%d]: %s\n", strlen(textoDentro), textoDentro);
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
    if(temNovalinha == 1)
    {
        conteudo[cont++] = '\\';
        conteudo[cont++] = 'n';
    }
    conteudo[cont++] = ASPAS_DUPLAS;
    conteudo[cont] = FIM_STRING;
    strcat(conteudo, nomesVariaveis);
    printf("printf(%s);\n", conteudo);
}

void escreva(char *texto)
{
    escrevaFunc(texto, 0);
}

void escreval(char *texto)
{
    escrevaFunc(texto, 1);
}

char* getStringAteCharLimitador(char *original, char charLimitador, int *indice)
{
    original = removerEspacosForaDaString(original);
    char *stringRetorno = declararString(strlen(original));
    int cont = 0;
    for(*indice=*indice; *indice < strlen(original) && original[*(indice)] != charLimitador; (*indice)++)
        stringRetorno[cont++] = original[*indice];
    stringRetorno[cont] = FIM_STRING;
    //printf("%s", stringRetorno);
    return stringRetorno;
}

void addVariavel(int indiceVarInicial, char tipoVar)
{
    int i = 0;
    for(i=indiceVarInicial; i < qtdVariaveis; i++)
    {
        if(tipoVar == 'i')
        {
            variaveis[i].operador = 'd';
            strcpy(variaveis[i].tipo, "int");
        }
        else if(tipoVar == 'r')
        {
            variaveis[i].operador = 'f';
            strcpy(variaveis[i].tipo, "float");
        }
        else if(tipoVar == 'c')
        {
            variaveis[i].operador = 'c';
            strcpy(variaveis[i].tipo, "char");
        }
        //printf("[%d] addVariavel %s -> %c\n", i, variaveis[i].nome, tipoVar);
    }
}

void declararVariavel(char *linha)
{
    int i = 0, somenteNomesVars = 1;
    linha = removerEspacosForaDaString(linha);
    int indiceNomeVar = 0;
    char tipoVar = ESTRELA; // Caracter que representa o estado inicial
    int indiceVarInicial = qtdVariaveis;
    //qtdVariaveis++;

    for(i=0; i < strlen(linha); i++)
    {
        if(linha[i] == VIRGULA)
        {
            variaveis[qtdVariaveis++].nome[indiceNomeVar] = FIM_STRING;
            indiceNomeVar = 0;
        }
        else if(linha[i] == DOIS_PONTOS)
        {
            somenteNomesVars = 0;
            qtdVariaveis++;
        }
        else
        {
            if(somenteNomesVars == 1) // Nomes das variáveis
                variaveis[qtdVariaveis].nome[indiceNomeVar++] = linha[i];
            else // Tipo da variável
                if(tipoVar == ESTRELA)
                    tipoVar = linha[i]; // só pegao primeiro char do tipo
        }
    }
    addVariavel(indiceVarInicial, tipoVar);

}

void imprimirVariaveis()
{
    int i = 0;
    for(i=0; i < qtdVariaveis; i++)
    {
        printf("%s %s;\n", variaveis[i].tipo, variaveis[i].nome, variaveis[i].operador);
    }
}
