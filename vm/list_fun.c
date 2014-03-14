/*
** list_fun.c for list_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Sun Mar  2 12:45:35 2014 Thibaut Lopez
** Last update Fri Mar 14 08:41:03 2014 Thibaut Lopez
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
      i = champ->pc;
      j = 0;
      addr = tmp->pc;
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
  if (tmp->pc == -1)
    tmp->pc = (MEM_SIZE / len) * i;
  i++;
  tmp = tmp->next;
  while (tmp != champ)
    {
      if (tmp->pc == -1)
	tmp->pc = (MEM_SIZE / len) * i;
      i++;
      tmp = tmp->next;
    }
  check_adress(champ);
}

void	fill_mem(char **mem, t_champ *champ)
{
  int		len;
  t_champ	*tmp;

  tmp = champ;
  len = read(tmp->fd, *mem + tmp->pc, MEM_SIZE - tmp->pc);
  if (len < tmp->head->prog_size)
    read(tmp->fd, *mem, tmp->head->prog_size);
  tmp->reg[0] = tmp->champ_nb;
  close(tmp->fd);
  printf("path = %s, champ_name = %s, champ_nb = %d\n", tmp->path, tmp->head->prog_name, tmp->champ_nb);
  tmp = tmp->next;
  while (tmp != champ)
    {
      len = read(tmp->fd, *mem + tmp->pc, MEM_SIZE - tmp->pc);
      if (len < tmp->head->prog_size)
	read(tmp->fd, *mem, tmp->head->prog_size);
      tmp->reg[0] = tmp->champ_nb;
      close(tmp->fd);
      printf("path = %s, champ_name = %s, champ_nb = %d\n", tmp->path, tmp->head->prog_name, tmp->champ_nb);
      tmp = tmp->next;
    }
  champ->prev->next = NULL;
  champ->prev = NULL;
}
