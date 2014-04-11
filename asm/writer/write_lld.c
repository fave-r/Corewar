/*
** write_lld.c for write_lld in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 11 21:43:59 2014 alex-odet
** Last update Fri Apr 11 21:56:08 2014 alex-odet
*/

#include "struct.h"

char	*write_lld(char *args, int *len)
{
  int	size;
  char	**args_tab;
  char	*ret;

  args_tab = my_str_to_wordtab(args, ",");
  size = size_to_malloc(args_tab);
  ret = xmalloc(sizeof(char) * (size + 1));
  ret[0] = op_tab[12].code;
  ret[1] = encode_octet(args);
  copy_arg(args_tab[0], ret);
   ret[size] = my_getnbr(copy_reg_value(args_tab[1]));
  ret[size + 1] = 0;
  len += size;
  return (ret);
}

void	copy_arg(char *arg, char *ret)
{
  int	end;
  char	*s_ret;

  if (args_tab[0] == '%')
    {
      end = my_getnbr(copy_dir_value(args_tab[0]));
      convert_short_endian(&end, my_endian());
      s_ret = (char *)&end;
      ret[2] = s_ret[0];
      ret[3] = s_ret[1];
    }
  else
    {
      end = my_getnbr(args_tab[0]);
      convert_short_endian(&end, my_endian());
      s_ret = (char *)&end;
      ret[2] = s_ret[0];
      ret[3] = s_ret[1];
    } 
}
