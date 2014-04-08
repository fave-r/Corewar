/*
** my_writer.c for my_writer in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Mar 26 10:43:51 2014 alex-odet
** Last update Tue Apr  8 11:22:49 2014 alex-odet
*/

#include "struct.h"

char		*my_write_live(char *value, int *len)
{
  int		save;
  char		*ret;
  char		*s_ret;

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
  int	i = 0;
  while (ret[i])
    printf("in live ret[i] = %d\n", ret[i++]);
  return (ret);
}

char		*my_write_zjmp(char *value, int *len)
{
  int		save;
  short int	save_v;
  char		*ret;
  char		*s_ret;

  if (value[0] != ':')
    save = my_getnbr(value);
  else
    save = 0;
  ret = xmalloc(sizeof(char) * 4);
  ret[0] = 9;
  ret[3] = 0;
  convert_short_endian(&save_v, my_endian());
  save_v = save;
  s_ret = (char *)&save_v;
  ret[1] = s_ret[0];
  ret[2] = s_ret[1];
  *len += 3;
  int	i = 0;
  while (ret[i])
    printf("in zjmp ret[i] = %d\n", ret[i++]);
  return (ret);
}

char		*my_write_fork(char *value, int *len)
{
  int		save;
  short int	save_v;
  char		*ret;
  char		*s_ret;

  save = (value[0] != ':') ? my_getnbr(value) : 0;
  ret = xmalloc(sizeof(char) * 4);
  ret[0] = 12;
  ret[3] = 0;
  convert_short_endian(&save_v, my_endian());
  save_v = save;
  s_ret = (char *)&save_v;
  ret[1] = s_ret[0];
  ret[2] = s_ret[1];
  *len += 3;
  return (ret);
}

char	 *my_write_lfork(char *value, int *len)
{
  int		save;
  short int	save_v;
  char		*ret;
  char		*s_ret;

  save = (value[0] != ':') ? my_getnbr(value) : 0;
  ret = xmalloc(sizeof(char) * 4);
  ret[0] = 16;
  ret[3] = 0;
  convert_short_endian(&save_v, my_endian());
  save_v = save;
  s_ret = (char *)&save_v;
  ret[1] = s_ret[0];
  ret[2] = s_ret[1];
  *len += 3;
  return (ret);
}

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
  ret[0] = 2;
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
