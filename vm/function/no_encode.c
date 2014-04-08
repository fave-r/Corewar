/*
** no_encode.c for no_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 12:05:37 2014 Thibaut Lopez
** Last update Tue Apr  8 15:04:46 2014 Thibaut Lopez
*/

#include "my.h"
#include "vm.h"

int	find_champ(t_cor *cor, int direct_arg)
{
  int	j;
  int	i;

  i = 0;
  j = -1;
  while (i < 4)
    {
      if (cor->champs_nb[i] == direct_arg)
	j = i;
      i++;
    }
  return (j);
}

void	my_live(t_champ *champ, t_cor *cor)
{
  int	i;
  int	j;
  int	direct_arg;

  direct_arg = get_nbr_action(cor->mem, champ->pc + 1, 4);
  j = find_champ(cor, direct_arg);
  if (j != -1)
    {
      i = 0;
      while (i++ < 4)
	if (cor->live[i - 1] == 2)
	  cor->live[i - 1] = 1;
      cor->live[j] = 2;
      i = 0;
      while (i++ < 4)
	if (cor->live[i - 1] == 2)
	  cor->live[i - 1] = 1;
      cor->live[j] = 2;
      cor->live_done++;
      change_pos_pc(champ, champ->pc + 5, cor->screen);
      champ->pc += 5;
    }
  else
    my_none(champ, cor);
}

void	my_zjmp(t_champ *champ, t_cor *cor)
{
  int	direct_arg;

  if (champ->carry == 1)
    {
      direct_arg = get_nbr_action(cor->mem, champ->pc + 1, 2);
      change_pos_pc(champ, champ->pc + direct_arg, cor->screen);
      champ->pc += direct_arg;
    }
  else
    my_none(champ, cor);
}

void	my_none(t_champ *champ, t_cor *cor)
{
  change_pos_pc(champ, champ->pc + 1, cor->screen);
  champ->pc++;
}
