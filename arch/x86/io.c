/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: io.c
 *	Objetivo: Processador comunicar-se com o mundo externo.
*/
#include <x86/io.h>

inline void outb(uint16_t port, uchar8_t val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

inline uchar8_t inb(uint16_t port)
{
	uchar8_t value;
	asm volatile("inb %1, %0" : "=a" (value) : "dN" (port));
	return(value);
}

inline void sti(void)
{
	asm volatile("sti");
}

inline void cli(void)
{
	asm volatile("cli");
}
