/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: main.c
 *	Objetivo: Acordar e levantar os principais sistema do kernel.
*/
#include <io.h>

uint32_t main() 
{
	clear();
	kPuts("AguilaOS", 5);
	return 0;
}
