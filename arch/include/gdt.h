/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: gdt.h
 *	Objetivo: Definir as estruturas da tabela global de descritores.
*/
#ifndef GDT_H
	#define GDT_H
	#include <unistd.h>

	/* gdt_segment 
	 * Uma entrada na GDT.
	 * Caso restem dúvidas no conceito implementado de uma olhada no arquivo doc/gdt/gdt.txt
	 * */
	typedef struct gdt_segment
	{
		uint16_t limit_low;
		uint16_t base_low;
		struct gdt_hight
		{
			uint16_t base_middle 	: 8;
			uint16_t type		: 4;
			uint16_t desc_type	: 1;
			uint16_t dpl		: 2;
			uint16_t present	: 1;
			uint16_t limit_hight	: 4;
			uint16_t avaliable	: 1;
			uint16_t reserved	: 1;
			uint16_t db		: 1;
			uint16_t granularity	: 1;
			uint16_t base_hight	: 8;
		}__attribute__((packed)) hight;
	}__attribute__((packed)) gdt_t;

	/* 
	 * gdt_register
	 * A estrutura que será carregada para o registrador do processador. Aponta para a primeira entrada da GDT, o segmento nulo.
	 * */
	typedef struct gdt_register 
	{
		uint16_t limit;
		uint32_t base_address;
	}__attribute__((packed)) gdtr;

#endif
