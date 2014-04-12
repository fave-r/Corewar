/*
** write_sti.c for write_sti in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 11 15:44:53 2014 alex-odet
** Last update Fri Apr 11 23:11:00 2014 alex-odet
*/

#include "struct.h"

char		*write_sti(char *args, int *len)
{
  int		size;
  char		*ret;
  char		**args_tab;
  int		index;
  int		tmp;

  args_tab = my_str_to_wordtab(args, ",");
  size = size_to_malloc(args_tab, 1);
  ret = xmalloc(sizeof(char) * (size + 1));
  ret[0] = op_tab[10].code;
  ret[1] = encode_octet(args);
  ret[2] = my_getnbr(copy_reg_value(args_tab[0]));
  index = 3;
  tmp = copy_arg_first(args_tab[1], ret, index);
  index += tmp;
  copy_arg_first(args_tab[2], ret, index);
  ret[size + 1] = 0;
  len += size;
  return (ret);
}

int		copy_arg_first(char *arg, char *ret, int index)
{
  char		*s_ret;
  short int	end;

  if (arg[0] == 'r')
    {
      ret[index] = my_getnbr(copy_reg_value(arg));
      index += 1;
    }
  else if (arg[0] == '%')
    {
      end = my_getnbr(copy_dir_value(arg));
      convert_short_endian(&end, my_endian());
      s_ret = (char *)&end;
      ret[index] = s_ret[0];
      ret[index + 1] = s_ret[1];
      index += 2;
    }
  else
    {
      end = my_getnbr(arg);
      convert_short_endian(&end, my_endian());
      s_ret = (char *)&end;
      ret[index] = s_ret[0];
      ret[index + 1] = s_ret[1];
      index += 2;
    }
  return (index);
}
