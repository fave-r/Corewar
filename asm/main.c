/*
** main.c for corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Mar 24 11:53:25 2014 romaric
** Last update Sun Apr 13 19:34:31 2014 
*/

#include "struct.h"

int		main(int ac, char **av)
{
  int		fd;
  header_t	*ptr;
  int		len;
  t_lab		*list;

  if (ac == 1)
    {
      my_putstr("Usage : ", 2);
      my_putstr(av[0], 2);
      my_putstr(" Name_Of_The_Champion.s\n", 2);
      return (0);
    }
  list = NULL;
  ptr = init();
  parser(av[1]);
  list = set_label_pos(av[1], list);
  fd = create_cor(av[1], ptr);
  print_assembling(av[1], check_name(av[1]), check_comment(av[1]));
  len = my_fill_buff(av[1], fd, list);
  close(fd);
  ptr = fill_header(check_name(av[1]), check_comment(av[1]), len);
  create_cor(av[1], ptr);
  free(ptr);
  return (0);
}
