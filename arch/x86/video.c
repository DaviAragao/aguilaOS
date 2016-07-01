/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: video.c
 *	Objetivo: Prover algumas funções para manipulação da memória de vídeo. Um pequeno driver de vídeo.
*/
#include <x86/video.h>
#include <string.h>

uint32_t corFonte = BRANCO;
char8_t* tela = (char8_t*)(BUFFER);

void printk(char8_t* str)
{
	uint32_t i = 0;
	for (i = 0; i < kStrlen(str); i++)
		putch(str[i]);
}

void kPuts(char8_t* str, uint32_t attr)
{
	uint32_t i = 0;
	corFonte = attr;
	for (i = 0; i < kStrlen(str); i++)
		putch(str[i]);
}

void putch(char8_t ch)
{
	*tela = ch;
	tela++;
	*tela = corFonte;
	tela++;
}

void print_mem(char8_t* start, char8_t* end)
{
	uint16_t count = 0;
	while(start != end)
	{
		*tela = *start++;
		*tela++;
		if (count == 7) 
		{
			*tela = corFonte;
			tela++;
			count = 0;
		}
		count++;
	}
}

void clear(void) 
{
	char8_t* mem = (char8_t*)(BUFFER);
	while(*mem != 0)
	{
		*mem = 0;
		mem++;
	}
}
