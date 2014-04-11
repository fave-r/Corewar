/*
** write_lldi.c for write_lldi in /home/alex-odet/work/Corewar/asm/writer
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 11 22:12:37 2014 alex-odet
** Last update Fri Apr 11 22:57:55 2014 alex-odet
*/

#include "struct.h"

char		*write_lldi(char *args, int *len)
{
  int		size;
  char		**args_tab;
  char		*ret;
  int		tmp;
  int		index;

  args_tab = my_str_to_wordtab(args, ",");
  size = size_to_malloc(args_tab, 1);
  ret = xmalloc(sizeof(char) * (size + 1));
  ret[0] = op_tab[13].code;
  ret[1] = encode_octet(args);
  index = 2;
  tmp = copy_arg_lldi(args_tab[0], ret, index);
  index += tmp;
  copy_arg_lldi(args_tab[1], ret, index);
  ret[size] = my_getnbr(copy_reg_value(args_tab[2]));
  ret[size + 1] = 0;
  len += size;
  return (ret);
}

int		copy_arg_lldi(char *args, char *ret, int index)
{
  short int	end;
  char		*s_ret;

  if (args[0] == 'r')
    {
      ret[index] = my_getnbr(copy_reg_value(args));
      index += 1;      
    }
  else if (args[0] == '%')
    end = my_getnbr(copy_dir_value(args));
  else
    end = my_getnbr(args);
  convert_short_endian(&end, my_endian());
  s_ret = (char *)&end;
  ret[index] = s_ret[0];
  ret[index + 1] = s_ret[1];
  index += 2;
  return (index);
}
