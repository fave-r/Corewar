/*
** tmp.c for tmp in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Mar 20 17:43:52 2014 Thibaut Lopez
** Last update Fri Mar 21 07:56:32 2014 thibaud
*/

#include "my.h"
#include "vm.h"

int	print_encode(int *encode)
{
  int   a, b;

  a = b = 0;
  my_putstr("\nENCODE = \n", 1);
  while (a < 4)
    {
      while (b < 3)
        {
          my_putnbr(encode[a][b], 1);
          my_putstr(" ", 1);
          b++;
        }
      b = 0;
      a++;
      my_putstr("\n", 1);
    }
  my_putstr("\n", 1);
}

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
