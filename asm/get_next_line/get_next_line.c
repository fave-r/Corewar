/*
** new_get_next_line.c for get_next_line in /home/blackbird/work/get_next_line
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sat Nov 23 13:24:46 2013 romaric
** Last update Sun Apr 13 19:25:16 2014 romaric
*/

#include "struct.h"

char		*my_strdup_new(char *src)
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
      l.s = my_strdup_new(l.s);
      l.s[l.c] = buff[i];
      i++;
      l.c++;
    }
  i++;
  return (l.s);
}
