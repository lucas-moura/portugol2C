# portugol2C
Compilador de Portugol para a linguagem C

# Executar o arquivo Flex
flex compilador.l
gcc <arquivo .c gerado> ./libs/funcoes.c -o teste.exe

# Compilar o arquivo teste.c com a biblioteca em ./libs
gcc test.c -o funcoes.c -o teste.exe (Windows)
gcc test.c -o funcoes.c -o teste.o (Linux)


