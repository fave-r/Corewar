/*
** tmp.c for tmp in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Mar 20 17:43:52 2014 Thibaut Lopez
** Last update Fri Mar 21 09:22:24 2014 Thibaut Lopez
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

int	print_encode(int **tab)
{
  printf("ENCODE\n%d %d %d\n%d %d %d\n%d %d %d\n%d %d %d\n", tab[0][0], tab[0][1], tab[0][2], tab[1][0], tab[1][1], tab[1][2], tab[2][0], tab[2][1], tab[2][2], tab[3][0], tab[3][1], tab[3][2]);
  return (42);
}
