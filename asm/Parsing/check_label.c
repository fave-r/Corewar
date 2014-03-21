/*
** check_label.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Mar 11 13:02:00 2014 romaric
** Last update Fri Mar 21 18:28:10 2014 alex-odet
*/

#include "struct.h"

t_label		*fill_list_of_label(char *str)
{
  t_label	*list;
  int		fd;
  char		*tmp;

  list = NULL;
  fd = xopen(str, O_RDONLY);
  while ((tmp = get_next_line(fd)))
    {
      if (tmp[my_strlen(tmp) - 1] == ':' && tmp[my_strlen(tmp) - 2] != '%')
	list = my_put_in_list(list, tmp);
      else
	list = check_label(tmp, list); 
    }
  my_show_list(list);
  return (list);
}

t_label		*check_label(char *tmp, t_label *list)
{
  int	i;
  int	j;
  char	*save;

  i = 0;
  j = 0;
  save = xmalloc(sizeof(char) * my_strlen(tmp));
  while (tmp[i])
    {
      if (tmp[i] == ':' && tmp[i + 1] != 0 && tmp[i - 1] != '%'
	  && tmp[i - 1] != ',' && (tmp[i - 1] <= '1' || tmp[i - 1] > '9'))
	{
	  while (j <= i)
	    {
	      save[j] = tmp[j];
	      j++;
	    }
	  save[j] = 0;
	  printf("save = %s\n", save);
	  list = my_put_in_list(list, save);
	  return (list);
	}
      i++;
    }
  save[j] = 0;
  return (NULL);
}
