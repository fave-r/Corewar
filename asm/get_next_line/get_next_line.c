/*
** get_next_line.c for corewar in /home/blackbird/work/Corewar/asm/Get_Next_Line
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Mar 24 11:49:17 2014 romaric
** Last update Fri Apr 11 23:18:28 2014 romaric
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

void	get_init(t_get *l)
{
  l->c = 0;
  l->s = NULL;
}

void	init_a(int *i, int *a, int fd, char buff[])
{
  if (*i == *a)
    {
      *a = xread(fd, buff, BUFF_SIZE);
      *i = 0;
    }
}

void	val(int *i, t_get *l)
{
  *i = *i + 1;
  if (l->s != NULL)
    l->s[l->c] = 0;
}

char		*get_next_line(const int fd)
{
  static char   buff[BUFF_SIZE];
  static int    i = 0;
  static int    a = 0;
  t_get		l;

  get_init(&l);
  init_a(&i, &a, fd, buff);
  if (buff[i] == '\n')
    {
      i++;
      return (my_strdup(""));
    }
  if (buff[i] == 0)
    {
      operationss(buff, &i, &a);
      return (NULL);
    }
  while (buff[i] != '\n')
    {
      if (buff[i] == '\0')
	  return (NULL);
      operations(&l, &i, buff);
    }
  val(&i, &l);
  return (l.s);
}
