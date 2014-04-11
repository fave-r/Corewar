/*
** write_add.c for write_add in /home/alex-odet/work/Corewar/asm/writer
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr 10 09:53:11 2014 alex-odet
** Last update Thu Apr 10 09:56:08 2014 alex-odet
*/

#include "struct.h"

char	*write_add(char *args, int *len)
{
  char	**args_tab;
  int	size;
  char	*ret;

  args_tab = args_to_wordtab(args);
  size = size_to_malloc(args_tab);
  ret = xmalloc(sizeof(char) * (size + 1));
  ret[0] = op_tab[3].code;
  ret[1] = encode_octet(args);
  ret[2] = my_getnbr(copy_reg_value(args_tab[0]));
  ret[3] = my_getnbr(copy_reg_value(args_tab[1]));
  ret[4] = my_getnbr(copy_reg_value(args_tab[2]));
  ret[size + 1] = 0;
  len += size;
  return (ret);
}
