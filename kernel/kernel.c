/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: main.c
 *	Objetivo: Acordar e levantar os principais sistema do kernel.
*/
#include <io.h>
#include <kernel.h>

void kernelMain() 
{
	clear();
	kPuts("AguilaOS", 5);
	while (1);
}
