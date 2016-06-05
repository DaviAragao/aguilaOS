AguilaOS
=====
AguilaOS é um protótipo de um sistema operacional desenvolvido em C com o objetivo de estudo.

---
Usando o sistema:

Para usar AguilaOS basta fazer o download so arquivo aguilaOS.iso e usá-lo no drive de CD de sua máquina virtual ou então copiá-lo para um CD físico e iniciar a sua máquina pelo CD.

---
Compilando o sistema:

Em ambiente linux você irá precisar das seguintes ferramentas instaladas para conseguir construir o AguilaOS.

- Nasm (Netwide Assembler)
- GCC (GNU C Compiler)
- LD (GNU Linker)
- Make (GNU Make)
- QEMU (Virtual Machine)
- GIT (Versionador)

Com isso pronto, vamos a compilação...
Você pode baixar o .zip e descompactar ou simplesmente fazer o clone do repositório.

git clone https://github.com/DaviAragao/aguilaOS

Depois de concluído, basta entrar como root e construir o sistema AguilaOS

sudo make

Ao termino, se todo ocorrer bem, será gerado 2 arquivos na pasta bin. O 'aguilaOS.img' e o kernel.bin.

aguilaOS.img é uma imagem de disquete com seu kernel construido amarrado ao GRUB. Você pode gravar a um disquete físico ou testar com o QEMU

 qemu-system-i386 -fda bin/aguilaOS.img
