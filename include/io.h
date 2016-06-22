/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: io.h
 *	Objetivo: Definir as funções para a manipulação da tela(temporário).
*/
#ifndef IO_H

	#define IO_H
	#include <unistd.h>

	void kPuts(char8_t* str, uint32_t attr);
	void putch(char8_t ch);
	void clear(void);

#endif
