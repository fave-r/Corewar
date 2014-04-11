/*
** my_put_in_cmd_list.c for my_put_in_cmd_list in /home/alex-odet/work/Corewar/asm/List
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  2 13:58:14 2014 alex-odet
** Last update Fri Apr 11 15:24:01 2014 romaric
*/

#include "struct.h"

t_lst		*create_new_node(char *cmd, t_lst **node)
{
  int		len;
  t_lst		*new;

  new = xmalloc(sizeof(t_lst));
  new->cmd = my_str_to_wordtab(cmd, "\t");
  len = my_strlen(new->cmd[0]);
  if (len > 1 && new->cmd[0][len - 1] == ':')
    new->cmd = my_str_to_wordtab(cmd + len, "\t");
  new->next = NULL;
  new->prev = *node;
  if (*node != NULL)
    (*node)->next = new;
  *node = new;
  return (new);
}

t_lst		*function(int fd)
{
  t_lst		*ret;
  t_lst		*first;
  char		*tmp;
  char		*buff;

  ret = NULL;
  first = NULL;
  while ((buff = get_next_line(fd)))
    {
      tmp = buff;
      while ((*tmp == ' ' || *tmp == '\t') && *tmp != 0)
	tmp++;
      if (tmp[0] != '.' && tmp[0] != 0)
	{
	  ret = create_new_node(tmp, &ret);
	  if (first == NULL)
	    first = ret;
	}
    }
  return (first);
}

char	*my_fill_buff(char *str, int fd)
{
  int	new_fd;
  t_lst	*list;
  char  *buff;

  buff = xmalloc(sizeof(char) * 4096);
  new_fd = xopen(str, O_RDONLY);
  list = function(new_fd);
  //(list == NULL) ? my_putstr("Empty file.\n", 2) : parse_list(list, fd);
  return (buff);
}

