/*
** check_label.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Mar 11 13:02:00 2014 romaric
** Last update Wed Apr  2 17:22:02 2014 romaric
*/

#include "struct.h"

t_label		*fill_list_of_label(char *str)
{
  t_label	*list;
  int		fd;
  char		*tmp;
  int		line;
  char		*save;

  line = 1;
  list = NULL;
  fd = xopen(str, O_RDONLY);
  while ((tmp = get_next_line(fd)))
    {
      if (tmp[my_strlen(tmp) - 1] == ':' && tmp[my_strlen(tmp) - 2] != '%')
	{
	  save = my_strndup(tmp, my_strlen(tmp) - 1);
	  list = my_put_in_list(list, save, line);
	}
      else
	list = check_label(tmp, list, line);
      line++;
    }
  my_show_list(list);
  close (fd);
  return (list);
}

t_label		*check_label(char *tmp, t_label *list, int line)
{
  int		i;

  i = 0;
  while (tmp[i])
    {
      if (tmp[i] == ':' && tmp[i - 1] != '%'
	  && tmp[i - 1] != ',' && tmp[i - 1] != ' '
	  && tmp[i - 1] != '\t' && tmp[i - 3] != ','
	  && (tmp[i + 1] == '\t' || tmp[i + 1] == ' '))
	list = copy_label(tmp, i, list, line);
      i++;
    }
  return (list);
}

t_label		*copy_label(char *tmp, int len, t_label *list, int line)
{
  char	*save;

  save = my_strndup(tmp, len);
  list = my_put_in_list(list, save, line);
  return (list);
}

int	check_label_exist(t_label *list, char *label_check)
{
  int	i;

  i = 0;
  if (label_check != NULL)
    {
      while (list != NULL)
	{
	  if (my_strcmp(label_check,list->name) == 0)
	    i = 1;
	  list = list->next;
	}
      return (i);
    }
  return (0);
}
