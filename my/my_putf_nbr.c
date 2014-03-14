/*
** my_putf_nbr.c for my_putf_nbr in /home/thibaut.lopez/Corewar/Corewar/my/TMP/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Fri Mar 14 09:36:45 2014 Thibaut Lopez
** Last update Fri Mar 14 10:03:59 2014 Thibaut Lopez
*/

#include "my.h"

int	my_putf_nbr(int nb, int *i, int fd)
{
  int	a;

  if (nb < 0)
    {
      my_putchar('-', fd);
      *i = *i + 1;
      nb = -nb;
    }
  a = nb % 10;
  nb = nb / 10;
  *i = *i + 1;
  if (nb > 0)
    my_putf_nbr(nb, i, fd);
  my_putchar(a + 48, fd);
  return (*i);
}
