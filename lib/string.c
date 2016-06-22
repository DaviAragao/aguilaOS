/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: string.h
 *	Objetivo: Funções para a manipulação de caracteres.
*/
#include <string.h>

uint32_t kStrlen(const char8_t* str)
{
	uint32_t i;
	for (i = 0; str[i] != 0; i++);
	return i;
}
