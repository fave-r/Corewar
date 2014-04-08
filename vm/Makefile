##
## Makefile for makefile in /home/thibaut.lopez/Corewar
##
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
##
## Started on  Sun Feb 23 20:34:38 2014 Thibaut Lopez
## Last update Tue Apr  8 15:04:33 2014 Thibaut Lopez
##

VM_S=		champ_fun.c \
		cycle_run.c \
		get_encode.c \
		list_fun.c \
		main.c \
		run_corewar.c \
		get_arg.c \
		tmp.c \
		rm_fun.c \
		function/fork_fun.c \
		function/ld_fun.c \
		function/no_encode.c \
		function/operation.c \
		function/other_fun.c \
		graphic/init_graphic.c \
		graphic/free_graphic.c \
		graphic/refresh_graphic.c \
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
