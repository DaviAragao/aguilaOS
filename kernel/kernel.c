/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: main.c
 *	Objetivo: Acordar e levantar os principais sistema do kernel.
*/
#include <x86/video.h>
#include <kernel.h>

void kernelMain() 
{
	//clear();
	kPuts("AguilaOS\n", CINZA_CLARO);
	while (1);
}
