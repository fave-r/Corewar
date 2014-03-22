/*
** main.c for main in /home/odet_a/Corewar
**
** Made by
** Login   <odet_a@epitech.net>
**
** Started on  Mon Feb 17 04:24:43 2014
** Last update Sat Mar 22 04:44:31 2014 alex-odet
*/

#include "struct.h"

int	main(int ac, char **av)
{
  t_file	*list;
  int		i;

  i = 1;
  list = NULL;
  if (ac == 1)
    {
      my_putstr("Usage : ", 2);
      my_putstr(av[0], 2);
      my_putstr(" Name_Of_The_Champion.s\n", 2);
      return (0);
    }
  else
    {
      while (av[i])
	{
	  list = my_put_in_file_list(list, av[i]);
	  i++;
	}
    }
  send_file_to_parser(list);
  return (0);
}

void	send_file_to_parser(t_file *list)
{
  while (list)
    {
      parser(list->name_file);
      list = list->next;
    }
}
