/*
** new_get_next_line.c for get_next_line in /home/blackbird/work/get_next_line
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sat Nov 23 13:24:46 2013 romaric
** Last update Mon Mar 24 11:45:38 2014 romaric
*/

#include "get_next_line.h"

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}

int		my_strlen(char *str)
{
  int		x;

  x = 0;
  while  (str[x] != '\0')
      x++;
  return (x);
}

char		*my_strdup(char *src)
{
  char		*dest;

  dest = malloc((my_strlen(src) + 2) * sizeof(char));
  if (dest == NULL)
    exit (EXIT_FAILURE);
  my_strcpy(dest, src);
  return (dest);
}

char		*get_next_line(const int fd)
{
  static char   buff[BUFF_SIZE];
  static int    i = 0;
  static int    a = 0;
  t_get	l;

  l.c = 0;
  l.s = malloc(1 * sizeof(char));
  if (i == a)
    {
      a = read(fd, buff, BUFF_SIZE);
      i = 0;
    }
  if (a <= 0)
    return (0);
  while (buff[i] != '\n')
    {
      if (buff[i] == '\0')
	return (l.s);
      l.s = my_strdup(l.s);
      l.s[l.c] = buff[i];
      i++;
      l.c++;
    }
  i++;
  return (l.s);
}
