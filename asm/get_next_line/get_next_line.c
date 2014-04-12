/*
** get_next_line.c for corewar in /home/blackbird/work/Corewar/asm/get_next_line
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sat Apr 12 23:51:21 2014 romaric
** Last update Sat Apr 12 23:53:22 2014 romaric
*/

#include "struct.h"

char    *my_strdupmoreone(char *src)
{
  char  *dest;

  dest = malloc((my_strlen(src) + 2) * sizeof(char));
  if (dest == NULL)
    exit (EXIT_FAILURE);
  my_strcpy(dest, src);
  return (dest);
}

char    *get_next_line(const int fd)
{
  static char   buff[4096];
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
