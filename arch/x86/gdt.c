/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: gdt.c
 *	Objetivo: Configurar e inicializar a GDT descrita em gdt.h
*/
#include <x86/gdt.h>

/*
 * Tabela GDT do AguilaOS.
 * */
gdt_t gdt[GDT_SIZE];

/*
 * GDTR, estrutura que mostra-rá ao processador onde está a GDT.
 * */
gdtr gdtptr;

/*
 * AguilaOS usa a GDT para segmentar a memória em 4 segmentos de 0 a 4Gb. Um segmento para código do usuário, um segmento para
 * dados do usuário, um segmento para código do kernel e um segmento para dados do kernel. Além destes segmentos, o sistema
 * operacional cria um segmento nulo, necessário para qualquer GDT. Os sistemas operacionais modernos trabalham dessa mesma forma.
 * Leia mais sobre o conceito implementado em doc/gdt/gdt.txt.
 *
 *
			  		Segmento de código do usuário
	      |-----------------------------------------------------------------------------|

			  		Segmento de dados do usuário
	      |-----------------------------------------------------------------------------|

			  		Segmento de código do Kernel
	      |-----------------------------------------------------------------------------|

			  		Segmento de dados do Kernel
	      |-----------------------------------------------------------------------------|

		Segmento nulo
		|-|
				    		Memória
		0Gb									4Gb
		+-------------------------------------------------------------------------+
		|									  |
		|									  |
		|									  |
		|									  |
		|									  |
		+-------------------------------------------------------------------------+
 * 
 * */

/*
 * Retorna o ponteiro da GDTR.
 * */
void* get_gdtr(void)
{
	return &gdtptr;
}

/*
 * Retorna o ponteiro da GDT.
 * */
void* get_gdt(void)
{
	return gdt;
}

/*
 * O setup_gdt prepara e instala a GDT.
 * */
void setup_gdt(void)
{
	prepare_gdt();
//	install_gdt();
}

/*
 * prepare_gdt preenche os valores das estruturas criadas.
 * */
void prepare_gdt(void)
{
	/*
	 * Segmento nulo, necessário para que o processador entenda GDT corretamente.
	 * */
	gdt[0].limit_low 		= GDT_NULL_SEGMENT;
	gdt[0].base_low 		= GDT_NULL_SEGMENT;
	gdt[0].hight.base_middle 	= GDT_NULL_SEGMENT;
	gdt[0].hight.type 		= GDT_NULL_SEGMENT;
	gdt[0].hight.desc_type 		= GDT_NULL_SEGMENT;
	gdt[0].hight.dpl 		= GDT_NULL_SEGMENT;
	gdt[0].hight.present 		= GDT_NULL_SEGMENT;
	gdt[0].hight.limit_hight 	= GDT_NULL_SEGMENT;
	gdt[0].hight.avaliable 		= GDT_NULL_SEGMENT;
	gdt[0].hight.reserved 		= GDT_NULL_SEGMENT;
	gdt[0].hight.db 		= GDT_NULL_SEGMENT;
	gdt[0].hight.granularity 	= GDT_NULL_SEGMENT;
	gdt[0].hight.base_hight 	= GDT_NULL_SEGMENT;

	/*
	 * Segmento de código do Kernel.
	 * */
	gdt[1].limit_low 		= GDT_LIMIT_LOW_4GB;
	gdt[1].base_low 		= ZERO;
	gdt[1].hight.base_middle 	= ZERO;
	gdt[1].hight.type 		= GDT_TYPE_CODE_READEXECUTE;
	gdt[1].hight.desc_type 		= GDT_DESCTYPE_CODEDATA;
	gdt[1].hight.dpl 		= GDT_DPL_KERNEL_RING;
	gdt[1].hight.present 		= ONE;
	gdt[1].hight.limit_hight 	= GDT_LIMIT_HIGHT_4GB;
	gdt[1].hight.avaliable 		= ZERO;
	gdt[1].hight.reserved 		= ZERO;
	gdt[1].hight.db 		= GDT_DB_32BITS;
	gdt[1].hight.granularity 	= GDT_GRAN_4GB;
	gdt[1].hight.base_hight 	= ZERO;

	/*
	 * Segmento de dados do Kernel.
	 * */
	gdt[2].limit_low 		= GDT_LIMIT_LOW_4GB;
	gdt[2].base_low 		= ZERO;
	gdt[2].hight.base_middle 	= ZERO;
	gdt[2].hight.type 		= GDT_TYPE_DATA_READWRITE;
	gdt[2].hight.desc_type 		= GDT_DESCTYPE_CODEDATA;
	gdt[2].hight.dpl 		= GDT_DPL_KERNEL_RING;
	gdt[2].hight.present 		= ONE;
	gdt[2].hight.limit_hight 	= GDT_LIMIT_HIGHT_4GB;
	gdt[2].hight.avaliable 		= ZERO;
	gdt[2].hight.reserved 		= ZERO;
	gdt[2].hight.db 		= GDT_DB_32BITS;
	gdt[2].hight.granularity 	= GDT_GRAN_4GB;
	gdt[2].hight.base_hight 	= ZERO;

	/*
	 * Segmento de código do usuário.
	 * */
	gdt[3].limit_low 		= GDT_LIMIT_LOW_4GB;
	gdt[3].base_low 		= ZERO;
	gdt[3].hight.base_middle 	= ZERO;
	gdt[3].hight.type 		= GDT_TYPE_CODE_READEXECUTE;
	gdt[3].hight.desc_type 		= GDT_DESCTYPE_CODEDATA;
	gdt[3].hight.dpl 		= GDT_DPL_USER_RING;
	gdt[3].hight.present 		= ONE;
	gdt[3].hight.limit_hight 	= GDT_LIMIT_HIGHT_4GB;
	gdt[3].hight.avaliable 		= ZERO;
	gdt[3].hight.reserved 		= ZERO;
	gdt[3].hight.db 		= GDT_DB_32BITS;
	gdt[3].hight.granularity 	= GDT_GRAN_4GB;
	gdt[3].hight.base_hight 	= ZERO;

	/*
	 * Segmento de dados do usuário.
	 * */
	gdt[4].limit_low 		= GDT_LIMIT_LOW_4GB;
	gdt[4].base_low 		= ZERO;
	gdt[4].hight.base_middle 	= ZERO;
	gdt[4].hight.type 		= GDT_TYPE_DATA_READWRITE;
	gdt[4].hight.desc_type 		= GDT_DESCTYPE_CODEDATA;
	gdt[4].hight.dpl 		= GDT_DPL_USER_RING;
	gdt[4].hight.present 		= ONE;
	gdt[4].hight.limit_hight 	= GDT_LIMIT_HIGHT_4GB;
	gdt[4].hight.avaliable 		= ZERO;
	gdt[4].hight.reserved 		= ZERO;
	gdt[4].hight.db 		= GDT_DB_32BITS;
	gdt[4].hight.granularity 	= GDT_GRAN_4GB;
	gdt[4].hight.base_hight 	= ZERO;

	/*
	 * Ajusta GDTR para a GDT.
	 * */
	gdtptr.limit = (GDT_SIZE * sizeof(gdt_t)) - 1;
	gdtptr.base_address = gdt;
}

/*
 * Carrega o ponteiro para a GDT dentro do registrador GDTR.
 * */
inline void install_gdt(void)
{
	asm(	
		"lgdt %0 \n\t"/* Load Global Descriptor Table */
		//"reloadData: \n\t"
		/* Recarrega segmento de dados */
		"	movw %2, %%ax \n\t"
		"	movw %%ax, %%ds \n\t"
		"	movw %%ax, %%es \n\t"
		"	movw %%ax, %%fs \n\t"
		"	movw %%ax, %%gs \n\t"
		"	movw %%ax, %%ss \n\t"
		/* Recarrega segmento de código */
		"ljmp %1, $0 \n\t"//$reloadData \n\t"
		::"m"(gdtptr), "i"(KERNEL_CS), "i"(KERNEL_DS): "eax"
	);
}
