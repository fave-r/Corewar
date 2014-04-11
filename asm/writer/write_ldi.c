/*
** write_ldi.c for write_ldi in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 11 14:53:20 2014 alex-odet
** Last update Fri Apr 11 15:24:06 2014 alex-odet
*/

#include "struct.h"

char	*write_ldi(char **args, int *len)
{
  char	*ret;
  int	size;

  tmp = xmalloc(sizeof(char) * my_strlen(args[0]));
  size = size_to_malloc(args);
  len += size;
  ret = xmalloc(sizeof(char) * (size + 1));
  ret[0] = op_tab[9].code;
  ret[1] = encode_octet(args);
  ret[size] = my_getnbr(copy_reg_value(args[2]));
  ret[size + 1] = 0;
  if (args[0][0] == 'r' && args[1][0] == 'r')
    {
      ret[2] = my_getnbr(copy_reg_value(args[0]));
      ret[3] = my_getnbr(copy_reg_value(args[1]));
    }
  else if (args[0][0] == '%')
    copy_arg(args[0], ret);
  else if (args[1][0] == '%')
    copy_arg_second(args[1], ret);
  return (ret);
}

void	copy_arg(char *arg, char *ret)
{
  char		*tmp;
  short int	end;
  char		*s_ret;

  if (arg[0] == '%')
    {
      tmp = xmalloc(sizeof(char) * my_strlen(arg) + 1);
      tmp = copy_dir_value(arg);
      end = my_getnbr(tmp);
      free(tmp);
      convert_short_endian(&end, my_endian());
      s_ret = (char *)&end;
      ret[2] = s_ret[0];
      ret[3] = s_ret[1];   
    }
  else
    {
      end = my_getnbr(arg);
      convert_short_endian(&end, my_endian());
      s_ret = (char *)&end;
      ret[2] = s_ret[0];
      ret[3] = s_ret[1];
    }
}

void	copy_arg_second(char *arg, char *ret)
{
  char		*tmp;
  short int	end;
  char		s_ret;

  if (arg[0] == '%')
    {
      tmp = xmalloc(sizeof(char) * my_strlen(arg) + 1);
      tmp = copy_dir_value(arg);
      end = my_getnbr(tmp);
      free(tmp);
      convert_short_endian(&end, my_endian());
      s_ret = (char *)&end;
      ret[4] = s_ret[0];
      ret[5] = s_ret[0];
    }
  else
    {
      end = my_getnbr(arg);
      convert_short_endian(&end, my_endian());
      s_ret = (char *)&end;
      ret[4] = s_ret[0];
      ret[5] = s_ret[1];
    }
}
