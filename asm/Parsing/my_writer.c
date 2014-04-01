/*
** my_writer.c for my_writer in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Mar 26 10:43:51 2014 alex-odet
** Last update Mon Mar 31 13:27:52 2014 alex-odet
*/

#include "struct.h"

int	size_to_malloc(char *cmd)
{
  int	i;

  if (my_strcmp(cmd, "live") == 0 || my_strcmp(cmd, "fork") == 0
      || my_strcmp(cmd, "zjmp") == 0 || my_strcmp(cmd, "lfork") == 0)
    {
      if (my_strcmp(cmd, "live") == 0)
	return (5);
      else
	return (3);
    }
  else
    i = 2;
  return (i);
}

char	*hexa_value(char *cmd)
{
  char	*str;
  int	i;

  str = xmalloc(sizeof(char) * size_to_malloc(cmd));
  return (str);
}

char	*write_in_buff(char *buff, char *cmd)
{
  my_strcat(buff, hexa_value(cmd));
  return (buff);
}
