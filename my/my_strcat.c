/*
** my_strcat.c for my_strcat in /home/thibaut.lopez/rendu/PSU_2013_my_ls/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Fri Nov 29 11:54:53 2013 Thibaut Lopez
** Last update Thu Mar 13 10:21:34 2014 Thibaut Lopez
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  int	len1;
  int	len2;
  char	*ret;

  i = 0;
  j = 0;
  len1 = my_strlen(dest);
  len2 = my_strlen(src);
  ret = malloc((len1 + len2 + 1) * sizeof(char));
  if (ret == NULL)
    return (NULL);
  while (dest[i] != '\0')
    {
      ret[i] = dest[i];
      i++;
    }
  while (src[j] != '\0')
    {
      ret[i + j] = src[j];
      j++;
    }
  ret[i + j] = '\0';
  return (ret);
}
