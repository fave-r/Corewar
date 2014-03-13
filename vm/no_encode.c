/*
** no_encode.c for no_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 12:05:37 2014 Thibaut Lopez
** Last update Thu Mar 13 13:55:45 2014 thibaud
*/

#include "my.h"
#include "vm.h"

int	my_live(t_champ *champ, t_cor *cor)
{
  int	live;

  my_putstr("live du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", pour le numéro : ", 1);
  live = get_nbr_action(cor->mem, champ->pc, 8);
  my_putnbr(live, 1);
  my_putstr(", avance dans la mémoire de 8\n", 1);
  return (9);
}

int	my_zjmp(t_champ *champ, t_cor *cor)
{
  int	jump;

  my_putstr("zjmp du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", vers le numéro : ", 1);
  jump = get_nbr_action(cor->mem, champ->pc, 4);
  my_putnbr(jump, 1);
  my_putstr(", avance dans la mémoire de 4\n", 1);
  return (5);
}

int	my_fork(t_champ *champ, t_cor *cor)
{
  int	frk;

  my_putstr("fork du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", vers le numéro : ", 1);
  frk = get_nbr_action(cor->mem, champ->pc, 4);
  my_putnbr(frk, 1);
  my_putstr(", avance dans la mémoire de 4\n", 1);
  return (5);
}

int	my_lfork(t_champ *champ, t_cor *cor)
{
  int	frk;

  my_putstr("lfork du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", vers le numéro : ", 1);
  frk = get_nbr_action(cor->mem, champ->pc, 4);
  my_putnbr(frk, 1);
  my_putstr(", avance dans la mémoire de 4\n", 1);
  return (5);
}
