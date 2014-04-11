/*
** operation.c for operation in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 18:52:51 2014 Thibaut Lopez
** Last update Thu Apr 10 15:51:59 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

/*{
  my_printf(1, "\t(%X)", champ->pc);
  my_printf(1, "add r%d, r%d, r%d\n", tab[0][2], tab[1][2], tab[2][2]);
  my_printf(1, "\t\treg[%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", champ->reg[0], champ->reg[1], champ->reg[2], champ->reg[3], champ->reg[4], champ->reg[5], champ->reg[6], champ->reg[7], champ->reg[8], champ->reg[9], champ->reg[10], champ->reg[11], champ->reg[12], champ->reg[13], champ->reg[14], champ->reg[15]);

  my_printf(1, "add r%d, r%d, r%d (fail)\n", tab[0][2], tab[1][2], tab[2][2]);
}
{
  my_printf(1, "\t(%X)", champ->pc);
  my_printf(1, "sub r%d, r%d, r%d\n", tab[0][2], tab[1][2], tab[2][2]);
  my_printf(1, "\t\treg[%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", champ->reg[0], champ->reg[1], champ->reg[2], champ->reg[3], champ->reg[4], champ->reg[5], champ->reg[6], champ->reg[7], champ->reg[8], champ->reg[9], champ->reg[10], champ->reg[11], champ->reg[12], champ->reg[13], champ->reg[14], champ->reg[15]);

  my_printf(1, "sub r%d, r%d, r%d (fail)\n", tab[0][2], tab[1][2], tab[2][2]);
}

{
  my_printf(1, "\t(%X)", champ->pc);
  my_putstr("and ", 1);
  my_printf(1, (tab[0][0] == 1) ? "r%d," :
	    (tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
  my_printf(1, (tab[1][0] == 1) ? "r%d," :
	    (tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
  my_printf(1, "r%d\n", tab[2][2]);
  my_printf(1, "\t\treg[%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", champ->reg[0], champ->reg[1], champ->reg[2], champ->reg[3], champ->reg[4], champ->reg[5], champ->reg[6], champ->reg[7], champ->reg[8], champ->reg[9], champ->reg[10], champ->reg[11], champ->reg[12], champ->reg[13], champ->reg[14], champ->reg[15]);

  my_putstr("and ", 1);
  my_printf(1, (tab[0][0] == 1) ? "r%d," :
	    (tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
  my_printf(1, (tab[1][0] == 1) ? "r%d," :
	    (tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
  my_printf(1, "r%d (fail)\n", tab[2][2]);
}
{
  my_printf(1, "\t(%X)", champ->pc);
  my_putstr("or ", 1);
  my_printf(1, (tab[0][0] == 1) ? "r%d," :
	    (tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
  my_printf(1, (tab[1][0] == 1) ? "r%d," :
	    (tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
  my_printf(1, "r%d\n", tab[2][2]);
  my_printf(1, "\t\treg[%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", champ->reg[0], champ->reg[1], champ->reg[2], champ->reg[3], champ->reg[4], champ->reg[5], champ->reg[6], champ->reg[7], champ->reg[8], champ->reg[9], champ->reg[10], champ->reg[11], champ->reg[12], champ->reg[13], champ->reg[14], champ->reg[15]);

  my_putstr("or ", 1);
  my_printf(1, (tab[0][0] == 1) ? "r%d," :
	    (tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
  my_printf(1, (tab[1][0] == 1) ? "r%d," :
	    (tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
  my_printf(1, "r%d (fail)\n", tab[2][2]);
}
{
  my_printf(1, "\t(%X)", champ->pc);
  my_putstr("xor ", 1);
  my_printf(1, (tab[0][0] == 1) ? "r%d," :
	    (tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
  my_printf(1, (tab[1][0] == 1) ? "r%d," :
	    (tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
  my_printf(1, "r%d\n", tab[2][2]);
  my_printf(1, "\t\treg[%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", champ->reg[0], champ->reg[1], champ->reg[2], champ->reg[3], champ->reg[4], champ->reg[5], champ->reg[6], champ->reg[7], champ->reg[8], champ->reg[9], champ->reg[10], champ->reg[11], champ->reg[12], champ->reg[13], champ->reg[14], champ->reg[15]);

  my_putstr("xor ", 1);
  my_printf(1, (tab[0][0] == 1) ? "r%d," :
	    (tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
  my_printf(1, (tab[1][0] == 1) ? "r%d," :
	    (tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
  my_printf(1, "r%d (fail)\n", tab[2][2]);
}*/

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
