/*
** mem_fun.c for mem_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Apr  9 00:46:06 2014 Thibaut Lopez
** Last update Sun Apr 13 12:55:42 2014 Thibaut Lopez
*/

#include "my.h"
#include "vm.h"

int	aff_mem(unsigned char *mem)
{
  int	i;
  int	j;

  i = 0;
  while (i < MEM_SIZE)
    {
      j = 0;
      if (i < 4096)
	my_putstr("0", 1);
      if (i < 256)
	my_putstr("0", 1);
      if (i < 16)
	my_putstr("0", 1);
      my_printf(1, "%x :", i);
      while (i + j < MEM_SIZE && j < 16)
	{
	  my_printf(1, (mem[i + j] < 16) ? " 0%X" : " %X", mem[i + j]);
	  j++;
	}
      my_putchar('\n', 1);
      i += j;
    }
  my_putstr("\n", 1);
  exit(0);
  return (42);
}

void	cor_mem_set(unsigned char *mem, int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      mem[i] = 0;
      i++;
    }
}

int	list_size(t_champ *champ)
{
  int	nb;
  t_champ	*tmp;

  tmp = champ;
  nb = 0;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      nb++;
    }
  return (nb);
}
