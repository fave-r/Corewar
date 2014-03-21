/*
** my_print_ptr.c for my_print_ptr in /home/thibaut.lopez/PSU_2018_my_printf
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Nov  6 21:45:54 2013 Thibaut Lopez
** Last update Fri Mar 14 09:39:02 2014 Thibaut Lopez
*/

#include "my.h"

int	my_printlen(va_list arg, int x)
{
  int	*nbr;

  nbr = va_arg(arg, int *);
  *nbr = x;
  return (0);
}

int	my_printvoid(va_list arg, int fd)
{
  int		i;
  unsigned long	nbr;

  i = 2;
  nbr = va_arg(arg, unsigned long);
  my_putstr("0x", fd);
  my_putlong_base(nbr, "0123456789abcdef", &i, fd);
  return (i);
}
