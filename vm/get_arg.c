/*
** get_arg.c for get_arg in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Mar 20 16:24:21 2014 Thibaut Lopez
** Last update Sat Mar 29 16:32:03 2014 thibaud
*/

#include "vm.h"
#include "my.h"

int	get_all_type_arg(int **tab, int i, t_champ *champ, unsigned char *mem)
{
  if (tab[i][0] == 0)
    return (-1);
  else if (tab[i][0] == 2)
    return (tab[i][2]);
  else if (tab[i][0] == 1)
    return ((check_reg(tab[i][2]) == 1) ? champ->reg[tab[i][2] - 1] : -1);
  else
    return (get_nbr_action(mem,
			   mod_mem(champ->pc + (tab[i][2] % IDX_MOD)), tab[i][1]));
}

int	get_dir_ind_arg(int **tab, int i, t_champ *champ, unsigned char *mem)
{
  if (tab[i][0] <= 1)
    return (-1);
  else if (tab[i][0] == 2)
    return (tab[i][2]);
  else
    return (get_nbr_action(mem,
			   mod_mem(champ->pc + (tab[i][2] % IDX_MOD)), tab[i][1]));
}

int	get_dir_reg_arg(int **tab, int i, t_champ *champ, unsigned char *mem)
{
  (void)mem;
  if (tab[i][0] == 0 || tab[i][0] == 3)
    return (-1);
  else if (tab[i][0] == 2)
    return (tab[i][2]);
  else
    return ((check_reg(tab[i][2])) ? champ->reg[tab[i][2] - 1] : -1);
}

int	get_dir_ind_arg_noidx(int **tab, int i,
			      t_champ *champ, unsigned char *mem)
{
  if (tab[i][0] <= 1)
    return (-1);
  else if (tab[i][0] == 2)
    return (tab[i][2]);
  else
    return (get_nbr_action(mem,
			   mod_mem(champ->pc + tab[i][2]), tab[i][1]));
}

int	get_all_type_arg_noidx(int **tab, int i,
			       t_champ *champ, unsigned char *mem)
{
  if (tab[i][0] == 0)
    return (-1);
  else if (tab[i][0] == 2)
    return (tab[i][2]);
  else if (tab[i][0] == 1)
    return ((check_reg(tab[i][2]) == 1) ? champ->reg[tab[i][2] - 1] : -1);
  else
    return (get_nbr_action(mem,
			   mod_mem(champ->pc + tab[i][2]), tab[i][1]));
}
