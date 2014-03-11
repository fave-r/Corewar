/*
** vm.h for vm in /home/thibaud/rendu/Corewar/vm
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Tue Feb 25 15:49:14 2014 thibaud
<<<<<<< HEAD
** Last update Tue Mar 11 16:26:01 2014 Thibaut Lopez
=======
<<<<<<< HEAD
** Last update Tue Mar 11 15:23:50 2014 thibaud
=======
** Last update Tue Mar 11 08:59:30 2014 Thibaut Lopez
>>>>>>> c0170bdbdfe4ae04b9c353ff3ff449a277ff1f5c
>>>>>>> cbb57c0ce9464c9af0bd7f53dd9e510acd100012
*/

#ifndef VM_H
#define VM_H
#define ER_DUMP	"Warning : Wrong value for nbr_cycle. Have been initialized at 0x68.\n"
#define ER_COR	" is not a corewar executable.\n"
#define ER_SIZE	" take to much memory to be launched.\n"
#define ER_POS1	"Error : the position "
#define	ER_POS2	"  is already taken by the file "
#define ER_POS3	".\n"
#define	ER_FULL	"Cannot find a new place for another champ : places already taken.\n"
#define ER_VOID	"You haven't gave a single correct champion.\n"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "op.h"

typedef struct		s_champ
{
  header_t		*head;
  char			*path;
  int			fd;
  int			champ_nb;
  int			adress;
  int			pc;
  int			reg[REG_NUMBER];
  int			carry;
<<<<<<< HEAD
  int			wait;
  int			jump;
=======
  int			cycle_to_wait;
>>>>>>> cbb57c0ce9464c9af0bd7f53dd9e510acd100012
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef struct 	s_cor
{
  t_champ	*champ;
  char		*mem;
  int		dump;
  int		cycle;
  int		cycle_to_die;
  int		endian;
  int		live[4];
}		t_cor;

typedef struct	s_struct
{
  char		mnémonique;
  int		(* ptr_fct)(t_cor *, t_champ *);
  int		ctw;
}		t_struct;

t_struct	ptr_fct[23];

t_champ	*init_champ();
int	move_in_list(t_champ **champ, int nbr);
int	check_champ(t_champ **champ, char *path, int addr, int endian);
int	my_list_len(t_champ *champ);
void	init_adress(t_champ *champ);
void	fill_mem(char **mem, t_champ *champ);

int	repartisseur(t_champ *, t_cor *);
int	cycle_run(t_champ *, t_cor *);
int	find_in_tab(char *);

#endif
