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

	inline void outb(uint16_t port, uchar8_t val);
	inline uchar8_t inb(uint16_t port);
	inline void cli(void)
	inline void sti(void)

#endif
