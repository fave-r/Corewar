/*
** check_label.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Mar 11 13:02:00 2014 romaric
** Last update Tue Mar 11 19:40:26 2014 romaric
*/

#include "struct.h"

int count_labels(char *str)
{
  int   fd;
  char  *line;
  int   i;
  int   x;
  int   k = 0;

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
  int	fd;
  char	*line;
  int	i;
  char	**labels;
  int	x;
  int	k = 0;
  int	w;
  int	nbrlabels;

  i = 0;
  x = 0;
  w = 0;
  nbrlabels = count_labels(str);
  labels = xmalloc(nbrlabels * sizeof(char*));
  fd = xopen(str, O_RDONLY);
  while ((line = get_next_line(fd)))
    {
      while (line[i] != ':' && line[i] != '\0')
	i++;
      i--;
      if (line[i] == '%' || (line[i] >= '0' && line[i] <= '9'))
	k++;//ceci est une line qui ne sert a rien mais oblige par la condition
      else if (line[++i] != '\0')
	labels = create_label(line, labels, i, &x);
      i = 0;
    }
  while (w < x)
    {
      printf("%s\n", labels[w]);
      w++;
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
