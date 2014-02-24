/*
** get_next_line.c for get_next_line in /home/odet_a/rendu/CPE-2013-BSQ/get_next_line
**
** Made by
** Login   <odet_a@epitech.net>
**
** Started on  Fri Dec  6 17:53:50 2013
** Last update Mon Feb 17 18:57:38 2014 
*/

#include "../../struct.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}

char    *my_strdup(char *src)
{
  char  *dest;

  dest = malloc((my_strlen(src) + 2) * sizeof(char));
  if (dest == NULL)
    {
      free(dest);
      exit (EXIT_FAILURE);
    }
  my_strcpy(dest, src);
  dest[my_strlen(src)] = 0;
  free(src);
  return (dest);
}

char    *get_next_line(const int fd)
{
  static char   buff[BUFF_SIZE];
  static int    i = 0;
  static int    a = 0;
  t_gnl		ptr;

  ptr.c = 0;
  ptr.save = malloc(1 * sizeof(char));
  if (i == a)
    {
      a = xread(fd, buff, BUFF_SIZE);
      buff[a] = '\0';
      i = 0;
    }
  if (a <= 0)
    {
      free(ptr.save);
      return (NULL);
    }
  while (buff[i] != '\n')
    {
      if (buff[i] == '\0')
	return (ptr.save);
      ptr.save= my_strdup(ptr.save);
      ptr.save[ptr.c] = buff[i];
      i++;
      ptr.c++;
    }
  i++;
  return (ptr.save);
}
