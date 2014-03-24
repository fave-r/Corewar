##
## Makefile for makefile in /home/thibaut.lopez/Corewar
## 
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
## 
## Started on  Sun Feb 23 20:34:38 2014 Thibaut Lopez
## Last update Mon Mar 24 14:12:59 2014 Thibaut Lopez
##

VM_S=		champ_fun.c \
		cycle_run.c \
		get_encode.c \
		list_fun.c \
		main.c \
		run_corewar.c \
		spec_fun.c \
		get_arg.c \
		tmp.c \
		rm_fun.c \
		Function/ld_fun.c \
		Function/no_encode.c \
		Function/operation.c \
		Function/other_fun.c \
		Graphic/init_graphic.c \
		Graphic/free_graphic.c \
		Graphic/refresh_graphic.c \
		check_reg.c

VM_N=		corewar

VM_O=		$(VM_S:.c=.o)

CC=		gcc -g3 -W -Wall -Werror -I ../my/ -I ../ -I .

all:		$(VM_N)

$(VM_N):	$(VM_O)
		$(CC) -o $(VM_N) $(VM_O) -L.. -lmy  -lSDL -lGL -lGLU

clean:
		rm -f $(VM_O)

fclean:		clean
		rm -f $(VM_N)

re:		fclean all
