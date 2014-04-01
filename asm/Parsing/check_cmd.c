/*
** check_cmd.c for check_cmd in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Thu Mar 20 14:24:38 2014 alex-odet
** Last update Tue Apr  1 11:45:40 2014 romaric
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
	if (i == 0)
	  {
	    line = my_str_to_wordtab(tmp);
	    printf("%s\n", line[1]);
	    if (line[1] != NULL)
	      {
		check_cmd_arg(line[1], cmd);
		check_arg(cmd, line[len_tab(line) - 1]);
	      }
	  }
      i = 0;
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
  cmd = xmalloc(sizeof(char) * (my_strlen(str) + 1));
  str[i - 1] != '\t' ? (cmd[0] = str[0]) : (j = 0);
  while (str[i] != '\t' && str[i] != ' ' && str[i])
    cmd[j++] = str[i++];
  cmd[j] = 0;
  if (j != 0 && cmd[j - 1] == ':' &&
      (str[j + 2] >= 'a' && str[j + 2] <= 'z'))
    {
      cmd = cmd_next_label(cmd, &j, i, str);
      *bool = 1;
    }
  if (j != 0 && cmd[j - 1] != ':' && my_strlen(cmd) > 1 && my_strchr(':', cmd) != 0 && my_strchr('#', cmd) != 0 && my_strchr(';', cmd) != 0)
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
    print_bad_instruction(cmd);
}

void	check_cmd_arg(char *args, char *cmd)
{
  int	i;
  int	nbr_coma;
  int	k;

  i = -1;
  k = 0;
  nbr_coma = 0;
  //printf("cmd = %s ; args = %s\n", cmd, args);
  while (args[++i] != '\0')
    {
      if (args[i] == ',')
	nbr_coma++;
    }
  while (my_strcmp(op_tab[k].mnemonique, cmd) != 0)
    k++;
  nbr_coma++;
  if (op_tab[k].nbr_args != nbr_coma)
    {
      my_printf(2, "The instruction : %s Doesn't take %d arguments but %d\n", cmd, nbr_coma, op_tab[k].nbr_args);
      exit(EXIT_FAILURE);
    }
}
