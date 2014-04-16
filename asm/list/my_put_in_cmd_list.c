/*
** my_put_in_cmd_list.c for my_put_in_cmd_list in /home/alex-odet/work/Corewar/asm/List
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  2 13:58:14 2014 alex-odet
** Last update Wed Apr 16 18:07:34 2014 romaric
*/

#include "struct.h"

t_lst		*create_new_node(char *cmd, t_lst **node)
{
  int		len;
  t_lst		*new;

  new = xmalloc(sizeof(t_lst));
  new->cmd = my_str_to_wordtab(cmd, "\t ");
  len = my_strlen(new->cmd[0]);
  if (len > 1 && new->cmd[0][len - 1] == ':')
    new->cmd = my_str_to_wordtab(cmd + len, "\t ");
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
  close(fd);
  return (first);
}

int		my_fill_buff(char *str, int fd, t_lab *lab)
{
  int		new_fd;
  t_lst		*list;
  int		len;

  len = 0;
  new_fd = xopen(str, O_RDONLY);
  list = function(new_fd);
  if (list == NULL)
    my_putstr("Empty file.\n", 2);
  else
    len = parse_list(list, fd, lab);
  close (new_fd);
  close (fd);
  return (len);
}

int		parse_list(t_lst *list, int fd, t_lab *lab)
{
  t_size	p;
  int		i;

  i = 0;
  p.size = 0;
  while (list && i < my_cmd_size(list))
    {
      p.len = 0;
      write_in_buff(list->cmd, &p, fd, lab);
      p.size += p.len;
      list = list->next;
      i++;
    }
  return (p.size);
}
