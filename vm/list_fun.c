/*
** list_fun.c for list_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Sun Mar  2 12:45:35 2014 Thibaut Lopez
** Last update Sun Mar  2 13:29:38 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"
#include <stdio.h>

int	my_list_len(t_champ *champ)
{
  int		i;
  t_champ	*tmp;

  i = 1;
  tmp = champ->next;
  while (tmp != champ)
    {
      tmp = tmp->next;
      i++;
    }
  return (i);
}

void	good_adress(t_champ *champ)
{
  int		i;
  int		j;
  int		addr;
  t_champ	*tmp;

  tmp = champ->next;
  while (tmp != champ)
    {
      i = champ->adress;
      j = 0;
      addr = tmp->adress;
      while (i != addr)
	{
	  i = (i + 1) % MEM_SIZE;
	  j++;
	}
      if (j < champ->head->prog_size)
	{
	  my_putstr(champ->path, 2);
	  my_putstr(ER_SIZE, 2);
	  exit(1);
	}
      tmp = tmp->next;
    }
}

void	check_adress(t_champ *champ)
{
  t_champ	*tmp;

  if (champ->next == champ)
    return;
  tmp = champ;
  good_adress(tmp);
  tmp = tmp->next;
  while (tmp != champ)
    {
      good_adress(tmp);
      tmp = tmp->next;
    }
}

void	init_adress(t_champ *champ)
{
  int		i;
  int		len;
  t_champ	*tmp;

  i = 0;
  len = my_list_len(champ);
  tmp = champ;
  if (tmp->adress == -1)
    tmp->adress = (MEM_SIZE / len) * i;
  printf("%d", tmp->adress);
  i++;
  tmp = tmp->next;
  while (tmp != champ)
    {
      if (tmp->adress == -1)
	tmp->adress = (MEM_SIZE / len) * i;
      printf(" %d", tmp->adress);
      i++;
      tmp = tmp->next;
    }
  printf("\n");
  check_adress(champ);
}
