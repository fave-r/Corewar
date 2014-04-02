/*
** operation.c for operation in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 18:52:51 2014 Thibaut Lopez
** Last update Wed Apr  2 16:52:14 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	my_add(t_champ *champ, t_cor *cor)
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
    }
  else
    {
      printf("ADD FAIL\n");
    champ->carry = 0;
    }
  change_pos_pc(champ, champ->pc + 5, 5, cor->screen);
  champ->pc += 5;
  ifree(tab, 4);
  return (5);
}

int	my_sub(t_champ *champ, t_cor *cor)
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
    }
  else
    {
      printf("SUB FAIL\n");
    champ->carry = 0;
    }
  change_pos_pc(champ, champ->pc + 5, 5, cor->screen);
  champ->pc += 5;
  ifree(tab, 4);
  return (5);
}

int	my_and(t_champ *champ, t_cor *cor)
{
  int	and;
  int	arg1;
  int	arg2;
  int	err;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg1 = get_all_type_arg(tab[0], champ, cor->mem, &err);
  arg2 = get_all_type_arg(tab[1], champ, cor->mem, &err);
  and = tab[0][1] + tab[1][1] + 3;
  if (err != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
      check_reg(tab[2][2]) == 1)
    {
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = arg1 & arg2;
    }
  else
    {
      printf("AND FAIL\n");
      champ->carry = 0;
    }
  change_pos_pc(champ, champ->pc + and, and, cor->screen);
  champ->pc += and;
  ifree(tab, 4);
  return (and);
}

int	my_or(t_champ *champ, t_cor *cor)
{
  int	or;
  int	arg1;
  int	arg2;
  int	**tab;
  int	err;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg1 = get_all_type_arg(tab[0], champ, cor->mem, &err);
  arg2 = get_all_type_arg(tab[1], champ, cor->mem, &err);
  or = tab[0][1] + tab[1][1] + 3;
  if (err != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
      check_reg(tab[2][2]) == 1)
    {
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = arg1 | arg2;
    }
  else
    {
      printf("OR FAIL\n");
      champ->carry = 0;
    }
  change_pos_pc(champ, champ->pc + or, or, cor->screen);
  champ->pc += or;
  ifree(tab, 4);
  return (or);
}

int	my_xor(t_champ *champ, t_cor *cor)
{
  int	xor;
  int	arg1;
  int	arg2;
  int	**tab;
  int	err;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg1 = get_all_type_arg(tab[0], champ, cor->mem, &err);
  arg2 = get_all_type_arg(tab[1], champ, cor->mem, &err);
  xor = tab[0][1] + tab[1][1] + 3;
  if (err != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
      check_reg(tab[2][2]) == 1)
    {
      champ->carry = 1;
      if (tab[0][0] == 3)
	aff_memdr(cor->mem);
      champ->reg[tab[2][2] - 1] = arg1 ^ arg2;
    }
  else
    {
      printf("XOR FAIL\n");
      champ->carry = 0;
    }
  change_pos_pc(champ, champ->pc + xor, xor, cor->screen);
  champ->pc += xor;
  ifree(tab, 4);
  return (xor);
}
