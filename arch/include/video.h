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

	void kPuts(char8_t* str, uint32_t attr);
	void putch(char8_t ch);
	void clear(void);

#endif
