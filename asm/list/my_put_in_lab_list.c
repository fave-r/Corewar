/*
** my_put_in_lab_list.c for my_put_in_lab_list in /home/alex-odet/work/Corewar/asm/list
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Sun Apr 13 14:50:26 2014 alex-odet
** Last update Sun Apr 13 22:04:20 2014 romaric
*/

#include "struct.h"

t_lab	*new_lab_node(char *label, int oct_pos)
{
  t_lab	*new;

  new = xmalloc(sizeof(t_lab));
  new->lab = label;
  new->oct_pos = oct_pos;
  new->next = NULL;
  return (new);
}

t_lab	*my_put_in_lab_list(t_lab *list, char *label, int oct_pos)
{
  t_lab	*tmp;

  if (list == NULL)
    return (new_lab_node(label, oct_pos));
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_lab_node(label, oct_pos);
  return (list);
}

char	*remove_comment(char *str)
{
  int	i;
  char	*new;

  i = 0;
  new = xmalloc(sizeof(char) * (my_strlen(str) + 1));
  while (str[i] != ';' && str[i] != '#' && str[i])
    {
      new[i] = str[i];
      i++;
    }
  new[i] = 0;
  return (new);
}
