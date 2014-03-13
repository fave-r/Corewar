/*
** get_next_line.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Feb 25 18:55:03 2014 romaric
** Last update Thu Mar 13 10:18:22 2014 Thibaut Lopez
*/

#include "struct.h"
#include "my.h"

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
