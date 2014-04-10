/*
** my_xtest.c for my_xtest in /home/thibaut.lopez/Corewar
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Sun Feb 23 21:21:10 2014 Thibaut Lopez
** Last update Thu Apr 10 13:27:24 2014 romaric
*/

#include "my.h"

void	*xmalloc(size_t n)
{
  void	*p;

  p = malloc(n);
  if (p == NULL)
    {
      my_putstr(ER_MALLOC, 2);
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
      my_putstr(ER_OPEN, 2);
      exit(EXIT_FAILURE);
    }
  return (fd);
}

ssize_t	xread(int fd, void *buf, size_t count)
{
  int	x;

  x = read(fd, buf, count);
  if (x < 0)
    {
      my_putstr(ER_READ, 2);
      exit(EXIT_FAILURE);
    }
  return (x);
}
