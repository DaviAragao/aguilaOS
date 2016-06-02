# Compilador C
CC=gcc
# Aqui sao nossas regras de compilacao de todos os arquivos .CPP do ErdOS
CFLAGS=-Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -fpermissive -m32 -c

# Montador Asssembly
AS=nasm
# Regras de montagem do codigo asm
ASFLAGS=-f elf32 -o

# Linker
LD=ld
# Regras do vinculador
LDFLAGS=-m elf_i386 -T link.ld

all: clean compilar gerar_disco_grub gerar_iso

compilar:
	mkdir -p bin/ obj/
	
	@echo "Montando assembly do lancador (start.asm)..."
	$(AS) $(ASFLAGS) start.o start.asm
	
	@echo "Compilando 'libc' especifica..."
	$(CC) $(CFLAGS) libc/io.c
	
	@echo "Compilando principal (main.c)..."
	$(CC) $(CFLAGS) main.c
	
	@echo "Movendo objetos..."
	mv -v start.o io.o main.o obj/
	
	@echo "Linkando Kernel em bin/..."
	$(LD) $(LDFLAGS) -o bin/kernel.bin obj/start.o obj/main.o obj/io.o
	

gerar_disco_grub:
	@echo "Gerando disco de boot com GRUB..."
	@echo "Caso ocorra problemas de permissao, rode como root."
	@echo ""
	@echo "Copiando boot..."
	cp boot/grub.img bin/aguilaOS.img
	@echo "Criando ponto de montagem para imagem..."
	mkdir -p /tmp/ponto_montagem_grub_aguilaOS
	@echo "Montando grub..."
	mount -t auto bin/aguilaOS.img /tmp/ponto_montagem_grub_aguilaOS/
	@echo "Limpando..."
	rm -fv /tmp/ponto_montagem_grub_aguilaOS/kernel.bin
	@echo "Copiando kernel para imagem..."
	cp -v bin/kernel.bin /tmp/ponto_montagem_grub_aguilaOS/
	@echo "Desmontando e fixando dados..."
	umount /tmp/ponto_montagem_grub_aguilaOS/
	@echo "Limpando..."
	rm -rfv /tmp/ponto_montagem_grub_aguilaOS/
	@echo ""
	@echo ""
	@echo ""
	@echo "Tudo pronto! Sua imagem de disquete esta em bin/"

gerar_iso:
	@echo "Gerando ISO"
	genisoimage -quiet -V 'AGUILAOS' -input-charset iso8859-1 -o aguilaOS.iso -b aguilaOS.img -hide aguilaOS.img bin/

clean:
	@echo "Limpando..."
	rm -fv *.o *.bin
	rm -fv libc/*.o
	rm -fv obj/*.o
	rm -fv bin/*.bin
	rm -fv bin/*.img
