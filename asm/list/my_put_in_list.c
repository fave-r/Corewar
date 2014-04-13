/*
** my_put_in_list.c for my_put_in_list in /home/alex-odet/work/Corewar/asm/List
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Mar 21 00:05:01 2014 alex-odet
** Last update Sun Apr 13 02:24:39 2014 alex-odet
*/

#include "struct.h"

t_label		*new_node(char *name)
{
  t_label	*new;

  new = xmalloc(sizeof(t_label));
  new->name = name;
  new->next = NULL;
  return (new);
}

t_label		*my_put_in_list(t_label *list, char *name)
{
  t_label	*tmp;

  if (list == NULL)
    return (new_node(name));
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_node(name);
  return (list);
}
