/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: unistd.h
 *	Objetivo: Definir os tipos das variáveis que serão usadas no sistema operacional.
*/
#ifndef UNISTD_H

	#define UNISTD_H
	#include <config.h>
	#define NULL (void*)0
	#ifdef ARCH_X86
		/*caracteres*/
		typedef char char8_t;
		typedef unsigned char uchar8_t;

		/*numeros*/
		typedef short int16_t;
		typedef unsigned short uint16_t;
		typedef int int32_t;
		typedef unsigned int uint32_t;
		typedef long long int64_t;
		typedef unsigned long long uint64_t;

		/*tamanhos*/
		typedef unsigned long size_t;
		typedef long ssize_t;
	#endif

#endif
