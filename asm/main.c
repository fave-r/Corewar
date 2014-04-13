/*
** main.c for corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Mar 24 11:53:25 2014 romaric
** Last update Sun Apr 13 05:39:38 2014 romaric
*/

#include "struct.h"

int	main(int ac, char **av)
{
  int		fd;
  header_t	*ptr;
  header_t	*new;
  int		len;

  if (ac == 1)
    {
      my_putstr("Usage : ", 2);
      my_putstr(av[0], 2);
      my_putstr(" Name_Of_The_Champion.s\n", 2);
      return (0);
    }
  ptr = init();
  new = init();
  parser(av[1]);
  ptr = fill_header(check_name(av[1]), check_comment(av[1]), 0);
  fd = create_cor(av[1], ptr);
  len = my_fill_buff(av[1], fd);
  close(fd);
  new = fill_header(check_name(av[1]), check_comment(av[1]), len);
  create_cor(av[1], new);
  return (0);
}
