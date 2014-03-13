/*
** check_label.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Mar 11 13:02:00 2014 romaric
** Last update Thu Mar 13 11:56:36 2014 alex-odet
*/

#include "struct.h"
#include "my.h"

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
  printf("x = %d\n", x);
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
  check_label_exist(p.labels, str, p.nbrlabels);
}

void	check_label_exist(char **labels, char *str, int nbrlabels)
{
  int	fd;
  char	*label;
  int	i;
  int	x;
  int	w;
  char	*line;
  int	k;

  i = 0;
  x = 0;
  w = 0;
  k = 0;
  fd = xopen(str, O_RDONLY);
  printf("nbrlabels = %d\n", nbrlabels);
  while ((line = get_next_line(fd)))
    {
      while (line[i] != ':' && line[i] != '\0')
        i++;
      if (line[++i] == '\0')
	k++;//ceci est une line qui ne sert a rien mais oblige par la condition
      else if (line[i - 2] == '%')
	{
	  x = i;
	  while (line[i] >= 'a' && line[i] <= 'z')
	    i++;
	  label = xmalloc((i - x + 1) * sizeof(char));
	  i = 0;
	  while (line[x] >= 'a' && line[x] <= 'z')
	    {
	      label[i] = line[x];
	      i++;
	      x++;
	    }
	  i = 0;
	  while (w <= nbrlabels)
	    {
	      printf("nbrlabels = %d\nlabels[4] = %s\n", nbrlabels, labels[4]);
	      if (my_strcmp(labels[w], label) == 0)
		{
		  printf("label = %s\nlabels[w] = %s\n", label, labels[w]);
		  i++;
		}
	      w++;
	    }
	  if (i == 0)
	    {
	      my_putstr("bourrel suce\n", 2);
	      exit(EXIT_FAILURE);
	    }
	}
      i = 0;
      x = 0;
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
  *y = *y++;
  return (labels);
}
