/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
** Last update Thu Mar 20 15:24:02 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	my_st(t_champ *champ, t_cor *cor)
{
  int	case_mem;
  int	st;
  int	arg;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc, &st);
  arg = get_arg(tab[1][0], tab[1][2], champ, cor->mem);
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
  change_pos_pc(champ, champ->pc + st, st, cor->screen);
  ifree(tab, 4);
  return (st);
}

int	my_sti(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	tmp;
  int	i;
  int	sti;
  int	oct_size;

  oct_size = 256;
  i = 0;
  tab = get_encode(cor->mem, champ->pc, &sti);
  if (tab[0][0] == 1 && tab[0][2] >= 0 && tab[0][2] <= REG_SIZE && (tab[1][0] != 0) && (tab[2][0] == 1 || tab[2][0] == 2))
    {
      my_putstr("Voici le REG 1 : ", 1);
      my_putnbr(champ->reg[0], 1);
      my_putstr("\nIl y dans la mémoire : ", 1);
      my_putnbr((int)cor->mem[champ->pc + 1], 1);
      my_putstr("  ", 1);
      my_putnbr((int)cor->mem[champ->pc + 2], 1);
      my_putstr("  ", 1);
      my_putnbr((int)cor->mem[champ->pc + 3], 1);
      my_putstr("  ", 1);
      my_putnbr((int)cor->mem[champ->pc + 4], 1);
      my_putstr("  ", 1);
      my_putnbr((int)cor->mem[champ->pc + 5], 1);
      my_putstr("  ", 1);
      my_putnbr((int)cor->mem[champ->pc + 6], 1);
      my_putstr("  ", 1);
      my_putnbr((int)cor->mem[champ->pc + 7], 1);
      my_putstr("  ", 1);
      my_putnbr((int)cor->mem[champ->pc + 8], 1);
      my_putstr("  ", 1);
      my_putnbr((int)cor->mem[champ->pc + 9], 1);
      my_putstr("  ", 1);
      my_putnbr((int)cor->mem[champ->pc + 10], 1);
      my_putstr("  ", 1);
      my_putnbr((int)cor->mem[champ->pc + 11], 1);
      my_putstr("  ", 1);
      my_putnbr((int)cor->mem[champ->pc + 12], 1);
      my_putstr("  ", 1);
      my_putstr("\n", 1);
      tmp = tab[0][2];
      while (i < 4)
	{
	  if (i - 3 == 0)
	    tmp = (tab[0][2] % (oct_size * i));
	  else if (i == 0)
	    tmp = (tab[0][2] / (oct_size * (3 - i))); 
	  else
	    tmp = (tab[0][2] / (oct_size * (3 - i))) %(oct_size * i); 
	  cor->mem[tab[1][2] + tab[2][2] + i] = (unsigned char)tmp;
	  i++;
	}
      my_putstr("sti du champion : ", 1);
      my_putstr(champ->head->prog_name, 1);
      my_putstr(", utilisation ", 1);
      my_putstr(" du registre ", 1);
      my_putnbr(tab[0][2], 1);
      if (tab[1][0] == 1)
	my_putstr(" au registre ", 1);
      else
	my_putstr((tab[1][0] == 2) ? " au direct " : " au indirect ", 1);
      my_putnbr(tab[1][2], 1);
      my_putstr(" plus", 1);
      if (tab[2][0] == 1)
	my_putstr(" le registre ", 1);
      else
	my_putstr((tab[2][0] == 2) ? " le direct " : " le indirect ", 1);
      my_putnbr(tab[2][2], 1);
      my_putstr(", avance dans la mémoire de ", 1);
      my_putnbr(tab[0][1] + tab[1][1] + tab[2][1], 1);
      my_putchar('\n', 1);
    }
  champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 1;
  return (tab[0][1] + tab[1][1] + tab[2][1] + 1);
}

int	my_aff(t_champ *champ, t_cor *cor)
{
  int	aff;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc, &aff);
  if (tab[0][2] > 0 && tab[0][2] <= REG_NUMBER)
    {
      champ->carry = 1;
      my_putchar(champ->reg[tab[0][2]], 1);
    }
  change_pos_pc(champ, champ->pc + aff, aff, cor->screen);
  ifree(tab, 4);
  return (aff);
}
