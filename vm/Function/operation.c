/*
** operation.c for operation in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 18:52:51 2014 Thibaut Lopez
** Last update Sat Mar 29 14:49:08 2014 thibaud
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
  champ->pc += 5;
  ifree(tab, 4);
  return (5);
}

int	my_and(t_champ *champ, t_cor *cor)
{
  int	and;
  int	arg1;
  int	arg2;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  arg1 = get_all_type_arg(tab, 0, champ, cor->mem);
  arg2 = get_all_type_arg(tab, 1, champ, cor->mem);
  and = tab[0][1] + tab[1][1] + 3;
  if (arg1 != -1 && arg2 != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
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

  tab = get_encode(cor->mem, champ->pc);
  arg1 = get_all_type_arg(tab, 0, champ, cor->mem);
  arg2 = get_all_type_arg(tab, 1, champ, cor->mem);
  or = tab[0][1] + tab[1][1] + 3;
  if (arg1 != -1 && arg2 != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
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

  tab = get_encode(cor->mem, champ->pc);
  //print_encode(tab);
  arg1 = get_all_type_arg(tab, 0, champ, cor->mem);
  arg2 = get_all_type_arg(tab, 1, champ, cor->mem);
  xor = tab[0][1] + tab[1][1] + 3;
  if (arg1 != -1 && arg2 != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
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
  champ->pc += xor;
  ifree(tab, 4);
  return (xor);
}
