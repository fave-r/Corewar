/*
** my_put_in_list.c for my_put_in_list in /home/alex-odet/work/Corewar/asm/List
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Mar 21 00:05:01 2014 alex-odet
** Last update Fri Mar 28 15:13:27 2014 alex-odet
*/

#include "struct.h"

t_label		*new_node(char *name, int line)
{
  t_label	*new;

  new = xmalloc(sizeof(t_label));
  new->name = name;
  new->line = line;
  new->next = NULL;
  return (new);
}

t_label		*my_put_in_list(t_label *list, char *name, int line)
{
  t_label	*tmp;

  if (list == NULL)
    return (new_node(name, line));
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_node(name, line);
  return (list);
}

t_file		*create_node(char *name)
{
  t_file	*new;

  new = xmalloc(sizeof(t_file));
  new->name_file = name;
  new->next = NULL;
  return (new);
}

t_file		*my_put_in_file_list(t_file *list, char *name)
{
  t_file	*tmp;

  if (list == NULL)
    return (create_node(name));
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = create_node(name);
  return (list);
}