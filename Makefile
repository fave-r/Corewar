##
<<<<<<< HEAD
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
=======
## Makefile for Makefile in /home/odet_a/Corewar
## 
## Made by 
## Login   <odet_a@epitech.net>
## 
## Started on  Mon Feb 17 04:28:28 2014 
## Last update Mon Feb 17 18:56:58 2014 
##

NAME=	asm

CC=	gcc -W -Wall

SRC=	main.c \
	op.c \
	parsing/parsing.c \
	parsing/lib/basic.c \
	parsing/lib/xfunction.c \
	parsing/get_next_line/get_next_line.c

RM=	rm -f

T=	*~

all:
	$(CC) -o $(NAME) $(SRC)

clean:
	$(RM) $(T)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
>>>>>>> 3db6bf54b2ee3975a2942bd3263118d38c0d7cdd
