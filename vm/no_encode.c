/*
** no_encode.c for no_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 12:05:37 2014 Thibaut Lopez
** Last update Fri Mar 21 18:56:18 2014 Thibaut Lopez
** Last update Fri Mar 21 09:23:42 2014 Thibaut Lopez
*/

#include "my.h"
#include "vm.h"

int	my_live(t_champ *champ, t_cor *cor)
{
  int	i;
  int	j;
  int	direct_arg;

  my_printf(1, "Compteur de live = %d\n", cor->live_done);
  my_printf(1, "Compteur de cycle = %d\n", cor->cycle);
  i = 0;
  j = -1;
  direct_arg = get_nbr_action(cor->mem, champ->pc + 1, 4);
  while (i < 4)
    {
      if (cor->champs_nb[i] == direct_arg)
	j = i;
      i++;
    }
  if (j != -1)
    {
      i = 0;
      while (i++ < 4)
	if (cor->live[i - 1] == 2)
	  cor->live[i - 1] = 1;
      cor->live[j] = 2;
      my_printf(1, "Live du champion %s pour le champion numéro %d\n", champ->head->prog_name, direct_arg);
      i = 0;
      while (i++ < 4)
	if (cor->live[i - 1] == 2)
	  cor->live[i - 1] = 1;
      cor->live[j] = 2;
      cor->live_done++;
    }
  else
    my_putstr("Live ECHEC\n", 1);
  my_putstr(", avance dans la mémoire de 5\n", 1);
  champ->pc += 5;

  my_printf(1, "Num live = %d %d %d %d\n", cor->live[0], cor->live[1], cor->live[2], cor->live[3]);

  return (5);
}

int	my_zjmp(t_champ *champ, t_cor *cor)
{
  int	direct_arg;

  if (champ->carry == 1)
    {
      direct_arg = get_nbr_action(cor->mem, champ->pc + 1, 2);

      my_printf(1, "ZJMP du champion %s de %d cases.\n", champ->head->prog_name, direct_arg);
      champ->pc += direct_arg;
    }
  else
    my_putstr("ECHEC DE JUMP car carry = 0", 1);
  return (3);
}

int	my_fork(t_champ *champ, t_cor *cor)
{
  int	frk;

  my_putstr("fork du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", vers le numéro : ", 1);
  frk = get_nbr_action(cor->mem, champ->pc + 1, 2);
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
  frk = get_nbr_action(cor->mem, champ->pc + 1, 2);
  my_putnbr(frk, 1);
  my_putstr(", avance dans la mémoire de 2\n", 1);
  return (3);
}

int	my_none(t_champ *champ, t_cor *cor)
{
  (void)cor;
  my_printf(1, "NONE du champion %s\n", champ->head->prog_name);
  my_putstr("Avance dans la mémoire de 1\n", 1);
  champ->pc++;
  return (0);
}
