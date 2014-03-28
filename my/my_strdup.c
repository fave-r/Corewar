/*
** my_strdup.c for my_strdup in /home/thibaut.lopez/rendu/PSU_2013_my_ls/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Fri Nov 29 11:55:25 2013 Thibaut Lopez
** Last update Fri Mar 28 16:46:58 2014 alex-odet
*/

#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *src)
{
  char	*dest;

  if (src == NULL)
    return (NULL);
  dest = xmalloc(my_strlen(src) + 1);
  my_strcpy(dest, src);
  dest[my_strlen(src)] = 0;
  return (dest);
}
