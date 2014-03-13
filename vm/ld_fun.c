/*
** ld_fun.c for ld in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:11:21 2014 Thibaut Lopez
** Last update Thu Mar 13 10:35:03 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	my_ld(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  my_putstr("ld du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", load ", 1);
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

int	my_ldi(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  my_putstr("ldi du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", ldisation ", 1);
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
