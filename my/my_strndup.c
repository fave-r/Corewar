/*
** my_strndup.c for my_strndup in /home/alex-odet/work/Corewar/my
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Mar 28 15:07:32 2014 alex-odet
** Last update Fri Mar 28 15:15:10 2014 alex-odet
*/

#include "my.h"

char	*my_strncpy(char *dest, char *src, int len)
{
  int	i;

  i = 0;
  while (src[i] && i < len)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

char	*my_strndup(char *src, int len)
{
  char	*dest;

  if (src == NULL)
    return (NULL);
  dest = xmalloc(sizeof(char) * len);
  my_strncpy(dest, src, len);
  dest[len] = 0;
  return (dest);
}
