/*
** operation.c for operation in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 18:52:51 2014 Thibaut Lopez
** Last update Mon Mar 17 20:46:03 2014 thibaud
*/

#include "vm.h"
#include "my.h"

int	my_add(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][2] > 0 && tab[1][2] > 0)
    champ->reg[tab[2][2]] = 1;
  champ->carry = 1;
  my_putstr("add du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", ajout ", 1);
  my_putstr(" du registre ", 1);
  my_putnbr(tab[0][2], 1);
  my_putstr(" au registre ", 1);
  my_putnbr(tab[1][2], 1);
  my_putstr(" dans le registre ", 1);
  my_putnbr(tab[2][2], 1);
  my_putstr(", avance dans la mémoire de ", 1);
  my_putnbr(tab[0][1] + tab[1][1] + tab[2][1], 1);
  my_putchar('\n', 1);
  return (tab[0][1] + tab[1][1] + tab[2][1] + 1);
}

int	my_sub(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  my_putstr("add du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", soustraction ", 1);
  my_putstr(" du registre ", 1);
  my_putnbr(tab[0][2], 1);
  my_putstr(" au registre ", 1);
  my_putnbr(tab[1][2], 1);
  my_putstr(" dans le registre ", 1);
  my_putnbr(tab[2][2], 1);
  my_putstr(", avance dans la mémoire de ", 1);
  my_putnbr(tab[0][1] + tab[1][1] + tab[2][1], 1);
  my_putchar('\n', 1);
  return (tab[0][1] + tab[1][1] + tab[2][1] + 2);
}

int	my_and(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  my_putstr("add du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", andisation ", 1);
  if (tab[0][0] == 1)
    my_putstr(" du registre ", 1);
  else
    my_putstr((tab[0][0] == 2) ? " du direct " : " du indirect ", 1);
  my_putnbr(tab[0][2], 1);
  if (tab[0][0] == 1)
    my_putstr(" au registre ", 1);
  else
    my_putstr((tab[0][0] == 2) ? " au direct " : " au indirect ", 1);
  my_putnbr(tab[1][2], 1);
  my_putstr(" dans le registre ", 1);
  my_putnbr(tab[2][2], 1);
  my_putstr(", avance dans la mémoire de ", 1);
  my_putnbr(tab[0][1] + tab[1][1] + tab[2][1], 1);
  my_putchar('\n', 1);
  return (tab[0][1] + tab[1][1] + tab[2][1] + 2);
}

int	my_or(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  my_putstr("add du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", orisation ", 1);
  if (tab[0][0] == 1)
    my_putstr(" du registre ", 1);
  else
    my_putstr((tab[0][0] == 2) ? " du direct " : " du indirect ", 1);
  my_putnbr(tab[0][2], 1);
  if (tab[0][0] == 1)
    my_putstr(" au registre ", 1);
  else
    my_putstr((tab[0][0] == 2) ? " au direct " : " au indirect ", 1);
  my_putnbr(tab[1][2], 1);
  my_putstr(" dans le registre ", 1);
  my_putnbr(tab[2][2], 1);
  my_putstr(", avance dans la mémoire de ", 1);
  my_putnbr(tab[0][1] + tab[1][1] + tab[2][1], 1);
  my_putchar('\n', 1);
  return (tab[0][1] + tab[1][1] + tab[2][1] + 2);
}

int	my_xor(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  my_putstr("add du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", xorisation ", 1);
  if (tab[0][0] == 1)
    my_putstr(" du registre ", 1);
  else
    my_putstr((tab[0][0] == 2) ? " du direct " : " du indirect ", 1);
  my_putnbr(tab[0][2], 1);
  if (tab[0][0] == 1)
    my_putstr(" au registre ", 1);
  else
    my_putstr((tab[0][0] == 2) ? " au direct " : " au indirect ", 1);
  my_putnbr(tab[1][2], 1);
  my_putstr(" dans le registre ", 1);
  my_putnbr(tab[2][2], 1);
  my_putstr(", avance dans la mémoire de ", 1);
  my_putnbr(tab[0][1] + tab[1][1] + tab[2][1], 1);
  my_putchar('\n', 1);
  return (tab[0][1] + tab[1][1] + tab[2][1] + 2);
}
