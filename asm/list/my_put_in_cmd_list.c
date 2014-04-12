/*
** my_put_in_cmd_list.c for my_put_in_cmd_list in /home/alex-odet/work/Corewar/asm/List
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  2 13:58:14 2014 alex-odet
** Last update Sat Apr 12 13:57:24 2014 alex-odet
*/

#include "struct.h"

void	my_show_tab(char **tab)
{
  int	i;

  i = 0;
  printf("----------------------------\n");
  while (tab[i])
    {
      printf("%s\n", tab[i]);
      i++;
    }
  printf("------------------------------\n");
}

void		my_show_list_cmd(t_lst *list)
{
  while (list)
    {
      my_show_tab(list->cmd);
      list = list->next;
    }
}

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
  int	i = 0;
  /*
  buff = xmalloc(sizeof(char *) * 4);
  buff[0] = "test:\tzjmp\t%0";
  buff[1] = "\tlive\t%42";
  buff[2] = "\tlive\t%21";
  buff[3] = NULL;
  */
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
      i++;
    }
  //  my_show_list_cmd(first);
  close (fd);
  return (first);
}

char	*my_fill_buff(char *str, int fd)
{
  int	new_fd;
  t_lst	*list;
  char	*buff;

  buff = xmalloc(sizeof(char) * 2);
  new_fd = xopen(str, O_RDONLY);
  list = function(new_fd);
  if (list == NULL)
    {
      my_putstr("Empty file.\n", 2);
      exit(EXIT_SUCCESS);
    }
  else
    parse_list(list, fd);
  return (buff);
}

int	my_cmd_list_size(t_lst *list)
{
  int	i;

  i = 0;
  while (list)
    {
      i++;
      list = list->next;
    }
  return (i);
}

void	parse_list(t_lst *list, int fd)
{
  char	*biggy_buff;
  int	len;
  int	i;

  i = 0;
  biggy_buff = xmalloc(sizeof(char) * 1);
  while (list)
    {
      write_in_buff(list->cmd, &len, biggy_buff);
      list = list->next;
      i++;
    }
  write(fd, biggy_buff, len);
}
