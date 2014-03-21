/*
** check_cmd.c for check_cmd in /home/alex-odet/work/Corewar/asm/Parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Mar 20 14:24:38 2014 alex-odet
** Last update Fri Mar 21 13:15:52 2014 alex-odet
*/

#include "struct.h"

void	check_cmd(char *str)
{
  int	fd;
  char	*tmp;

  fd = xopen(str, O_RDONLY);
  while ((tmp = get_next_line(fd)))
    {
      if (tmp[0] == '\t')
	  cmd_exist(tmp);
    }
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
  printf("str = %s\n", str);
  while ((str[i] != '\t' && str[i] != ' ') && str[i])
      {
	cmd[j] = str[i];
	j++;
	i++;
      }
  cmd[j] = 0;
  j = 0;
  printf("cmd = %s\n", cmd);
  while (op_tab[j].mnemonique)
    {
      if (my_strcmp(op_tab[j].mnemonique, cmd) == 0)
	my_putstr("good\n", 1);
      j++;
    }
}

