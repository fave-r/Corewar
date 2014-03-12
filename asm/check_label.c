/*
** check_label.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Mar 11 13:02:00 2014 romaric
** Last update Wed Mar 12 18:28:05 2014 romaric
*/

#include "struct.h"

int count_labels(char *str)
{
  int   fd;
  char  *line;
  int   i;
  int   x;
  int   k;

  k = 0;
  i = 0;
  x = 0;
  fd = xopen(str, O_RDONLY);
  while ((line = get_next_line(fd)))
    {
      while (line[i] != ':' && line[i] != '\0')
	i++;
      i--;
      if (line[i] == '%'|| (line[i] >= '0' && line[i] <= '9'))
	k++;//ceci est une line qui ne sert a rien mais oblige par la condition
      else if (line[++i] != '\0')
	x++;
      i = 0;
    }
  return (x);
}

void	check_label(char *str)
{
  t_label	p;

  p.i = 0;
  p.x = 0;
  p.k = 0;
  p.nbrlabels = count_labels(str);
  p.labels = xmalloc(p.nbrlabels * sizeof(char*));
  p.fd = xopen(str, O_RDONLY);
  while ((p.line = get_next_line(p.fd)))
    {
      while (p.line[p.i] != ':' && p.line[p.i] != '\0')
	p.i++;
      p.i--;
      if (p.line[p.i] == '%' || (p.line[p.i] >= '0' && p.line[p.i] <= '9'))
	p.k++;//ceci est une line qui ne sert a rien mais oblige par la condition
      else if (p.line[++p.i] != '\0')
	p.labels = create_label(p.line, p.labels, p.i, &p.x);
      p.i = 0;
    }
}

char	**create_label(char *line, char **labels, int i, int *y)
{
  int	x;

  labels[*y] = xmalloc(i * sizeof(char));
  x = 0;
  while (x != i)
    {
      labels[*y][x] = line[x];
      x++;
    }
  *y = *y + 1;
  return (labels);
}
