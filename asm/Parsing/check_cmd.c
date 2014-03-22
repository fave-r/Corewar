/*
** check_cmd.c for check_cmd in /home/alex-odet/work/Corewar/asm/Parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Mar 20 14:24:38 2014 alex-odet
** Last update Sat Mar 22 12:31:51 2014 alex-odet
*/

#include "struct.h"

void	check_cmd(char *str)
{
  int	fd;
  char	*tmp;
  int	i;

  i = 0;
  fd = xopen(str, O_RDONLY);
  while ((tmp = get_next_line(fd)))
    {
      while (tmp[i])
	{
	  if ((tmp[i] == '\t' && i == 0)
	      || (tmp[i] == '\t' && tmp[i - 1] == ':'))
	    cmd_exist(tmp);
	  i++;
	}
    }
  close (fd);
}

void	cmd_exist(char *str)
{
  int	j;
  int	i;
  char	*cmd;
  char	*big_buffer;

  i = 1;
  j = 0;
  cmd = xmalloc(sizeof(char) * 6);
  big_buffer = xmalloc(sizeof(char) * BUFF_SIZE);
  while (str[i] != '\t' && str[i] != ' ' && str[i])
    {
      cmd[j] = str[i];
      j++;
      i++;
    }
  cmd[j] = 0;
  check_cmd_exist(cmd);
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
  if (op_tab[j].mnemonique == NULL && x ==1)
    {
      my_putstr("The instruction : ", 2);
      my_putstr(cmd, 2);
      my_putstr(" Doesn't exists.\n", 2);
      exit(EXIT_FAILURE);
    }
}
