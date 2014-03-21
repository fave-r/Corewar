/*
** my_print_spec.c for my_print_spec in /home/thibaut.lopez/PSU_2018_my_printf
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Nov  6 21:42:20 2013 Thibaut Lopez
** Last update Fri Mar 14 09:59:24 2014 Thibaut Lopez
*/

#include "my.h"

int	my_printchar(va_list arg, int fd)
{
  unsigned char	c;

  c = va_arg(arg, int);
  my_putchar(c, fd);
  return (1);
}

int	my_printstr(va_list arg, int fd)
{
  const char	*str;

  str = va_arg(arg, const char *);
  my_putfstr(str, fd);
  return (my_strflen(str));
}

int	my_print_zero(int fd)
{
  my_putchar('0', fd);
  return (1);
}

int	my_printstrsp(va_list arg, int fd)
{
  int	i;
  int	count;
  char	*str;

  i = 0;
  count = 0;
  str = va_arg(arg, char *);
  while (str[i])
    {
      if (str[i] > 32 && str[i] < 127)
	my_putchar(str[i], fd);
      else
	{
	  my_putchar('\\', fd);
	  if (str[i] < 64)
	    count = count + my_print_zero(fd);
	  if (str[i] < 8)
	    count = count + my_print_zero(fd);
	  my_putfnbr_base(str[i], "01234567", &count, fd);
	}
      i++;
    }
  return (i + count);
}

int	my_printdec(va_list arg, int fd)
{
  int		i;
  unsigned int	nbr;

  i = 0;
  nbr = va_arg(arg, unsigned int);
  my_putfnbr_base(nbr, "0123456789", &i, fd);
  return (i);
}
