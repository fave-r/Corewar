/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
** Last update Tue Mar 25 17:30:10 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	my_st(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if ((tab[0][0] == 1 && check_reg(tab[0][2]))
      && ((tab[1][0] == 1 && check_reg(tab[1][2])) || tab[1][0] == 3) &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      if (tab[1][0] == 1)
	champ->reg[tab[1][2]] = champ->reg[tab[0][2]];
      else
	print_on_mem(cor, champ->reg[tab[0][2] - 1], champ->pc + tab[1][2]);
    }
  else
    my_putstr("ST FAIL\n", 1);
  champ->pc += tab[0][1] + tab[1][1] + 2;
  return (tab[0][1] + tab[1][1] + 2);
}

int	my_sti(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2])
      && (tab[1][0] > 1 || (tab[1][0] == 1 && check_reg(tab[1][2])))
      && ((tab[2][0] == 1 && check_reg(tab[2][2])) || tab[2][0] == 2) &&
      tab[3][0] == 0)
    {
      print_on_mem(cor, champ->reg[tab[0][2] - 1],
		   champ->pc + tab[1][2] + tab[2][2]);
    }
  else
    my_putstr("STI FAIL\n", 1);
  champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
  return (tab[0][1] + tab[1][1] + tab[2][1] + 2);
}

int	my_aff(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2]) && tab[1][0] == 0 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      champ->carry = 1;
      my_putchar(champ->reg[tab[0][2]] % 256, 1);
    }
  champ->pc += 6;
  return (6);
}
