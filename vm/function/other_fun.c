/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
** Last update Wed Apr  9 10:17:33 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

void	my_st(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if ((tab[0][0] == 1 && check_reg(tab[0][2]))
      && ((tab[1][0] == 1 && check_reg(tab[1][2])) || tab[1][0] == 3) &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      if (champ->champ_nb == 1)
	printf("ST\n");
      if (tab[1][0] == 1)
	champ->reg[tab[1][2]] = champ->reg[tab[0][2]];
      else
	{
	  print_on_mem(cor, champ->reg[tab[0][2] - 1], champ->pc + tab[1][2]);
	  change_case_mem(champ->pc + tab[1][2], champ->color, cor->screen);
	}
      change_pos_pc(champ, champ->pc + tab[0][1] + tab[1][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + 2;
    }
  else
    {
      if (champ->champ_nb == 1)
	printf("ST (fail)\n");
      my_none(champ, cor);
    }
  ifree(tab, 4);
}

void	my_sti(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2])
      && (tab[1][0] > 1 || (tab[1][0] == 1 && check_reg(tab[1][2])))
      && ((tab[2][0] == 1 && check_reg(tab[2][2])) || tab[2][0] == 2) &&
      tab[3][0] == 0)
    {
      if (champ->champ_nb == 1)
	printf("STI\n");
      print_on_mem(cor, champ->reg[tab[0][2] - 1],
		   champ->pc + tab[1][2] + tab[2][2]);
      change_case_mem(champ->pc + tab[1][2] + tab[2][2],
		      champ->color, cor->screen);
      change_pos_pc(champ,
		    champ->pc + tab[0][1] + tab[1][1] + tab[2][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    {
      if (champ->champ_nb == 1)
	printf("STI (fail)\n");
      my_none(champ, cor);
    }
  ifree(tab, 4);
}

void	my_aff(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2]) && tab[1][0] == 0 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      if (champ->champ_nb == 1)
	printf("AFF\n");
      champ->carry = 1;
      my_putchar(champ->reg[tab[0][2]] % 256, 1);
      change_pos_pc(champ, champ->pc + 6, cor->screen);
      champ->pc += 6;
    }
  else
    {
      if (champ->champ_nb == 1)
	printf("AFF (fail)\n");
      my_none(champ, cor);
    }
  ifree(tab, 4);
}
