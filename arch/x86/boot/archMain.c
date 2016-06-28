/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: archMain.c
 *	Objetivo: Iniciar os serviços dependentes da arquitetura e chamar a função principal do kernel.
*/
#include <kernel.h>

void archMain()
{
	kernelMain();
}
