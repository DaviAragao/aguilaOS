AguilaOS
=====
AguilaOS é um protótipo de um sistema operacional desenvolvido em C com o objetivo de estudo.

---

Compilando o sistema:

- ** Nota: Não é recomendado o teste de Kernels 'caseiros' em hardwares reais/físicos, pois não é prevista a reação disto. O simples teste pode acabar DANIFICANDO seu equipamento. Caso queira testar, faça por sua conta e risco. O uso de máquinas virtuais não oferece NENHUM risco de dano a sua máquina física. **

Para compilar o AguilaOS é incrívelmente simples! O sistema já conta com uma imagem pronta do GRUB 0.5.96 que ja é automáticamente modificada quando seu kernel é linkado corretamente pelo script Makefile.


Você irá precisar ter um sistema Linux instalado na sua máquina. ALGUMAS pessoas tem problemas ao compilar o AguilaOS em sistemas operacionais x86_64, então é recomendado que você use um sistema operacional apenas 32 bits para a tarefa. 
Além disso, você irá precisar das seguintes ferramentas instaladas para conseguir construir o AguilaOS.

- Nasm (Netwide Assembler)
- GCC(GNU C Compiler)
- LD (GNU Linker)
- Make (GNU Make)
- QEMU (Virtual Machine)

Com isso pronto, vamos a compilação...
Você pode baixar o ZIP e descompactar ou simplesmente fazer o clone em seu HD.

Depois de concluído, basta entrar como root e construir o sistema AguilaOS

$ su

 # make

ou

$ sudo make

Ao termino, se todo ocorrer bem, será gerado 2 arquivos na pasta bin. O 'aguilaOS.img' e o kernel.bin.

aguilaOS.img é nada mais do que uma imagem de disquete com seu kernel recentemente gerado atrelado ao GRUB. Você pode gravar a um disquete físico ou testar com o QEMU

 # qemu-system-i386 -fda bin/aguilaOS.img

Você pode usar também aguilaOS.iso para carregar seu sistema operacional a partir do drive de CD em uma máquina física ou em um virtualizador.
