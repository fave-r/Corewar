/*
** ld_fun.c for ld in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:11:21 2014 Thibaut Lopez
** Last update Fri Apr 11 17:17:39 2014 thibaud
*/

#include "vm.h"
#include "my.h"

void	my_ld(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	arg;
  int	err;

  err = 0;
  tab = get_encode(cor->mem, champ->pc);
  arg = get_dir_ind_arg(tab[0], champ, cor->mem, &err);
  if (err != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      champ->carry = 1;
      champ->reg[tab[1][2] - 1] = arg;
      champ->pc += tab[0][1] + tab[1][1] + 2;
    }
  else
    {
      my_none(champ, cor);
      champ->carry = 0;
    }
  ifree(tab, 4);
}

void	my_ldi(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	arg1;
  int	arg2;
  int	err;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg1 = get_all_type_arg(tab[0], champ, cor->mem, &err);
  arg2 = get_dir_reg_arg(tab[1], champ, cor->mem, &err);
  if (err != -1 &&
      (tab[2][0] == 1 && check_reg(tab[2][2]) == 1) && tab[3][0] == 0)
    {
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + (arg1 + arg2) % IDX_MOD, 4);
      champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    {
      champ->carry = 0;
      my_none(champ, cor);
    }
  ifree(tab, 4);
}

void	my_lld(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	arg;
  int	err;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg = get_dir_ind_arg_noidx(tab[0], champ, cor->mem, &err);
  if (err != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      champ->carry = 1;
      champ->reg[tab[1][2] - 1] = arg;
      champ->pc += tab[0][1] + tab[1][1] + 2;
    }
  else
    {
      my_none(champ, cor);
      champ->carry = 0;
    }
  ifree(tab, 4);
}

void	my_lldi(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	arg1;
  int	arg2;
  int	err;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg1 = get_all_type_arg_noidx(tab[0], champ, cor->mem, &err);
  arg2 = get_dir_reg_arg(tab[1], champ, cor->mem, &err);
  if (err != -1 &&
      (tab[2][0] == 1 && check_reg(tab[2][2]) == 1) && tab[3][0] == 0)
    {
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    {
      champ->carry = 0;
      my_none(champ, cor);
    }
  ifree(tab, 4);
}
