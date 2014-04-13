##
## Makefile for makefile in /home/thibaut.lopez/Corewar
##
## Made by Thibaut Lopez
## Login   <thibaut.lopez@epitech.net>
##
## Started on  Sun Feb 23 20:34:38 2014 Thibaut Lopez
## Last update Sun Apr 13 22:55:13 2014 romaric
##

CC=		gcc

VM_S=		champ_fun.c \
		check_reg.c \
		cycle_run.c \
		get_encode.c \
		list_fun.c \
		main.c \
		run_corewar.c \
		get_arg.c \
		mem_fun.c \
		rm_fun.c \
		function/fork_fun.c \
		function/ld_fun.c \
		function/no_encode.c \
		function/operation.c \
		function/other_fun.c \
		graphic/init_graphic.c \
		graphic/free_graphic.c \
		graphic/refresh_graphic.c \
		graphic/fmod.c \
		graphic/information.c

VM_N=		corewar

VM_O=		$(VM_S:.c=.o)

CFLAGS=		-W -Wall -Werror -I ../my/ -I ../ -I . -I ./graphic/fmodapi44432linux/api/inc -lSDL_image -lSDL_ttf -lSDL -lGL -lGLU ./graphic/fmodapi44432linux/api/lib/libfmodex64-4.44.32.so

all:		$(VM_N)

$(VM_N):	$(VM_O)
		$(CC) -o $(VM_N) $(VM_O) $(LDFLAGS) -L.. -lmy

clean:
		rm -f $(VM_O)

fclean:		clean
		rm -f $(VM_N)

re:		fclean all
