/*
** operation.c for operation in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 18:52:51 2014 Thibaut Lopez
** Last update Wed Apr  9 10:16:23 2014 Thibaut Lopez
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
      if (champ->champ_nb == 1)
	printf("ADD\n");
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = champ->reg[tab[0][2] - 1]
	+ champ->reg[tab[1][2] - 1];
      change_pos_pc(champ, champ->pc + 5, cor->screen);
      champ->pc += 5;
    }
  else
    {
      if (champ->champ_nb == 1)
	printf("ADD (fail)\n");
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
      if (champ->champ_nb == 1)
	printf("SUB\n");
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = champ->reg[tab[0][2] - 1] -
	champ->reg[tab[1][2] - 1];
      change_pos_pc(champ, champ->pc + 5, cor->screen);
      champ->pc += 5;
    }
  else
    {
      if (champ->champ_nb == 1)
	printf("SUB (fail)\n");
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
      if (champ->champ_nb == 1)
	printf("AND\n");
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = arg1 & arg2;
      change_pos_pc(champ, champ->pc + tab[0][1] + tab[1][1] + 3, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + 3;
    }
  else
    {
      if (champ->champ_nb == 1)
	printf("AND (fail)\n");
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
      if (champ->champ_nb == 1)
	printf("OR\n");
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = arg1 | arg2;
      change_pos_pc(champ, champ->pc + tab[0][1] + tab[1][1] + 3, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + 3;
    }
  else
    {
      if (champ->champ_nb == 1)
	printf("OR (fail)\n");
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
      if (champ->champ_nb == 1)
	printf("XOR\n");
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = arg1 ^ arg2;
      change_pos_pc(champ, champ->pc + tab[0][1] + tab[1][1] + 3, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + 3;
    }
  else
    {
      if (champ->champ_nb == 1)
	printf("XOR (fail)\n");
      my_none(champ, cor);
      champ->carry = 0;
    }
  ifree(tab, 4);
}
