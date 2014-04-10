/*
** get_arg.c for get_arg in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Mar 20 16:24:21 2014 Thibaut Lopez
** Last update Wed Apr  9 19:35:36 2014 thibaud
*/

#include "vm.h"
#include "my.h"

int	get_all_type_arg(int *tab, t_champ *champ, unsigned char *mem, int *err)
{
  if (tab[0] == 0)
    {
      *err = -1;
      return (-1);
    }
  else if (tab[0] == 2)
    return (tab[2]);
  else if (tab[0] == 1)
    {
      *err = (check_reg(tab[2]) == 1) ? *err : -1;
      return ((check_reg(tab[2]) == 1) ? champ->reg[tab[2] - 1] : -1);
    }
  else
    return (get_nbr_action(mem,
			   mod_mem(champ->pc + (tab[2] % IDX_MOD)), tab[1]));
}

int	get_dir_ind_arg(int *tab, t_champ *champ, unsigned char *mem, int *err)
{
  if (tab[0] <= 1)
    {
      *err = -1;
      return (-1);
    }
  else if (tab[0] == 2)
    return (tab[2]);
  else
    return (get_nbr_action(mem,
			   mod_mem(champ->pc + (tab[2] % IDX_MOD)), tab[1]));
}

int	get_dir_reg_arg(int *tab, t_champ *champ, unsigned char *mem, int *err)
{
  (void)mem;
  if (tab[0] == 0 || tab[0] == 3)
    {
      *err = -1;
      return (-1);
    }
  else if (tab[0] == 2)
    return (tab[2]);
  else
    {
      *err = (check_reg(tab[2]) == 1) ? *err : -1;
      return ((check_reg(tab[2])) ? champ->reg[tab[2] - 1] : -1);
    }
}

int	get_dir_ind_arg_noidx(int *tab, t_champ *champ,
			      unsigned char *mem, int *err)
{
  if (tab[0] <= 1)
    {
      *err = -1;
      return (-1);
    }
  else if (tab[0] == 2)
    return (tab[2]);
  else
    return (get_nbr_action(mem,
			   mod_mem(champ->pc + tab[2]), tab[1]));
}

int	get_all_type_arg_noidx(int *tab, t_champ *champ,
			       unsigned char *mem, int *err)
{
  if (tab[0] == 0)
    {
      *err = -1;
      return (-1);
    }
  else if (tab[0] == 2)
    return (tab[2]);
  else if (tab[0] == 1)
    {
      *err = (check_reg(tab[2]) == 1) ? *err : -1;
      return ((check_reg(tab[2]) == 1) ? champ->reg[tab[2] - 1] : -1);
    }
  else
    return (get_nbr_action(mem,
			   mod_mem(champ->pc + tab[2]), tab[1]));
}
