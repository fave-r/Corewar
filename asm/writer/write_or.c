/*
** write_or.c for write_or in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 11 14:47:57 2014 alex-odet
** Last update Fri Apr 11 23:12:37 2014 alex-odet
*/

#include "struct.h"

char    *write_or(char *args, int *len)
{
  char  **args_tab;
  int   size;
  char  *ret;
  int   index;
  int   tmp_size;

  tmp_size = 3;
  args_tab = my_str_to_wordtab(args, ",");
  size = size_to_malloc(args_tab, 0);
  ret = xmalloc(sizeof(char) * (size + 1));
  ret[0] = op_tab[6].code;
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

char	*write_xor(char *args, int *len)
{
  char  **args_tab;
  int   size;
  char  *ret;
  int   index;
  int   tmp_size;

  tmp_size = 3;
  args_tab = my_str_to_wordtab(args, ",");
  size = size_to_malloc(args_tab, 0);
  ret = xmalloc(sizeof(char) * (size + 1));
  ret[0] = op_tab[7].code;
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
