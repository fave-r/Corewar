/*
** tmp.c for tmp in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Mar 20 17:43:52 2014 Thibaut Lopez
<<<<<<< HEAD
** Last update Wed Mar 26 16:07:29 2014 Thibaut Lopez
=======
** Last update Wed Mar 26 15:50:56 2014 thibaud
>>>>>>> 6ead5372de22acdfb9145f9316d83847f12eea49
*/

#include "my.h"
#include "vm.h"

int	aff_memdr(unsigned char *mem)
{
  int	i;
  int	j;

  i = 0;
  while (i < MEM_SIZE)
    {
<<<<<<< HEAD
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
=======
      my_printf(1, "");
      while ((i % 16) != 0)
	{
      my_printf(1, "%X ", mem[i]);
      i++;
	}
      my_printf(1, "\n");
>>>>>>> 6ead5372de22acdfb9145f9316d83847f12eea49
    }
  my_putstr("\n", 1);
  return (42);
}

int	print_encode(int **tab)
{
  printf("ENCODE\n%d %d %d\n%d %d %d\n%d %d %d\n%d %d %d\n", tab[0][0], tab[0][1], tab[0][2], tab[1][0], tab[1][1], tab[1][2], tab[2][0], tab[2][1], tab[2][2], tab[3][0], tab[3][1], tab[3][2]);
  return (42);
}
