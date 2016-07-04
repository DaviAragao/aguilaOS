/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: video.h
 *	Objetivo: Definir padrões para o driver de vídeo.
*/
#ifndef VIDEO_H
#define VIDEO_H

	#include <unistd.h>
	#define BUFFER 0xB8000
	#define COLUNS 80
	#define LINES 25
	#define VIDEO_SIZE COLUNS * LINES * 2

        /*Cores possíveis*/                                                                                                                       
        #define PRETO		0x00
        #define AZUL		0x01
        #define VERDE		0x02
        #define CIANO		0x03
        #define VERMELHO	0x04
        #define MAGENTA		0x05
        #define MARROM		0x06
        #define CINZA_CLARO	0x07
        #define CINZA_ESCURO	0x08
        #define AZUL_CLARO	0x09
        #define VERDE_CLARO	0x0A
        #define CIANO_CLARO	0x0B
        #define VERMELHO_CLARO	0x0C
        #define MAGENTA_CLARO	0x0D
        #define AMARELO		0x0E
        #define BRANCO		0x0F

	void kPuts(char8_t* str, uint32_t attr);
	void printk(char8_t* str);
	void putch(char8_t ch);
	void gotoxy(uchar8_t x, uchar8_t y);
	void scroll(void);
	void clearLastLine(void);
	void clear(void);
	void _clear(uint32_t i);
	void newLine(void);

#endif
