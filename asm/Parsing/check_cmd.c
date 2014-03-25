/*
** check_cmd.c for check_cmd in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Thu Mar 20 14:24:38 2014 alex-odet
** Last update Tue Mar 25 13:22:00 2014 romaric
*/

#include "struct.h"

void	check_cmd(char *str)
{
  int	fd;
  char	*tmp;
  int	i;
  char	*cmd;
  char	**line;

  i = 0;
  fd = xopen(str, O_RDONLY);
  cmd = NULL;
  while ((tmp = get_next_line(fd)))
    {
      //my_printf(1, "%s\n", tmp);
      if (tmp[0] == '\t' || my_strchr(':', tmp) != -1)
	cmd = cmd_exist(tmp, &i);
      if (cmd != NULL)
	{
	  //printf("%d\n", i);
	  //my_printf(1, "%s\n", cmd);
	  if (i == 0)
	    {
	      line = my_str_to_wordtab(tmp, '\t');
	      printf("%s\n", line[0]);
	    }
	  i = 0;
	}
    }
  close (fd);
}

char	*cmd_exist(char *str, int *bool)
{
  int	j;
  int	i;
  char	*cmd;

  i = 1;
  j = 1;
  cmd = xmalloc(sizeof(char) * 6);
  str[i - 1] != '\t' ? (cmd[0] = str[i - 1]) : (j = 0);
  while (str[i] != '\t' && str[i] != ' ' && str[i])
    cmd[j++] = str[i++];
  if (cmd[j - 1] == ':' && str[j + 2] >= 'A')
    {
      cmd = cmd_next_label(cmd, &j, i, str);
      *bool = 1;
    }
  cmd[j] = 0;
  if (cmd[j - 1] != ':')
    {
      check_cmd_exist(cmd);
      return (cmd);
    }
  return (NULL);
}

char	*cmd_next_label(char *cmd, int *j, int i, char *str)
{
  my_memset(cmd, my_strlen(cmd));
  *j = 0;
  i++;
  while (str[i] != '\t' && str[i] != ' ' && str[i])
    {
      cmd[*j] = str[i];
      *j = *j + 1;
      i++;
    }
  return (cmd);
}

void	check_cmd_exist(char *cmd)
{
  int	j;
  int	x;

  j = 0;
  x = 1;
  while (op_tab[j].mnemonique)
    {
      if (my_strcmp(op_tab[j].mnemonique, cmd) == 0)
	x = 0;
      j++;
    }
  if (op_tab[j].mnemonique == NULL && x == 1)
    {
      my_putstr("The instruction : ", 2);
      my_putstr(cmd, 2);
      my_putstr(" Doesn't exists.\n", 2);
      exit(EXIT_FAILURE);
    }
}
