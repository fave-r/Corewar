/*
** encode_function.c for encode_function in /home/alex-odet/work/Corewar/asm/writer
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  9 13:04:49 2014 alex-odet
** Last update Sun Apr 13 19:55:06 2014 
*/

#include "struct.h"

int	*my_write_st(char *args, int *len, int fd, t_lab *lab)
{
  char		**args_tab;
  short int	size_end;
  char		encode;
  char		val;

  (void)lab;
  args_tab = my_str_to_wordtab(args, "\t,");
  *len += write(fd, &op_tab[2].code, 1);
  encode = encode_octet(args);
  *len += write(fd, &encode, 1);
  args_tab[0]++;
  val = my_getnbr(args_tab[0]);
  *len += write(fd, &val, 1);
  if (args_tab[1][0] == 'r')
    {
      args_tab[1]++;
      val = my_getnbr(args_tab[1]);
      *len += write(fd, &val, 1);
    }
  else
    {
      size_end = my_getnbr(args_tab[1]);
      convert_short_endian(&size_end, my_endian());
      *len += write(fd, &size_end, sizeof(short int));
    }
  return (len);
}
