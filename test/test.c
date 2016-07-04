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
//	testVideo();
}

void testGDT(void* gdt, void* pgdtr)
{
	gdtr* gdt_ptr = (gdtr*) pgdtr;

	/*
	 * Verifica se a GDT existe.
	 * */
	if(!gdt || !gdt_ptr)
		printk("******* GDT ou GDTR não inicializadas *******\n");
	else if((*gdt_ptr).base_address != gdt)
		printk("******** O endereço em GDTR não é o endereço da GDT ********\n");
}

/*
 * Testa algumas funções do driver de video.
 * */
void testVideo(void)
{
	uint32_t i;
	clear();
	printk("AguilaOS\n");
	for (i = 0; i < 23; i++)
		printk("Davi Augusto Aragão\n");

}
