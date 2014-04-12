/*
** write_or.c for write_or in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 11 14:47:57 2014 alex-odet
** Last update Sat Apr 12 23:49:30 2014 alex-odet
*/

#include "struct.h"

int		*write_or(char *args, int *len, int fd)
{
  char		**args_tab;
  char		val;

  args_tab = my_str_to_wordtab(args, ",");
  len += write(fd, &op_tab[6].code, 1);
  val = encode_octet(args);
  len += write(fd, &val, 1);
  write_arg_or(args_tab[0], len, fd);
  write_arg_or(args_tab[1], len, fd);
  write_arg_or(args_tab[2], len, fd);
  return (len);
}

int		*write_arg_or(char *args, int *len, int fd)
{
  int		size;
  char		val;
  short int	size_end;

  if (args[0] == 'r')
    {
      args++;
      val = my_getnbr(args);
      len += write(fd, &val, REG_SIZE);
    }
  else if (args[0] == '%')
    {
      args++;
      size = (args[1] != ':') ? my_getnbr(args) : 0;
      convert_endian(&size, my_endian());
      len += write(fd, &size, sizeof(int));
    }
  else
    {
      size_end = my_getnbr(args);
      convert_short_endian(&size_end, my_endian());
      len += write(fd, &size_end, sizeof(short int));
    }
  return (len);
}

int		*write_xor(char *args, int *len, int fd)
{
  char		**args_tab;
  char		val;

  args_tab = my_str_to_wordtab(args, ",");
  len += write(fd, &op_tab[7].code, 1);
  val = encode_octet(args);
  len += write(fd, &val, 1);
  write_arg_and(args_tab[0], len, fd);
  write_arg_and(args_tab[1], len, fd);
  write_arg_and(args_tab[2], len, fd);
  return (len);
}

int		*write_arg_xor(char *args, int *len, int fd)
{
  int           size;
  char          val;
  short int     size_end;

  if (args[0] == 'r')
    {
      args++;
      val = my_getnbr(args);
      len += write(fd, &val, REG_SIZE);
    }
  else if (args[0] == '%')
    {
      args++;
      size = (args[1] != ':') ? my_getnbr(args) : 0;
      convert_endian(&size, my_endian());
      len += write(fd, &size, sizeof(int));
    }
  else
    {
      size_end = my_getnbr(args);
      convert_short_endian(&size_end, my_endian());
      len += write(fd, &size_end, sizeof(short int));
    }
  return (len);
}
