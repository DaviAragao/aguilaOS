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

	#define ZERO 0
	#define ONE 1
	/*
	 * Campos zerados, segmento nulo.
	 * */
	#define GDT_NULL_SEGMENT ZERO

	/*
	 * Número de entradas da GDT.
	 * */
	#define GDT_SIZE 4

	/*
	 * Granulidade incrementando de 4 em 4kb, tamanho do segmento até 4Gb.
	 * */
	#define GDT_GRAN_4GB ONE

	/*
	 * Granulidade incrementando de 1 em 1Byte, tamanho do segmento até 1Mb.
	 * */
	#define GDT_GRAN_1MB ZERO

	/*
	 * Limite 4Gb parte baixa. 16bits 1.
	 * */
	#define GDT_LIMIT_LOW_4GB 0xFFFF

	/*
	 * Limite 4Gb parte alta. 4bits 1.
	 * */
	#define GDT_LIMIT_HIGHT_4GB 0xF

	/*
	 * Segmento de sistema.
	 * */
	#define GDT_DESCTYPE_SYS ZERO

	/*
	 * Segmento de código ou de dados.
	 * */
	#define GDT_DESCTYPE_CODEDATA ONE

	/*
	 * Segmento de dados com permissão de leitura e escrita.
	 * */
	#define GDT_TYPE_DATA_READWRITE 2

	/*
	 * Segmento de código com permissão de leitura e execução.
	 * */
	#define GDT_TYPE_CODE_READEXECUTE 10

	/*
	 * Ring 0, nível de privilegio do kernel.
	 * */
	#define GDT_DPL_KERNEL_RING ZERO

	/*
	 * Ring 3, nível de privilegio do usuário.
	 * */
	#define GDT_DPL_USER_RING 3

	/*
	 * Segmento de 16bits.
	 * */
	#define GDT_DB_16BITS ZERO

	/*
	 * Segmento de 32bits.
	 * */
	#define GDT_DB_32BITS ONE

	/*
	 * Deslocamento do segmento de dados do Kernel.
	 * */
	#define KERNEL_DS 0x10

	/*
	 * Deslocamento do segmento de código do Kernel.
	 * */
	#define KERNEL_CS 0x08

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

	/*
	 * O setup_gdt prepara e instala a GDT.
	 * */
	void setup_gdt(void);

	/*
	 * prepare_gdt preenche os valores das estruturas criadas.
	 * */
	void prepare_gdt(void);

	/*
	 * Carrega o ponteiro para a GDT dentro do registrador GDTR.
	 * */
	extern void install_gdt(void);

	/*
	 * Retorna um ponteiro para a GDT.
	 * */
	void* get_gdt(void);

	/*
	 * Retorna um ponteiro para o GDTR.
	 * */
	void* get_gdtr(void);

#endif
