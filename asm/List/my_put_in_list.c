/*
** my_put_in_list.c for my_put_in_list in /home/alex-odet/work/Corewar/asm/List
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Mar 21 00:05:01 2014 alex-odet
** Last update Fri Mar 21 00:18:22 2014 alex-odet
*/

#include "struct.h"

t_label		*my_put_in_list(t_label *list, char *name)
{
  t_label *new;
  t_label *tmp;

  new = xmalloc(sizeof(t_label));
  new->name = name;
  new->next = NULL;
  if (list == NULL)
    return (new);
  tmp = list;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
  return (list);
}