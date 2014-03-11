/*
** vm.h for vm in /home/thibaud/rendu/Corewar/vm
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Tue Feb 25 15:49:14 2014 thibaud
** Last update Tue Mar 11 08:59:30 2014 Thibaut Lopez
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

t_champ	*init_champ();
int	move_in_list(t_champ **champ, int nbr);
int	check_champ(t_champ **champ, char *path, int addr, int endian);
int	my_list_len(t_champ *champ);
void	init_adress(t_champ *champ);
void	fill_mem(char **mem, t_champ *champ);

#endif
