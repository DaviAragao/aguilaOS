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
uchar8_t px = 0;
uchar8_t py = 0;

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
	if(ch == '\n')
		tela += 80;
	else
	{
		*tela = ch;
		tela++;
		*tela = corFonte;
		tela++;
	}
}

void print_mem(void* start, void* end)
{
	uchar8_t* pstart = (uchar8_t*) start;
	uchar8_t* pend = (uchar8_t*) end;
	uint32_t count = 0;

	while(pstart != pend)
	{
		count++;
		if(count >= 7)
		{
			*tela++ = BRANCO;
			count = 0;
		}
		else
			*tela++ = *pstart++;
	}
}

void clear(void) 
{
	uint32_t i;
	for (i = 0; i < (80 * 25) * 2; i += 2) 
	{
		tela[i] = ' ';
		tela[i + 1] = PRETO;
	}
}

void gotoxy(uchar8_t x, uchar8_t y)
{
	px = x;
	py = y;
}
