/*
** operation.c for operation in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 18:52:51 2014 Thibaut Lopez
** Last update Fri Apr 11 17:20:20 2014 thibaud
*/

#include "vm.h"
#include "my.h"

void	my_add(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && tab[1][0] == 1 && tab[2][0] == 1 &&
      tab[3][0] == 0 && check_reg(tab[0][2]) == 1 &&
      check_reg(tab[1][2]) == 1 && check_reg(tab[2][2]) == 1)
    {
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = champ->reg[tab[0][2] - 1]
	+ champ->reg[tab[1][2] - 1];
      champ->pc += 5;
    }
  else
    {
      my_none(champ, cor);
      champ->carry = 0;
    }
  ifree(tab, 4);
}

void	my_sub(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && tab[1][0] == 1 && tab[2][0] == 1 &&
      tab[3][0] == 0 && check_reg(tab[0][2]) == 1 &&
      check_reg(tab[1][2]) == 1 && check_reg(tab[2][2]) == 1)
    {
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = champ->reg[tab[0][2] - 1] -
	champ->reg[tab[1][2] - 1];
      champ->pc += 5;
    }
  else
    {
      my_none(champ, cor);
      champ->carry = 0;
    }
  ifree(tab, 4);
}

void	my_and(t_champ *champ, t_cor *cor)
{
  int	arg1;
  int	arg2;
  int	err;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg1 = get_all_type_arg(tab[0], champ, cor->mem, &err);
  arg2 = get_all_type_arg(tab[1], champ, cor->mem, &err);
  if (err != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
      check_reg(tab[2][2]) == 1)
    {
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = arg1 & arg2;
      champ->pc += tab[0][1] + tab[1][1] + 3;
    }
  else
    {
      my_none(champ, cor);
      champ->carry = 0;
    }
  ifree(tab, 4);
}

void	my_or(t_champ *champ, t_cor *cor)
{
  int	arg1;
  int	arg2;
  int	**tab;
  int	err;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg1 = get_all_type_arg(tab[0], champ, cor->mem, &err);
  arg2 = get_all_type_arg(tab[1], champ, cor->mem, &err);
  if (err != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
      check_reg(tab[2][2]) == 1)
    {
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = arg1 | arg2;
      champ->pc += tab[0][1] + tab[1][1] + 3;
    }
  else
    {
      my_none(champ, cor);
      champ->carry = 0;
    }
  ifree(tab, 4);
}

void	my_xor(t_champ *champ, t_cor *cor)
{
  int	arg1;
  int	arg2;
  int	**tab;
  int	err;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg1 = get_all_type_arg(tab[0], champ, cor->mem, &err);
  arg2 = get_all_type_arg(tab[1], champ, cor->mem, &err);
  if (err != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
      check_reg(tab[2][2]) == 1)
    {
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = arg1 ^ arg2;
      champ->pc += tab[0][1] + tab[1][1] + 3;
    }
  else
    {
      my_none(champ, cor);
      champ->carry = 0;
    }
  ifree(tab, 4);
}
