/*
** xfunction.c for xfunction in /home/odet_a/Corewar/lib
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Mon Feb 17 04:46:01 2014 
** Last update Mon Feb 17 18:57:45 2014 
*/

#include "../../struct.h"

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

int	xopen(const char *pathname, int flags)
{
  int	fd;

  fd = open(pathname, flags);
  if (fd == -1)
    {
      my_putstr("Open Failed.\n", 2);
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
      my_putstr("Read Failed.\n", 2);
      exit(EXIT_FAILURE);
    }
  return (x);
}
