/*
** ld_fun.c for ld in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:11:21 2014 Thibaut Lopez
** Last update Fri Mar 21 17:40:58 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	my_ld(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	ld;
  int	arg;

  tab = get_encode(cor->mem, champ->pc);
  arg = get_dir_ind_arg(tab[0][0], tab[0][2], champ, cor->mem);
  if (tab[0][0] == 3)
    aff_memdr(cor->mem);
  if (arg != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1)
    {
      champ->carry = 1;
      champ->reg[tab[1][2] - 1] = arg;
      ld = tab[0][1] + tab[1][1] + 2;
      my_printf(1, "LD du champion %s, load la valeur %d dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, arg, tab[1][2], ld);
    }
  else
    {
      ld = 5;
      champ->carry = 0;
    }
  champ->pc += ld;
  return (ld);
}

int	my_ldi(t_champ *champ, t_cor *cor)
{
  int	**tab;
  //char	tmp[4];

  tab = get_encode(cor->mem, champ->pc);

  if (tab[0][0] != 0 &&
      ((tab[1][0] == 1 && check_reg(tab[1][2])) || tab[1][0] == 2)
      && (tab[2][0] == 1) && check_reg(tab[2][2]))
    {
      champ->carry = 1;
      if (tab[0][0] == 1)
	champ->reg[tab[1][2]] = champ->reg[tab[0][2]];
      else
	{
	  //tmp = cor->mem + champ->pc + 1 + tab[0][2];
	  //champ->reg[tab[1][2]] = (int)tmp;
	}
      my_printf(1, "LDI du champion %s\n", champ->head->prog_name);
    }
  champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
  return (tab[0][1] + tab[1][1] + tab[2][1] + 2);
}

int	my_lld(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  my_putstr("lld du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", lload ", 1);
  if (tab[0][0] == 1)
    my_putstr(" du registre ", 1);
  else
    my_putstr((tab[0][0] == 2) ? " du direct " : " du indirect ", 1);
  my_putnbr(tab[0][2], 1);
  my_putstr(" dans le registre ", 1);
  my_putnbr(tab[1][2], 1);
  my_putstr(", avance dans la mémoire de ", 1);
  my_putnbr(tab[0][1] + tab[1][1], 1);
  my_putchar('\n', 1);
  return (tab[0][1] + tab[1][1] + 2);
}

int	my_lldi(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  my_putstr("lldi du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", lldisation ", 1);
  if (tab[0][0] == 1)
    my_putstr(" du registre ", 1);
  else
    my_putstr((tab[0][0] == 2) ? " du direct " : " du indirect ", 1);
  my_putnbr(tab[0][2], 1);
  if (tab[1][0] == 1)
    my_putstr(" au registre ", 1);
  else
    my_putstr((tab[1][0] == 2) ? " au direct " : " au indirect ", 1);
  my_putnbr(tab[1][2], 1);
  my_putstr(" dans le registre ", 1);
  my_putnbr(tab[2][2], 1);
  my_putstr(", avance dans la mémoire de ", 1);
  my_putnbr(tab[0][1] + tab[1][1] + tab[2][1], 1);
  my_putchar('\n', 1);
  return (tab[0][1] + tab[1][1] + tab[2][1] + 2);
}
