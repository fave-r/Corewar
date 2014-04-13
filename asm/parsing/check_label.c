/*
** check_label.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Mar 11 13:02:00 2014 romaric
** Last update Sun Apr 13 22:09:42 2014 romaric
*/

#include "struct.h"

t_label		*fill_list_of_label(char *str)
{
  t_label	*list;
  t_chklab	p;

  list = NULL;
  p.fd = xopen(str, O_RDONLY);
  while ((p.tmp = get_next_line(p.fd)))
    {
      if ((p.tmp[0] >= 'a' && p.tmp[0] <= 'z')
	  && p.tmp[my_strlen(p.tmp) - 1] == ':')
	{
	  p.save = my_strndup(p.tmp, my_strlen(p.tmp) - 1);
	  if ((check_label_exist(list, p.save)) != 1)
	    list = my_put_in_list(list, p.save);
	}
      else
	list = check_label(p.tmp, list);
    }
  close (p.fd);
  return (list);
}

t_label		*check_label(char *tmp, t_label *list)
{
  int		i;

  i = 0;
  while (tmp[i])
    {
      if (tmp[i] == ':' && tmp[i - 1] != '%'
	  && tmp[i - 1] != ',' && tmp[i - 1] != ' '
	  && tmp[i - 1] != '\t' && tmp[i - 3] != ','
	  && (tmp[i + 1] == '\t' || tmp[i + 1] == ' '))
	list = copy_label(tmp, i, list);
      i++;
    }
  return (list);
}

t_label		*copy_label(char *tmp, int len, t_label *list)
{
  char		*save;

  save = my_strndup(tmp, len);
  if ((check_label_exist(list, save)) != 1)
    list = my_put_in_list(list, save);
  return (list);
}

int		check_label_exist(t_label *list, char *label_check)
{
  int		i;

  i = 0;
  if (label_check != NULL)
    {
      while (list != NULL)
	{
	  if (my_strcmp(label_check, list->name) == 0)
	    i = 1;
	  list = list->next;
	}
      return (i);
    }
  return (0);
}

