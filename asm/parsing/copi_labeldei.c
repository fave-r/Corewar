/*
** copi_labeldei.c for corewar in /home/blackbird/work/Corewar/asm/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Apr  8 15:01:40 2014 romaric
** Last update Sun Apr 13 22:15:20 2014 romaric
*/

#include "struct.h"

void	init_labeldei(int *i, int *x, int *j, int *size)
{
  *x = *x + 2;
  *i = *x;
  *j = 0;
  *size = 0;
}

char	*copi_labeldei(char *args, int x)
{
  char	*str;
  int	i;
  int	j;
  int	size;

  init_labeldei(&i, &x, &j, &size);
  while (args[x + 2] != ',')
    {
      size++;
      x++;
    }
  str = xmalloc((size + 1) * sizeof(char));
  if (args[i - 1] == ':')
    {
      while (args[i] != ',')
        {
	  str[j] = args[i];
          j++;
          i++;
        }
      str[j++] = '\0';
      return (str);
    }
  return (NULL);
}
