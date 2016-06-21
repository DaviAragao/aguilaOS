#include <io.h>
#include <string.h>

#define BUFFER 0xb8000

int corFonte = 15;
char* tela = (char*)(BUFFER);

void putsk(char* texto, int cor)
{
	int i = 0;
	corFonte = cor;
	for (i = 0; i < strlenk(texto); i++)
		putch(texto[i]);
}

void putch(char c)
{
	*tela = c;
	tela++;
	*tela = corFonte;
	tela++;
}

void clear(void) 
{
	char* mem = (char*)(BUFFER);
	while(*mem != 0)
	{
		*mem = 0;
		mem++;
	}
}

void outportb (unsigned short _port, unsigned char _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

unsigned char inportb (unsigned short _port)
{
	unsigned char rv;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}
