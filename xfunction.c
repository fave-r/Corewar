/*
** xfunction.c for xfunction in /home/odet_a/rendu/CPE_2014_corewar/asm
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Mon Feb 24 14:58:20 2014 
** Last update Mon Feb 24 15:11:34 2014 
*/

#include "struct.h"

void	*xmalloc(size_t n)
{
  void	*p;

  p = malloc(n);
  if (p == NULL)
    {
      my_putstr("Malloc Failed.\n", 2);
      exit(EXIT_FAILURE);
    }
  return (p);
}

int	xopen(char *pathname, int flags)
{
  int	fd;

  fd = open(pathname, flags);
  if (fd == -1)
    {
      my_putstr(pathname, 2);
      my_putstr(": Cannot be opened.\n", 2);
      exit(EXIT_FAILURE);
    }
  return (fd);
}

ssize_t	xread(int fd, void *buf, size_t count)
{
  int	x;

  x = read(fd, buf, count);
  if (x == -1)
    {
      my_putstr("Error Read.\n", 2);
      exit(EXIT_FAILURE);
    }
  return (x);
}
