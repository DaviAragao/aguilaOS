/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: archMain.c
 *	Objetivo: Iniciar os serviços dependentes da arquitetura e chamar a função principal do kernel.
*/
#include <kernel.h>
#include <x86/gdt.h>

void archMain()
{
	setup_gdt();
	test_gdt();
	kernelMain();
}

void test_gdt()
{
	
}
