/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
** Last update Fri Mar 21 12:04:56 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	my_st(t_champ *champ, t_cor *cor)
{
  int	**tab;
  char	*tmp;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && tab[0][2] >= 0 && tab[0][2] <= REG_SIZE
      && (tab[1][0] == 1 || tab[1][0] == 3) && tab[1][2] >= 0
      && tab[1][2] <= REG_SIZE)
    {
      if (tab[1][0] == 1)
	champ->reg[tab[1][2]] = champ->reg[tab[0][2]];
      else
	{
	  tmp = (char *)&champ->reg[tab[0][2] - 1];
	  cor->mem[champ->pc + tab[1][2] + 3] = tmp[0];
	  cor->mem[champ->pc + tab[1][2] + 2] = tmp[1];
	  cor->mem[champ->pc + tab[1][2] + 1] = tmp[2];
	  cor->mem[champ->pc + tab[1][2] + 0] = tmp[3];
	}
      my_printf(1, "ST du champion %s\n", champ->head->prog_name);
    }
  else
    my_putstr("ST FAIL\n", 1);
  champ->pc += tab[0][1] + tab[1][1] + 2;
  return (tab[0][1] + tab[1][1] + 2);
}

int	my_sti(t_champ *champ, t_cor *cor)
{
  int	**tab;
  char	*tmp;

  tab = get_encode(cor->mem, champ->pc);
  aff_memdr(cor->mem);
  my_putstr("\n\n", 1);
  print_encode(tab);
  if (tab[0][0] == 1 && tab[0][2] >= 0 && tab[0][2] <= REG_SIZE
      && tab[1][0] != 0 && (tab[2][0] == 1 || tab[2][0] == 2))
    {
      tmp = (char *)&champ->reg[tab[0][2] - 1];
      cor->mem[champ->pc + tab[1][2] + tab[2][2] + 3] = tmp[0];
      cor->mem[champ->pc + tab[1][2] + tab[2][2] + 2] = tmp[1];
      cor->mem[champ->pc + tab[1][2] + tab[2][2] + 1] = tmp[2];
      cor->mem[champ->pc + tab[1][2] + tab[2][2] + 0] = tmp[3];
      my_printf(1, "STI du champion %s\n", champ->head->prog_name);
    }
  else
    my_putstr("STI FAIL\n", 1);
  champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
  aff_memdr(cor->mem);
  my_putstr("\n\n", 1);
  return (tab[0][1] + tab[1][1] + tab[2][1] + 2);
}

int	my_aff(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && tab[0][2] >= 0 && tab[0][2] <= REG_NUMBER)
    {
      champ->carry = 1;
      my_putchar(champ->reg[tab[0][2]] % 256, 1);
    }
  champ->pc += 6;
  return (6);
}
