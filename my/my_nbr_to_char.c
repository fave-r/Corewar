/*
** my_nbr_to_char.c for my_nbr_to_char in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Sat Apr 12 21:06:17 2014 Thibaut Lopez
** Last update Sat Apr 12 21:21:59 2014 Thibaut Lopez
*/

#include "my.h"
#include <stdio.h>

char	*my_nbr_to_char(int nb, int tmp_nb)
{
  int	len;
  char	*str;

  len = (tmp_nb == 0) ? 2 : 1;
  while (tmp_nb != 0)
    {
      len++;
      tmp_nb /= 10;
    }
  str = xmalloc(len * sizeof(char));
  len--;
  str[len] = 0;
  len--;
  if (nb == 0)
    str[0] = '0';
  while (nb != 0)
    {
      str[len] = nb % 10 + 48;
      nb /= 10;
      len--;
    }
  return (str);
}
