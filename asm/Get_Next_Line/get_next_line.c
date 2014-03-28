/*
** get_next_line.c for corewar in /home/blackbird/work/Corewar/asm/Get_Next_Line
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Mar 24 11:49:17 2014 romaric
** Last update Fri Mar 28 18:04:31 2014 alex-odet
*/

#include "struct.h"

char		*my_get_strdup(char *src)
{
  int		len;
  char		*dest;

  len = (src == NULL) ? 0 : my_strlen(src);
  dest = malloc((len + 2) * sizeof(char));
  if (dest == NULL)
    exit (EXIT_FAILURE);
  if (src != NULL)
    my_strcpy(dest, src);
  dest[len + 1] = 0;
  return (dest);
}

char		*get_next_line(const int fd)
{
  static char   buff[BUFF_SIZE];
  static int    i = 0;
  static int    a = 0;
  t_get	l;

  l.c = 0;
  l.s = NULL;
  if (i == a)
    {
      a = read(fd, buff, BUFF_SIZE);
      i = 0;
    }
  if (a <= 0)
    return (0);
  if (buff[i] == '\n')
    {
      i++;
      return (my_strdup(""));
    }
  if (buff[i] == 0)
    return (NULL);
  while (buff[i] != '\n')
    {
      if (buff[i] == '\0')
	return (l.s);
      l.s = my_get_strdup(l.s);
      l.s[l.c] = buff[i];
      i++;
      l.c++;
    }
  i++;
  if (l.s != NULL)
    l.s[l.c] = 0;
  return (l.s);
}
