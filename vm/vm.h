/*
** vm.h for vm in /home/thibaud/rendu/Corewar/vm
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Last update Thu Mar 13 10:42:42 2014 Thibaut Lopez
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
  int		cycle;
  int		cycle_to_die;
  int		endian;
  int		live[4];
  int		champs_nb[4];
  int		nb_chmps_alive;
}		t_cor;

typedef struct	s_struct
{
  char		mnemonique;
  int		(* ptr_fct)(t_champ *, t_cor *);
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
int	find_in_tab(char);
int	end_game(t_champ *, t_cor *);

int	my_live(t_champ *champ, t_cor *cor);
int	my_ld(t_champ *champ, t_cor *cor);
int	my_st(t_champ *champ, t_cor *cor);
int	my_add(t_champ *champ, t_cor *cor);
int	my_sub(t_champ *champ, t_cor *cor);
int	my_and(t_champ *champ, t_cor *cor);
int	my_or(t_champ *champ, t_cor *cor);
int	my_xor(t_champ *champ, t_cor *cor);
int	my_zjmp(t_champ *champ, t_cor *cor);
int	my_ldi(t_champ *champ, t_cor *cor);
int	my_sti(t_champ *champ, t_cor *cor);
int	my_fork(t_champ *champ, t_cor *cor);
int	my_lld(t_champ *champ, t_cor *cor);
int	my_lldi(t_champ *champ, t_cor *cor);
int	my_lfork(t_champ *champ, t_cor *cor);
int	my_aff(t_champ *champ, t_cor *cor);

#endif
