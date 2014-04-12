/*
** write_lld.c for write_lld in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 11 21:43:59 2014 alex-odet
** Last update Sat Apr 12 23:47:50 2014 alex-odet
*/

#include "struct.h"

int		*write_lld(char *args, int *len, int fd)
{
  char		val;
  char		**args_tab;

  args_tab = my_str_to_wordtab(args, ",");
  len += write(fd, &op_tab[12].code, 1);
  val = encode_octet(args);
  len += write(fd, &val, 1);
  write_lld_arg(args_tab[0], len, fd);
  args_tab[1]++;
  val = my_getnbr(args_tab[1]);
  write(fd, &val, REG_SIZE);
  return (len);
}

int		*write_lld_arg(char *arg, int *len, int fd)
{
  int		size;
  short	int	size_end;

  if (arg[0] == '%')
    {

      arg[0]++;
      size = (arg[1] != ':') ? my_getnbr(arg) : 0;
      convert_endian(&size, my_endian());
      len += write(fd, &size, sizeof(int));
    }
  else
    {
      size_end = my_getnbr(arg);
      convert_short_endian(&size_end, my_endian());
      len += write(fd, &size_end, sizeof(short int));
    }
  return (len);
}
