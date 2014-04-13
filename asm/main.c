/*
** main.c for corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Mar 24 11:53:25 2014 romaric
** Last update Sun Apr 13 02:25:15 2014 alex-odet
*/

#include "struct.h"

int	main(int ac, char **av)
{
  int		i;

  i = 1;
  if (ac == 1)
    {
      my_putstr("Usage : ", 2);
      my_putstr(av[0], 2);
      my_putstr(" Name_Of_The_Champion.s\n", 2);
      return (0);
    }
  parser(av[1]);
  return (0);
}
