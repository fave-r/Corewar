/*
** encode_function.c for encode_function in /home/alex-odet/work/Corewar/asm/writer
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr  9 13:04:49 2014 alex-odet
** Last update Wed Apr  9 13:05:22 2014 alex-odet
*/

#include "struct.h"

char    *my_write_ld(char *args, int *len)
{
  int   i;
  int   save;
  char  *ret;
  char  *tmp;

  i = 0;
  ret = xmalloc(sizeof(char) * 8);
  tmp = xmalloc(sizeof(char) * 5);
  while (args[i] != ',')
    {
      if (args[0] == '%')
	i++;
      tmp[i] = args[i];
      i++;
    }
  tmp[i] = 0;
  save = my_getnbr(tmp);
  free(tmp);
  ret[0] = op_tab[1].code;
  ret[1] = encode_octet(args);
  ret[7] = 0;
  ret = my_write_ld_next(args, ret, save);
  *len += 6;
  return (ret);
}

char	*my_write_ld_next(char *args, char *ret, int save)
{
  char		*s_ret;
  short int	save_v;
  int		save_s;

  if (args[0] != '%')
      convert_endian(&save_s, my_endian());
  else
    convert_short_endian(&save_v, my_endian());
  save_v = save;
  s_ret = (char *)&save_v;
  ret[2] = s_ret[0];
  ret[3] = s_ret[1];
  ret[4] = s_ret[2];
  ret[5] = s_ret[3];
  ret[6] = s_ret[4];
  return (ret);  
}
