AguilaOS
=====
AguilaOS é um protótipo de um sistema operacional desenvolvido em C com o objetivo de auxiliar no estudo de sistemas operacionais.

===
Usando o sistema:

Para usar AguilaOS basta fazer o download do arquivo aguilaOS.iso e usá-lo na sua máquina virtual ou então copiá-lo para um CD físico e iniciar a sua máquina pelo CD.

===
Compilando o sistema:

Em ambiente linux você irá precisar das seguintes ferramentas instaladas para conseguir baixar e compilar o AguilaOS.

- Nasm (Netwide Assembler)
- GCC (GNU C Compiler)
- LD (GNU Linker)
- Make (GNU Make)
- QEMU (Virtual Machine)
- GIT (Versionador)

Você pode baixar o .zip e descompactar ou fazer o clone do repositório.

git clone https://github.com/DaviAragao/aguilaOS

Depois de concluído, basta entrar como root e construir o sistema AguilaOS:

**sudo make**

Serão gerados 2 arquivos na pasta bin: aguilaOS.img e kernel.bin.

aguilaOS.img é uma imagem de disquete com seu kernel compilado e linkado ao GRUB. Você pode gravar a um disquete físico ou testar com o QEMU:

**qemu-system-i386 -fda bin/aguilaOS.img**

kernel.bin é o sistema operacional compilado em formato binário. Para usá-lo basta chamar QEMU da seguinte forma: 

**qemu-system-i386 -kernel bin/kernel.bin**

O processo de compilação substitui ainda o arquivo aguilaOS.iso com a nova iso do sistema operacional.

O projeto está dividido da seguinte forma:


- arch (Código dependente da arquitetura).
- bin (Diretório em que ficarão aguilaOS.img e kernel.bin após a compilação).
- grub (Imagem do GRUB).
- include (Arquivos de cabeçalhos do kernel).
- kernel (Código principal do sistema operacional).
- lib (Biblioteca com funções auxiliares).
- obj (Pasta usada em tempo de compilação).


AguilaOS foi desenvolvido para você testar, modificar, recompilar e melhorar. Portanto não sinta-se intimidado, aguardamos ansiosamente para ver as melhorias que você fará.
