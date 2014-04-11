/*
** write_and.c for write_end in /home/alex-odet/work/Corewar/asm/writer
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr 10 10:01:35 2014 alex-odet
** Last update Fri Apr 11 23:11:56 2014 alex-odet
*/

#include "struct.h"

char	*write_and(char *args, int *len)
{
  char	**args_tab;
  int	size;
  char	*ret;
  int	index;
  int	tmp_size;

  tmp_size = 3;
  args_tab = my_str_to_wordtab(args, ",");
  size = size_to_malloc(args_tab, 0);
  ret = xmalloc(sizeof(char) * (size + 1));
  ret[0] = op_tab[5].code;
  ret[1] = encode_octet(args);
  index = 2;
  index += write_first_arg(args_tab[0], ret, tmp_size);
  tmp_size = index;
  write_first_arg(args_tab[1], ret, tmp_size);
  ret[size] = my_getnbr(copy_reg_value(args_tab[2]));
  ret[size + 1] = 0;
  len+= size;
  return (ret);
}

int	write_first_arg(char *arg, char *ret, int index)
{
  char	*s_ret;
  int	end;

  if (arg[0] == 'r')
    {
      ret[index] = my_getnbr(copy_reg_value(arg));
      index += 1;
    }
  else if (arg[0] == '%')
    {
      end = my_getnbr(copy_dir_value(arg));
      convert_endian(&end, my_endian());
      s_ret = (char *)&end;
      ret[index] = s_ret[0];
      ret[index + 1] = s_ret[1];
      ret[index + 2] = s_ret[2];
      ret[index + 3] = s_ret[3];
      index += 4;
    }
  else
    {
      write_ind_value(arg, ret, index);
      index += 2;
    }
  return (index);
}

void	write_ind_value(char *arg, char *ret, int index)
{
  char	*s_ret;
  int	end;

  end = my_getnbr(my_strdup(arg));
  convert_endian(&end, my_endian());
  s_ret = (char *)&end;
  ret[index] = s_ret[0];
  ret[index + 1] = s_ret[1];
}
