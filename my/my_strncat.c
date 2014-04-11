/*
** my_strncat.c for corewar in /home/blackbird/work/Corewar/my
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Fri Apr 11 15:02:38 2014 romaric
** Last update Fri Apr 11 15:06:58 2014 romaric
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int len)
{
  int	i;
  int	j;
  char	*ret;

  i = 0;
  j = 0;
  ret = xmalloc((len * 2 + 1) * sizeof(char));
  while (i < len)
    {
      ret[i] = dest[i];
      i++;
    }
  while (j < len)
    {
      ret[i + j] = src[j];
      j++;
    }
  ret[i + j] = '\0';
  return (ret);
}
