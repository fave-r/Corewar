/*
** no_encode.c for no_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 12:05:37 2014 Thibaut Lopez
** Last update Mon Mar 17 14:23:06 2014 thibaud
*/

#include "my.h"
#include "vm.h"

int	my_live(t_champ *champ, t_cor *cor)
{
  int	live;
  int	i;
  int	j;
  int	direct_arg;
  int	**encode;

  i = 0;
  j = -1;
  direct_arg = get_nbr_action(cor->mem, champ->pc + 1, 4);
  while (i++ < 4)
    {
      if (cor->champ->nb[i - 1] == direct_arg)
	j = i - 1;
    }
  if (j != -1)
    {
	  my_putstr("live du champion : ", 1);
	  my_putstr(champ->head->prog_name, 1);
	  my_putstr(", pour le numéro : ", 1);
	  my_putnbr(, 1);
	  cor->live_done++;
	  i = 0;
	  while (i++ < 4)
	    if (cor->live[i - 1] == 2)
	      cor->live[i - 1] = 1;
	  cor->live[j] = 2;
    }
  my_putstr(", avance dans la mémoire de 5\n", 1);
  champ->pc += 5;
  return (5);
}

int	my_zjmp(t_champ *champ, t_cor *cor)
{
  int	jump;

  my_putstr("zjmp du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", vers le numéro : ", 1);
  jump = get_nbr_action(cor->mem, champ->pc, 2);
  my_putnbr(jump, 1);
  my_putstr(", avance dans la mémoire de 2\n", 1);
  return (3);
}

int	my_fork(t_champ *champ, t_cor *cor)
{
  int	frk;

  my_putstr("fork du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", vers le numéro : ", 1);
  frk = get_nbr_action(cor->mem, champ->pc, 2);
  my_putnbr(frk, 1);
  my_putstr(", avance dans la mémoire de 2\n", 1);
  return (3);
}

int	my_lfork(t_champ *champ, t_cor *cor)
{
  int	frk;

  my_putstr("lfork du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", vers le numéro : ", 1);
  frk = get_nbr_action(cor->mem, champ->pc, 2);
  my_putnbr(frk, 1);
  my_putstr(", avance dans la mémoire de 2\n", 1);
  return (3);
}
