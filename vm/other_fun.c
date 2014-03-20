/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
** Last update Thu Mar 20 18:40:21 2014 thibaud
*/

#include "vm.h"
#include "my.h"

int	my_st(t_champ *champ, t_cor *cor)
{
  int	case_mem;
  int	st;
  int	arg;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  st = tab[0][1] + tab[1][1] + tab[2][1] + tab[3][1] + 2;
  arg = get_all_type_arg(tab[1][0], tab[1][2], champ, cor->mem);
  case_mem = 0;
  if (arg != -1 && tab[1][0] != 1)
    case_mem = (tab[1][0] == 2) ? tab[1][2] : champ->pc + (tab[1][2] % IDX_MOD);
  if (arg != -1 && tab[0][2] > 0 && tab[0][2] <= REG_NUMBER &&
      case_mem >= 0 && case_mem < MEM_SIZE)
    {
      champ->carry = 1;
      if (tab[1][0] == 1)
	champ->reg[tab[1][2]] = champ->reg[tab[0][2]];
      else
	{
	  cor->mem[case_mem] = champ->reg[tab[0][2]];
	  change_case_mem(case_mem, champ->color, cor->screen);
	}
    }
  ifree(tab, 4);
  return (st);
}

int	my_sti(t_champ *champ, t_cor *cor)
{
  int	**tab;
  char	*tmp;

  tab = get_encode(cor->mem, champ->pc);

  aff_memdr(cor->mem);
  my_putstr("\n\n\n", 1);

  int	a, b;
  a = b = 0;
  my_putstr("\nENCODE = \n", 1);
  while (a < 4)
    {
      while (b < 3)
	{
	  my_putnbr(tab[a][b], 1);
	  my_putstr(" ", 1);
	  b++;
	}
      b = 0;
      a++;
      my_putstr("\n", 1);
    }
      my_putstr("\n", 1);

  if (tab[0][0] == 1 && tab[0][2] >= 0 && tab[0][2] <= REG_SIZE && (tab[1][0] != 0) && (tab[2][0] == 1 || tab[2][0] == 2))
    {
      my_putstr("Voici le REG 1 : ", 1);
      my_putnbr(champ->reg[0], 1);

      tmp = (char *)&champ->reg[tab[0][2] - 1];
      cor->mem[champ->pc + tab[1][2] + tab[2][2] + 3] = tmp[0];
      cor->mem[champ->pc + tab[1][2] + tab[2][2] + 2] = tmp[1];
      cor->mem[champ->pc + tab[1][2] + tab[2][2] + 1] = tmp[2];
      cor->mem[champ->pc + tab[1][2] + tab[2][2] + 0] = tmp[3];
    }
  else
    my_putstr("STI FAIL\n", 1);
  champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;

  aff_memdr(cor->mem);
  my_putstr("\n\n\n", 1);

  return (tab[0][1] + tab[1][1] + tab[2][1] + 2);
}

int	my_aff(t_champ *champ, t_cor *cor)
{
  int	aff;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  aff = tab[0][1] + tab[1][1] + tab[2][1] + tab[3][1] + 2;
  if (tab[0][2] > 0 && tab[0][2] <= REG_NUMBER)
    {
      champ->carry = 1;
      my_putchar(champ->reg[tab[0][2]], 1);
    }
  change_pos_pc(champ, champ->pc + aff, aff, cor->screen);
  ifree(tab, 4);
  return (aff);
}
