#include "io.h"

//Define o endereco do buffer
#define BUFFER 0xb8000

void escrever(char* mensagem, int cor)
{
	char* mem = (BUFFER);
	while(*mensagem != 0)
	{
		*mem = *mensagem;
		mem++;
		mensagem++;
		*mem = (char*) cor;
		mem++;
	}
}

void limpar_tela(void) 
{
	char* mem = (char*)(BUFFER);
	while(*mem != 0)
	{
		*mem = 0;
		mem++;
	}
}
