/*
** copy_reg_value.c for copy_reg_value in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr  9 14:58:40 2014 alex-odet
** Last update Thu Apr 10 01:18:14 2014 alex-odet
*/

#include "struct.h"

char	*copy_reg_value(char *args)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  j = 0;
  tmp = xmalloc(sizeof(char) * 3);
  while (args[i] != ',' && args[i] != 0)
    {
      if (args[i] == 'r')
	i++;
      tmp[j] = args[i];
      j++;
      i++;
    }
  tmp[j] = 0;
  return (tmp);
}

char	*copy_dir_value(char *args)
{
  int	i;
  int	j;
  char	*tmp;

  tmp = xmalloc(sizeof(char) * 10);
  i = 0;
  j = 0;
  while (args[i] != ',')
    {
      if (args[i] == '%')
	i++;
      tmp[j] = args[i];
      i++;
      j++;
    }
  tmp[j] = 0;
  return (tmp);
}
