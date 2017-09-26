#define ASPAS_DUPLAS '\"'
#define ASPAS_SIMPLES '\''
#define ESPACO ' '
#define VIRGULA ','
#define ESTRELA '*'
#define DOIS_PONTOS ':'
#define ABRE_PARENTESES '('
#define FECHA_PARENTESES ')'
#define FIM_STRING '\0'

struct variavel{
    char nome[60];
    char operador; // d, f, c
    char tipo[10]; // int, float, char
};

// Aloca um espaço na memória com o tamanho e retorna a string
char* declararString(int tamanho);

// Retorna o índice da primeira ocorrência do caracter informado
int getPrimeiroIndiceChar(char letra, char *texto);

// Retorna o conteúdo que está entre os parênteses
char* getConteudoEntreParenteses(char *texto);

// Partindo de um índice informado, retorna o nome da primeira variável encontrada
char* getNomeVariavel(char *texto, int indiceInicial);

// Remove os espaços em branco que estão fora das aspas duplas
char* removerEspacosForaDaString(char *conteudo);

// Retorna a letra correspondente ao tipo da variável. Ex: 'c', 'd', 's'...
char getOperadorVariavel(char *nomeVariavel);

// Identifica a variável encontrada e o seu respectivo operador na string do printf. Não adiciona o nome
// da variável na string
void concatVariavelEncontrada(char *textoDentro, char *conteudo, char *nomesVariaveis, int indiceTxtDentro, int *cont);

// Função responsável por converter as funções 'escreva' ou 'escreval' do portugol
void escrevaFunc(char *texto, int temNovalinha);

// Função do escreva sem quebra de linha no final
void escreva(char *texto);

void leia(char *texto);
void caso(char *texto);
void escolha(char *escolha);
// Função do escreva com quebra de linha no final
void escreval(char *texto);

// Função do escreva com quebra de linha no final
char* getStringAteCharLimitador(char *original, char charLimitador, int *indice);

// Retorna o conteúdo que está entre os parênteses
char* getConteudoEntreParenteses(char *texto);

// Adiciona uma variável na minha lista de variáveis
void addVariavel(int indiceVarInicial, char tipoVar);

// Interpreta a linah de variáveis e adiciona na lista
void declararVariavel(char *linha);

// Imprime todas as variáveis já declaradas
void imprimirVariaveis();

//Função do condicional se
void se(char *texto, int temParenteses);

//Função do laço enquanto
void enquanto(char *texto, int temParenteses);
