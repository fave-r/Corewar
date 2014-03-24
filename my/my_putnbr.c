/*
** my_putnbr.c for Corewar in /home/blackbird/work/Corewar/my
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Feb 26 16:46:01 2014 romaric
** Last update Mon Mar 24 12:13:07 2014 romaric
*/

#include "my.h"

void    my_putnbr(int n, int fd)
{
  if (n < 0)
    {
      my_putchar('-', fd);
      n = -n;
    }
  if (n >= 10)
    {
      my_putnbr(n / 10, fd);
      my_putnbr(n % 10, fd);
    }
  else
    my_putchar(48 + n, fd);
}
