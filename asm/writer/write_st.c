/*
** encode_function.c for encode_function in /home/alex-odet/work/Corewar/asm/writer
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  9 13:04:49 2014 alex-odet
** Last update Sat Apr 12 15:36:03 2014 alex-odet
*/

#include "struct.h"

int	*my_write_st(char *args, int *len, int fd)
{
  char	**args_tab;
  int	size;
  char	encode;
  char	val;

  args_tab = my_str_to_wordtab(args, "\t,");
  len += write(fd, &op_tab[2].code, 1);
  encode = encode_octet(args);
  len += write(fd, &encode, 1);
  args_tab[0]++;
  val = my_getnbr(args_tab[0]);
  len += write(fd, &val, REG_SIZE);
  if (args_tab[1][0] == 'r')
    {
      args_tab[1]++;
      val = my_getnbr(args_tab[1]);
      len += write(fd, &val, REG_SIZE);
    }
  else
    {
      size = my_getnbr(args_tab[1]);
      convert_endian(&size, my_endian());
      write(fd, &size, sizeof(short int));
    }
  return (len);
}
