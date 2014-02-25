/*
** parsing.c for parsing in /home/odet_a/rendu/CPE_2014_corewar/asm
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Mon Feb 17 18:54:21 2014 
** Last update Mon Feb 17 18:56:06 2014 
*/

#include "../struct.h"
#include "../op.h"

void	check_instructions(char *str)
{
  int	fd;
  char	*tmp;
  char	*cmd;

  fd = xopen(str, O_RDONLY);
  while ((tmp = get_next_line(fd)))
    {
      if (strcmp("\n", tmp) != 0 && tmp[0] != '.')
	cmd = cmd_by_line(tmp);
      if (cmd != NULL)
	my_putstr(cmd, 1);
      my_putstr("\n", 1);
    }
}

void	check_my_arg(char *str)
{
  if (str[my_strlen(str) - 2] != '.' || str[my_strlen(str) - 1] != 's')
    {
      my_putstr("Not valid format.\n", 2);
      exit(EXIT_FAILURE);
    }
}

char	*cmd_by_line(char *str)
{
  int	i;
  char	*cmd;

  i = 0;
  cmd = xmalloc(sizeof(char) * 5);
  while (str[i] !=  ' ' && str[i] != 0 && str[i] != 10)
    {
      cmd[i] = str[i];
      i++;
    }
  cmd[i] = 0;
  return (cmd);
}

void	parser(char *str)
{
  check_my_arg(str);
  check_instructions(str);
}
