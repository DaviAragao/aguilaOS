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
	{
		if (str[i] == '\n')
			newLine();
		else
			putch(str[i]);
	
	}
}

void kPuts(char8_t* str, uint32_t attr)
{
	corFonte = attr;
	printk(str);
}

void putch(char8_t ch)
{
	uint32_t position = ((COLUNS * py) + px) * 2;

	if(px >= COLUNS)
		newLine();
	else 
		px++;

	tela[position] = ch;
	tela[position + 1] = corFonte;
}

void newLine(void)
{
	px = 0;
	py++;
	if (py >= LINES)
		scroll();
}

void scroll(void)
{
	uint32_t i;
	for (i = 0; i < VIDEO_SIZE - 160; i++)
		tela[i] = tela[i + 160];
	clearLastLine();
	py--;
}

void clearLastLine(void)
{
	uint32_t i = VIDEO_SIZE - 160;
	for (i; i < VIDEO_SIZE; i += 2)
	{
		tela[i] = ' ';
		tela[i + 1] = PRETO;
	}
}

void clear(void) 
{
	uint32_t i;
	for (i = 0; i < VIDEO_SIZE; i += 2) 
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
