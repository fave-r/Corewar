/*
** my_putf_nbr.c for my_putf_nbr in /home/thibaut.lopez/Corewar/Corewar/my/TMP/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Fri Mar 14 09:36:45 2014 Thibaut Lopez
** Last update Sat Apr  5 18:03:21 2014 Thibaut Lopez
*/

#include "my.h"

int	my_putf_nbr(int nb, int *i, int fd, int bool)
{
  int	a;

  if (nb < 0 && bool == 0)
    {
      my_putchar('-', fd);
      *i = *i + 1;
      nb = -nb;
    }
  a = nb % 10;
  if (a < 0)
    a = -a;
  nb = nb / 10;
  if (nb < 0)
    nb = -nb;
  *i = *i + 1;
  if (nb != 0)
    my_putf_nbr(nb, i, fd, 1);
  my_putchar(a + 48, fd);
  return (*i);
}
