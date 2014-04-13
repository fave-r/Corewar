/*
** my_nbr_to_char.c for my_nbr_to_char in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Sat Apr 12 21:06:17 2014 Thibaut Lopez
** Last update Sun Apr 13 15:33:32 2014 Thibaut Lopez
*/

#include "my.h"

int	nbr_len(int nb)
{
  int	len;

  len = (nb == 0) ? 2 : 1;
  while (nb != 0)
    {
      len++;
      nb /= 10;
    }
  return (len);
}

char	*my_nbr_to_char(int nb)
{
  int	len;
  char	*str;

  len = nbr_len(nb);
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
