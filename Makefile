##
## Makefile for makefile in /home/thibaut.lopez/Corewar
## 
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
## 
## Started on  Sun Feb 23 20:34:38 2014 Thibaut Lopez
## Last update Thu Feb 27 09:46:25 2014 Thibaut Lopez
##

LIB_S=		my/basic.c \
		my/my_bzero.c \
		my/my_endian.c \
		my/my_getnbr_base.c \
		my/my_getnbr.c \
		my/my_putchar.c \
		my/my_putnbr_base.c \
		my/my_putnbr.c \
		my/my_strchr.c \
		my/my_strcmp.c \
		my/my_strdup.c \
		my/my_strlen.c \
		my/my_xtest.c
## Mettre ici tous les fichier C de la library avec leur chemin ("my/")

ASM_N=		asm/

VM_N=		vm/

LIB_N=		libmy.a

LIB_O=		$(LIB_S:.c=.o)

all:		$(LIB_O)
		ar rc $(LIB_N) $(LIB_O)
		make -C $(ASM_N)
		make -C $(VM_N)

clean:
		rm -f $(LIB_O)
		make clean -C $(ASM_N)
		make clean -C $(VM_N)

fclean:		clean
		rm -f $(LIB_N)
		make fclean -C $(ASM_N)
		make fclean -C $(VM_N)

re:		fclean all
