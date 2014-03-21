/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
** Last update Fri Mar 21 16:00:48 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	my_st(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	st;

  tab = get_encode(cor->mem, champ->pc);
  if ((tab[0][0] == 1 && check_reg(tab[0][2]))
      && ((tab[1][0] == 1 && check_reg(tab[1][2])) || tab[1][0] == 3))
    {
      if (tab[1][0] == 1)
	champ->reg[tab[1][2]] = champ->reg[tab[0][2]];
      else
	print_on_mem(cor, champ->reg[tab[0][1] - 1], champ->pc + tab[1][2]);
      my_printf(1, "ST du champion %s\n", champ->head->prog_name);
      st = tab[0][1] + tab[1][1] + 2;
    }
  else
    {
      st = 4;
      my_putstr("ST FAIL\n", 1);
    }
  champ->pc += tab[0][1] + tab[1][1] + 2;
  return (st);
}

int	my_sti(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	sti;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2])
      && (tab[1][0] > 1 || (tab[1][0] == 1 && check_reg(tab[1][2])))
      && ((tab[2][0] == 1 && check_reg(tab[2][2]))|| tab[2][0] == 2))
    {
      print_on_mem(cor, champ->reg[tab[0][1] - 1],
		   champ->pc + tab[1][2] + tab[2][2]);
      my_printf(1, "STI du champion %s\n", champ->head->prog_name);
      sti = tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    {
      sti = 6;
      my_putstr("STI FAIL\n", 1);
    }
  champ->pc += sti;
  return (sti);
}

int	my_aff(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2]))
    {
      champ->carry = 1;
      my_putchar(champ->reg[tab[0][2] - 1] % 256, 1);
    }
  champ->pc += 6;
  return (6);
}
