/*
** my_printf.c for my_printf in /home/thibaut.lopez/PSU_2018_my_printf
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Tue Nov  5 18:31:47 2013 Thibaut Lopez
** Last update Mon Mar 24 12:13:38 2014 romaric
*/

#include "my.h"

int	(*ptr_tab[13])() =
{&my_printbin,
 &my_printchar,
 &my_printnbr,
 &my_printnbr,
 &my_printlen,
 &my_printoct,
 &my_printvoid,
 &my_printstr,
 &my_printstrsp,
 &my_printdec,
 &my_printhex,
 &my_printhexc};

int	my_ident_flag(const char *str, va_list ap, int *count, int fd)
{
  char	tab[14] = "bcdinopsSuxX%";

  if (my_strchr(str[count[0]], tab) == -1)
    {
      my_putchar('%', fd);
      my_putchar(str[count[0]], fd);
      return (1);
    }
  else if (my_strchr(str[count[0]], tab) == 12)
    {
      my_putchar('%', fd);
      return (0);
    }
  else if (my_strchr(str[count[0]], tab) == 4)
    return (ptr_tab[my_strchr(str[count[0]], tab)]
	    (ap, count[0] + count - 1));
  else
    return (ptr_tab[my_strchr(str[count[0]], tab)](ap, fd));
}

int	my_printf(int fd, const char *format, ...)
{
  va_list	ap;
  int		*count;
  int		ret;

  va_start(ap, format);
  count = xmalloc(2 * sizeof(int));
  count[0] = 0;
  count[1] = 0;
  while (format[count[0]])
    {
      if (format[count[0]] == '%')
	{
	  count[0]++;
	  count[1] += my_ident_flag(format, ap, count, fd) - 2;
	}
      else
	my_putchar(format[count[0]], fd);
      count[0]++;
    }
  va_end(ap);
  ret = count[0] + count[1];
  free(count);
  return (ret);
}
