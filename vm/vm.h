/*
** vm.h for vm in /home/thibaud/rendu/Corewar/vm
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Tue Feb 25 15:49:14 2014 thibaud
** Last update Wed Feb 26 18:14:12 2014 Thibaut Lopez
*/

#ifndef VM_H
#define VM_H
#define ER_DUMP	"Warning : Wrong value for nbr_cycle. Have been initialized at 150.\n"
#define ER_COR	" is not a .cor file.\n"
#define ER_SIZE	" take to much memory to be launched.\n"
#define ER_POS1	"Error : the position "
#define	ER_POS2	"  is already taken by the file"
#define ER_POS3	". Setting the champion to the next available position.\n"
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
  int		dump;
  int		cycle;
  int		cycle_to_die;
}		t_cor;

t_champ	*init_champ();
void	move_in_list(t_champ **champ, int nbr);
int	check_champ(t_champ *champ, char *path, int addr);

#endif
