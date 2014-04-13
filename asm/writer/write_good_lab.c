/*
** write_good_lab.c for write_good_lab in /home/odet_a/work/Corewar/asm/writer
**
** Made by
** Login   <odet_a@epitech.net>
**
** Started on  Sun Apr 13 19:20:01 2014
** Last update Sun Apr 13 20:20:28 2014 
*/

#include "struct.h"

char	*good_lab(t_lab *list)
{
  char	*new;
  int	i;

  i = 0;
  new = xmalloc(sizeof(char) * (my_strlen(list->lab) - 1));
  while (list->lab[i] != ':' && list->lab[i])
    {
      new[i] = list->lab[i];
      i++;
    }
  new[i] = 0;
  return (new);
}

char	*good_lab_call(char *value)
{
  char	*new;
  int	i;
  int	j;

  j = 0;
  i = 2;
  new = xmalloc(sizeof(char) * my_strlen(value));
  while (value[i])
    {
      new[j] = value[i];
      j++;
      i++;
    }
  new[j] = 0;
  return (new);
}

int	find_good_lab(t_lab *list, char *value)
{
  int	size;

  size = 0;
  while (list)
    {
      if (my_strcmp(good_lab(list), good_lab_call(value)) == 0)
	size = list->oct_pos;
      list = list->next;
    }
  return (size);
}
