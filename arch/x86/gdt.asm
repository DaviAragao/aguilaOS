global install_gdt      ;Função descrita em gdt.h
extern gdtptr           ;Estrutura que aponta para a GDT

install_gdt:
    lgdt [gdtptr]       ;Carrega a GDT
    mov ax, 0x10        ;Atualiza o segmento de dados
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    jmp 0x08:return     ;Atualiza o segmento de código
	return:
	    ret