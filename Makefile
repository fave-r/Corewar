##
## Makefile for makefile in /home/thibaut.lopez/Corewar
## 
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
## 
## Started on  Sun Feb 23 20:34:38 2014 Thibaut Lopez
## Last update Sun Feb 23 20:44:11 2014 Thibaut Lopez
##

ASM_S=		## Mettre ici tous les fichier C de l'ASM avec leur chemin

VM_S=		## Mettre ici tous les fichier C de la VM avec leur chemin

LIB_S=		## Mettre ici tous les fichier C de la library avec leur chemin ("my/")

ASM_N=		asm

VM_N=		corewar

LIB_N=		libmy.a

CC=		gcc -W -Wall -Werror -I my/ -I asm/ -I vm/ # Si besoin, rajouter ici d'autres -I

ASM_O=		$(ASM_S=.c:.o)

VM_O=		$(VM_S=.c:.o)

LIB_O=		$(LIB_S=.c:.o)

all:		$(LIB_N) $(ASM_N) $(VM_N)

$(LIB_N):	$(LIB_O)
		ar rc $(LIB_N) $(LIB_O)

$(ASM_N):	$(ASM_O)
		$(CC) $(ASM_N) $(ASM_O)

$(VM_N):	$(VM_O)
		$(CC) $(VM_N) $(VM_O)

clean:
		rm -f $(ASM_O)
		rm -f $(VM_O)
		rm -f $(LIB_O)

fclean:		clean
		rm -f $(ASM_N)
		rm -f $(VM_N)
		rm -f $(LIB_N)

re:		fclean all
