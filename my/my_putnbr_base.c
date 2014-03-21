/*
** my_putnbr_base.c for my_putnbr_base in /home/odet_a/rendu/Piscine-C-Jour_06/ex_15
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Mon Oct  7 20:30:16 2013 alexandre.odet
** Last update Mon Mar  3 19:21:42 2014 Thibaut Lopez
*/

#include <stdio.h>

void	my_putnbr_base(unsigned int nb, char *base)
{
  int	a;
  int	len_base;

  len_base = my_strlen(base);
  a = nb % len_base;
  nb = nb / len_base;
  if (nb > 0)
    my_putnbr_base(nb, base);
  my_putchar(base[a]);
}
