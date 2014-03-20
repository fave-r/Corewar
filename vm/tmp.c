/*
** tmp.c for tmp in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Mar 20 17:43:52 2014 Thibaut Lopez
** Last update Thu Mar 20 17:48:22 2014 Thibaut Lopez
*/

#include "my.h"
#include "vm.h"

int	aff_memdr(unsigned char *mem)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      my_printf(1, "%X|", mem[i]);
      i++;
    }
  my_putstr("\n", 1);
  return (42);
}
