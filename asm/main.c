/*
** main.c for main in /home/odet_a/Corewar
**
** Made by
** Login   <odet_a@epitech.net>
**
** Started on  Mon Feb 17 04:24:43 2014
** Last update Thu Mar 13 10:18:04 2014 Thibaut Lopez
*/

#include "struct.h"
#include "op.h"
#include "my.h"

int	main(int ac, char **av)
{
  if (ac == 1)
    {
      my_putstr("Usage : ", 2);
      my_putstr(av[0], 2);
      my_putstr(" Name_Of_The_Champion.s\n", 2);
      return (0);
    }
  else
    parser(av[1]);
  return (0);
}
