/*
** encode_function.c for encode_function in /home/alex-odet/work/Corewar/asm/writer
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr  9 13:04:49 2014 alex-odet
** Last update Thu Apr 10 09:51:38 2014 alex-odet
*/

#include "struct.h"

char	*my_write_st(char *args, int *len)
{
  char	**args_tab;
  char	*tmp;
  int	size;

  args_tab = args_to_wordtab(args);
  size = size_to_malloc(args_tab);
  tmp = xmalloc(sizeof(char) * (size + 1));
  tmp[0] = op_tab[2].code;
  tmp[1] = encode_octet(args);
  tmp[2] = my_getnbr(copy_reg_value(args_tab[0]));
  if (args_tab[1][0] == 'r')
    tmp[size] = my_getnbr(copy_reg_value(args_tab[1]));
  else
    write_ind_st(args_tab[1], tmp);
  tmp[size + 1] = 0;
    len += size;
  return (tmp);
}

char	*write_ind_st(char *args, char *tmp)
{
  int	end;
  char	*s_ret;

  end = my_getnbr(args);
  convert_endian(&end, my_endian());
  s_ret = (char *)&end;
  tmp[3] = s_ret[0];
  tmp[4] = s_ret[1];
  tmp[5] = s_ret[2];
  tmp[6] = s_ret[3];
  return (tmp);
}
