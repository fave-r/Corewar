/*
** check_label.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Mar 11 13:02:00 2014 romaric
** Last update Fri Mar 21 09:54:18 2014 alex-odet
*/

#include "struct.h"

t_label	*fill_list_of_label(char *str)
{
  t_label	*list;
  int		fd;
  char		*tmp;

  list = xmalloc(sizeof(t_label));
  fd = xopen(str, O_RDONLY);
  while ((tmp = get_next_line(fd)))
    {
      if (tmp[my_strlen(tmp) - 1] == ':')
	my_put_in_list(list, tmp);
    }
  //  my_show_list(list);
  return (list);
}
