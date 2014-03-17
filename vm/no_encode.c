/*
** no_encode.c for no_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 12:05:37 2014 Thibaut Lopez
** Last update Sat Mar 15 17:43:03 2014 thibaud
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

  encode = get_encode(cor->mem, champ->pc);

  i = 0;
  j = -1;
  while (i++ < 4)
    {
      if (cor->champs->nb[i - 1] == direct_arg)
	j = i - 1;
    }
  if (j != -1)
    {
      if (j != -1)
	{
	  my_putstr("live du champion : ", 1);
	  my_putstr(champ->head->prog_name, 1);
	  my_putstr(", pour le numéro : ", 1);
	  my_putnbr(cor->direct_arg, 1);
	  cor->live_done++;
	  i = 0;
	  while (i++ < 4)
	    if (cor->live[i - 1] == 2)
	      cor->live[i - 1] = 1;
	  cor->live[j] = 2;
	}
    }

  my_putstr(", avance dans la mémoire de 4\n", 1); //T'es sur que c'est 6 plutot? 4 octets pour le label "live" + 2 octets du T_DIR
  champ->pc += 6;
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
