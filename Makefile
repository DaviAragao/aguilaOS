# Compilador C
CC=gcc
# Aqui sao nossas regras de compilacao de todos os arquivos .C
CFLAGS=-Iinclude -Iarch/include -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -m32 -c

# Montador Asssembly
AS=nasm
# Regras de montagem do codigo asm
ASFLAGS=-f elf32 -o

# Linker
LD=ld
# Regras do vinculador
LDFLAGS=-m elf_i386 -T arch/x86/boot/link.ld

all: clean compilar gerar_disco_grub gerar_iso

compilar:
	mkdir -p bin/ obj/
	
	@echo "Montando assembly do lancador (start.asm)..."
	$(AS) $(ASFLAGS) start.o arch/x86/boot/start.asm
	
	@echo "Compilando 'lib' especifica..."
	$(CC) $(CFLAGS) lib/string.c

	@echo "Compilando código da arquitetura(archMain.c)..."
#	$(CC) $(CFLAGS) arch/x86/io.c
	$(CC) $(CFLAGS) arch/x86/video.c
	$(CC) $(CFLAGS) arch/x86/gdt.c
	$(CC) $(CFLAGS) arch/x86/boot/archMain.c
	
	@echo "Compilando principal (kernel.c)..."
	$(CC) $(CFLAGS) kernel/kernel.c
	
	@echo "Movendo objetos..."
	mv -v start.o string.o video.o gdt.o archMain.o kernel.o obj/
	
	@echo "Linkando Kernel em bin/..."
	$(LD) $(LDFLAGS) -o bin/kernel.bin obj/start.o obj/kernel.o obj/archMain.o obj/gdt.o obj/video.o obj/string.o
	

gerar_disco_grub:
	@echo "Gerando disco de boot com GRUB..."
	@echo "Caso ocorra problemas de permissao, rode como root."
	@echo ""
	cp grub/grub.img bin/aguilaOS.img
	@echo "Criando ponto de montagem para imagem..."
	mkdir -p /tmp/aguilaOS
	@echo "Montando grub..."
	sudo mount -t auto bin/aguilaOS.img /tmp/aguilaOS/
	@echo "Limpando..."
	sudo rm -fv /tmp/aguilaOS/kernel.bin
	@echo "Copiando kernel para imagem..."
	sudo cp -v bin/kernel.bin /tmp/aguilaOS/
	@echo "Desmontando e fixando dados..."
	sudo umount /tmp/aguilaOS/
	@echo "Limpando..."
	sudo rm -rfv /tmp/aguilaOS/
	@echo ""
	@echo ""
	@echo ""
	@echo "Tudo pronto! Sua imagem de disquete esta em bin/"

gerar_iso:
	@echo "Gerando ISO..."
	genisoimage -quiet -V 'AGUILAOS' -input-charset iso8859-1 -o aguilaOS.iso -b aguilaOS.img -hide aguilaOS.img bin/

clean:
	@echo "Limpando..."
	rm -fv *.o *.bin
	rm -fv lib/*.o
	rm -fv obj/*.o
	rm -fv bin/*.bin
	rm -fv bin/*.img
