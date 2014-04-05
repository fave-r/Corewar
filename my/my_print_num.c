/*
** my_print_num.c for my_print_num in /home/thibaut.lopez/PSU_2018_my_printf
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Nov  6 21:39:29 2013 Thibaut Lopez
** Last update Sat Apr  5 17:59:16 2014 Thibaut Lopez
*/

#include "my.h"

int	my_printbin(va_list arg, int fd)
{
  int		i;
  unsigned int	nbr;

  i = 0;
  nbr = va_arg(arg, unsigned int);
  my_putfnbr_base(nbr, "01", &i, fd);
  return (i);
}

int	my_printoct(va_list arg, int fd)
{
  int		i;
  unsigned int	nbr;

  i = 0;
  nbr = va_arg(arg, unsigned int);
  my_putfnbr_base(nbr, "01234567", &i, fd);
  return (i);
}

int	my_printnbr(va_list arg, int fd)
{
  int  	i;
  int	nbr;

  i = 0;
  nbr = va_arg(arg, int);
  my_putf_nbr(nbr, &i, fd, 0);
  return (i);
}

int	my_printhex(va_list arg, int fd)
{
  int		i;
  unsigned int	nbr;

  i = 0;
  nbr = va_arg(arg, unsigned int);
  my_putfnbr_base(nbr, "0123456789abcdef", &i, fd);
  return (i);
}

int	my_printhexc(va_list arg, int fd)
{
  int		i;
  unsigned int	nbr;

  i = 0;
  nbr = va_arg(arg, unsigned int);
  my_putfnbr_base(nbr, "0123456789ABCDEF", &i, fd);
  return (i);
}
