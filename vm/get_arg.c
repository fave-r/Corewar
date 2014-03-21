/*
** get_arg.c for get_arg in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Mar 20 16:24:21 2014 Thibaut Lopez
** Last update Fri Mar 21 12:18:41 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	get_all_type_arg(int type, int val, t_champ *champ, unsigned char *mem)
{
  if (type == 0)
    return (-1);
  else if (type == 2)
    return (val);
  else if (type == 1)
    return ((check_reg(val) == 1) ? champ->reg[val - 1] : -1);
  else
    return (get_nbr_action(mem, (champ->pc + (val % IDX_MOD)) % MEM_SIZE, 4));
}

int	get_dir_ind_arg(int type, int val, t_champ *champ, unsigned char *mem)
{
  if (type <= 1)
    return (-1);
  else if (type == 2)
    return (val);
  else
    return (get_nbr_action(mem, (champ->pc + (val % IDX_MOD)) % MEM_SIZE, 4));
}

int	get_dir_reg_arg(int type, int val, t_champ *champ)
{
  if (type == 0 || type == 3)
    return (-1);
  else if (type == 2)
    return (val);
  else
    return ((check_reg(val)) ? champ->reg[val - 1] : -1);
}
