/*
 *	AguilaOS - Sistema operacional para ensino de sistemas operacionais.
 *	Davi Augusto Aragão.
 *	GNU GPL.
 *
 *	Arquivo: test.c
 *	Objetivo: Criar casos de teste para os conceitos implementados.
*/
#include <test.h>

/*
 * Chama todos os casos de teste.
 * */
void testMain(void)
{
	testGDT(get_gdt(), get_gdtr());
}

void testGDT(void* gdt, void* gdtr)
{
	uint32_t i;
	void* aux = gdt;

	/*
	 * Verifica se a GDT existe.
	 * */
	if(!gdt || !gdtr)
		printk("******* GDT ou GDTR não inicializadas *******\n");
/*	else if(gdtr->gdtptr.base_address != gdt)
		printk("******** O endereço em GDTR não é o endereço da GDT ********");*/

	/*
	 * Exibe as entradas da tabela GDT.
	 * */
	for (i = 0; i <= GDT_SIZE; i++)
	{
		printk("******* Segmento da GDT ********\n");
		print_mem(aux, aux + 64);
		aux += 64;
	}
}
