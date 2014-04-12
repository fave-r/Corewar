/*
** my_writer.c for my_writer in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Mar 26 10:43:51 2014 alex-odet
** Last update Sat Apr 12 14:10:10 2014 alex-odet
*/

#include "struct.h"

char		*my_write_live(char *value, int *len)
{
  int		save;
  char		*ret;
  char		*s_ret;

  if (value[0] != ':')
    save = my_getnbr(copy_dir_value(value));
  else
    save = 0;
  ret = xmalloc(sizeof(char) * 6);
  ret[0] = op_tab[0].code;
  ret[5] = 0;
  convert_endian(&save, my_endian());
  s_ret = (char *)&save;
  ret[1] = s_ret[0];
  ret[2] = s_ret[1];
  ret[3] = s_ret[2];
  ret[4] = s_ret[3];
  *len += 5;
  
  /*  if (value[0] ==' %')
    {
      value++;
      save = my_getnbr(value);
    }
  else
    save = 0; // ERRROR
  convert_endiant(&save, my_endian());
  len = write(fd, &save, sizeof(int))*/
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
    ret[0] = op_tab[8].code;
    ret[3] = 0;
    convert_short_endian(&save_v, my_endian());
    save_v = save;
    s_ret = (char *)&save_v;
    ret[1] = s_ret[0];
    ret[2] = s_ret[1];
    *len += 3;
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
    ret[0] = op_tab[11].code;
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
    ret[0] = op_tab[14].code;
    ret[3] = 0;
    convert_short_endian(&save_v, my_endian());
    save_v = save;
    s_ret = (char *)&save_v;
    ret[1] = s_ret[0];
    ret[2] = s_ret[1];
    *len += 3;
    return (ret);
  }
