/*
** write_ld.c for write_ld in /home/alex-odet/work/Corewar/asm/writer
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  9 17:16:18 2014 alex-odet
** Last update Sat Apr 12 13:51:59 2014 alex-odet
*/

#include "struct.h"

char		*my_write_ld(char *args, int *len)
{
  int		size;
  char		*ret;
  char		**args_tab;

  args_tab = my_str_to_wordtab(args, "\t,");
  size = size_to_malloc(args_tab, 0);
  ret = xmalloc(sizeof(char) * (size + 1));
  ret[0] = op_tab[1].code;
  ret[1] = encode_octet(args);
  my_write_ld_args(args_tab, ret, size);
  ret[size + 1] = 0;
  *len += size;
  return (ret);
}

char		*my_write_ld_args(char **args, char *ret, int size)
{
  char		reg_value;
  int		save;
  short int	save_end;
  char		*tmp;
  char		*s_ret;

  tmp = (args[0][0] == '%') ? copy_dir_value(args[0]) : my_strdup(args[0]);
  save = my_getnbr(tmp);
  save_end = my_getnbr(tmp);
  free(tmp);
  (args[0][0] == '%') ? convert_short_endian(&save_end, my_endian()) :
    convert_endian(&save, my_endian());
  s_ret = (args[0][0] == '%') ? (char *)&save_end : (char *)&save;
  ret[2] = s_ret[0];
  ret[3] = s_ret[1];
  if (args[0][0] != '%')
    {
      ret[4] = s_ret[2];
      ret[5] = s_ret[3];
    }
  reg_value = my_getnbr(copy_reg_value(args[1]));
  ret[size] = reg_value;
  return (ret);
}
