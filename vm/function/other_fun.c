/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
** Last update Thu Apr 10 15:41:32 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

/*{
  my_printf(1, "\t(%X)", champ->pc);
  my_putstr("st ", 1);
  my_printf(1, (tab[0][0] == 1) ? "r%d," : "%d,", tab[0][2]);
  my_printf(1, "r%d\n", tab[1][2]);
  my_printf(1, "\t\treg[%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", champ->reg[0], champ->reg[1], champ->reg[2], champ->reg[3], champ->reg[4], champ->reg[5], champ->reg[6], champ->reg[7], champ->reg[8], champ->reg[9], champ->reg[10], champ->reg[11], champ->reg[12], champ->reg[13], champ->reg[14], champ->reg[15]);

  my_putstr("st ", 1);
  my_printf(1, (tab[0][0] == 1) ? "r%d," : "%d,", tab[0][2]);
  my_printf(1, "r%d (fail)\n", tab[1][2]);
}
{
  my_printf(1, "\t(%X)", champ->pc);
  my_printf(1, "sti r%d,", tab[0][2]);
  my_printf(1, (tab[1][0] == 1) ? "r%d," :
	    (tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
  my_printf(1, (tab[2][0] == 1) ? "r%d\n" : "%%%d\n", tab[2][2]);
  my_printf(1, "\t\ta %d -> %d    b %d -> %d\n", tab[1][2], a, tab[2][2], b);

  my_printf(1, "sti r%d,", tab[0][2]);
  my_printf(1, (tab[1][0] == 1) ? "r%d," :
	    (tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
  my_printf(1, (tab[2][0] == 1) ? "r%d (fail)\n" : "%%%d (fail)\n", tab[2][2]);
}
{
  my_printf(1, "\t(%X)", champ->pc);
  my_printf(1, "aff r%d\n", tab[0][2]);

  my_printf(1, "aff r%d (fail)\n", tab[0][2]);
  }*/

void	my_st(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if ((tab[0][0] == 1 && check_reg(tab[0][2]))
      && ((tab[1][0] == 1 && check_reg(tab[1][2])) || tab[1][0] == 3) &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      if (tab[0][0] == 1)
	champ->reg[tab[1][2]] = champ->reg[tab[0][2]];
      else
	{
	  print_on_mem(cor, champ->reg[tab[0][2] - 1], champ->pc + tab[1][2]);
	  change_case_mem(champ->pc + tab[1][2], champ->color, cor->screen);
	}
      champ->pc += tab[0][1] + tab[1][1] + 2;
    }
  else
    my_none(champ, cor);
  ifree(tab, 4);
}

void	my_sti(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	a;
  int	b;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2])
      && (tab[1][0] > 1 || (tab[1][0] == 1 && check_reg(tab[1][2])))
      && ((tab[2][0] == 1 && check_reg(tab[2][2])) || tab[2][0] == 2) &&
      tab[3][0] == 0)
    {
      a = (tab[1][0] == 1) ? champ->reg[tab[1][2] - 1] : tab[1][2];
      b = (tab[2][0] == 1) ? champ->reg[tab[2][2] - 1] : tab[2][2];
      print_on_mem(cor, champ->reg[tab[0][2] - 1], a + b);
      change_case_mem(a + b, champ->color, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    my_none(champ, cor);
  ifree(tab, 4);
}

void	my_aff(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2]) && tab[1][0] == 0 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      champ->carry = 1;
      my_putchar(champ->reg[tab[0][2]] % 256, 1);
      champ->pc += 6;
    }
  else
    my_none(champ, cor);
  ifree(tab, 4);
}
