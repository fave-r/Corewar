/*
** main.c for corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Mar 24 11:53:25 2014 romaric
** Last update Thu Mar 27 17:44:16 2014 alex-odet
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
  my_show_file_list(list);
  while (list)
    {
      parser(list->name_file);
      sleep(20);
      list = list->next;
    }
}
