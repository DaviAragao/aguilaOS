/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: test.h
 *	Objetivo: Definir as funções dos casos de teste.
*/
#ifndef TESTE_H
#define TESTE_H
	#include <x86/gdt.h>
	#include <x86/video.h>
	
	/*
	 * Testa todos os módulos.
	 * */
	void testMain(void);

	/*
	 * Imprime a região da memória onde está a GDT.
	 * */
	void testGDT(void* gdt, void* gdtr);
#endif
