/*
** write_aff.c for write_aff in /home/alex-odet/work/Corewar/asm/writer
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr 10 14:47:40 2014 alex-odet
** Last update Fri Apr 11 23:14:57 2014 alex-odet
*/

#include "struct.h"

char	*write_aff(char *arg, int *len)
{
  char	*ret;
  int	size;

  size = 3;
  len += size;
  ret = xmalloc(sizeof(char) * (size + 1));
  ret[0] = op_tab[15].code;
  ret[1] = encode_octet(arg);
  ret[2] = my_getnbr(copy_reg_value(arg));
  ret[3] = 0;
  return (ret);
}
