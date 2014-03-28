/*
** check_label.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Mar 11 13:02:00 2014 romaric
** Last update Fri Mar 28 15:16:08 2014 alex-odet
*/

#include "struct.h"

t_label		*fill_list_of_label(char *str)
{
  t_label	*list;
  int		fd;
  char		*tmp;
  int		line;

  line = 1;
  list = NULL;
  fd = xopen(str, O_RDONLY);
  while ((tmp = get_next_line(fd)))
    {
      if (tmp[my_strlen(tmp) - 1] == ':' && tmp[my_strlen(tmp) - 2] != '%')
	list = my_put_in_list(list, tmp, line);
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
  char		*save;

  i = 0;
  save = xmalloc(sizeof(char) * my_strlen(tmp));
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
