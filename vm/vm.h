/*
** vm.h for vm in /home/thibaud/rendu/Corewar/vm
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Last update Wed Mar 12 18:27:20 2014 thibaud
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
  int			wait;
  struct s_champ	*next;
  struct s_champ	*prev;
}			t_champ;

typedef struct 	s_cor
{
  t_champ	*champ;
  char		*mem;
  int		dump;
  int		live_done;
  int		cycle_done;
  int		cycle_to_die;
  int		endian;
  int		live[4];
  int		champs_nb[4];
  int		nb_chmps_alive;
}		t_cor;

typedef struct	s_struct
{
  char		mnemonique;
  int		(* ptr_fct)(t_cor *, t_champ *);
  int		wait;
}		t_struct;

t_struct	ptr_fct[23];

t_champ	*init_champ();
int	move_in_list(t_champ **champ, int nbr);
int	check_champ(t_champ **champ, char *path, int addr, int endian);
int	my_list_len(t_champ *champ);
void	init_adress(t_champ *champ);
void	fill_mem(char **mem, t_champ *champ);
int	get_nbr_action(char *mem, int pc, int len);
int	**get_encode(char *mem, int pc);

int	someone_is_dead(t_champ *, t_cor *);
int	run_corewar(t_champ *, t_cor *);
t_champ *del_chmp(t_champ *, int);
int	cycle_run(t_champ *, t_cor *);
int	get_wait(t_champ *, t_cor *);
int	champ_play(t_champ *, t_cor *);
int	find_in_tab(char *);
int	end_game(t_champ *, t_cor *);

#endif
