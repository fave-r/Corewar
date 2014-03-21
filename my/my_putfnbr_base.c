/*
** my_putfnbr_base.c for my_putfnbr_base in /home/thibaut.lopez/Corewar/Corewar/my/TMP/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Fri Mar 14 09:36:59 2014 Thibaut Lopez
** Last update Fri Mar 14 10:00:44 2014 Thibaut Lopez
*/

#include "my.h"

int	my_putfnbr_base(unsigned int nb, char *base, int *i, int fd)
{
  int	a;
  int	len_base;

  len_base = my_strlen(base);
  a = nb % len_base;
  nb = nb / len_base;
  (*i)++;
  if (nb > 0)
    my_putfnbr_base(nb, base, i, fd);
  my_putchar(base[a], fd);
  return (4);
}
