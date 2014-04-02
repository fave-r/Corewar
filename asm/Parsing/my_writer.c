/*
** my_writer.c for my_writer in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Mar 26 10:43:51 2014 alex-odet
** Last update Wed Apr  2 13:47:46 2014 alex-odet
*/

#include "struct.h"

char	*my_write_live(char *value, int *len)
{
  int	save;
  char	*ret;
  char	*s_ret;

  if (value[0] != ':')
    save = my_getnbr(value);
  else
    save = 0;
  ret = xmalloc(sizeof(char) * 6);
  ret[0] = 1;
  ret[5] = 0;
  convert_endian(&save, my_endian());
  s_ret = (char *)&save;
  ret[1] = s_ret[0];
  ret[2] = s_ret[1];
  ret[3] = s_ret[2];
  ret[4] = s_ret[3];
  *len += 5;
  return (ret);
}

char	*write_live(char *buff, char *cmd)
{
  my_strcat(buff, hexa_value(cmd));
  return (buff);
}
