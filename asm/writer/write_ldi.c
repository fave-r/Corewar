/*
** write_ldi.c for write_ldi in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 11 14:53:20 2014 alex-odet
** Last update Sun Apr 13 00:12:03 2014 alex-odet
*/

#include "struct.h"

int		*write_ldi(char *args, int *len, int fd)
{
  char		**args_tab;
  char		ret;

  args_tab = my_str_to_wordtab(args, ",");
  len += write(fd, &op_tab[9].code, 1);
  ret = encode_octet(args);
  len += write(fd, &ret, 1);
  write_ldi_arg(args_tab[0], len, fd);
  write_ldi_arg(args_tab[1], len, fd);
  write_ldi_arg(args_tab[2], len, fd);
  return (len);
}

int		*write_ldi_arg(char *arg, int *len, int fd)
{
  char		val;
  short int	size_end;

  if (arg[0] == 'r')
    {
      arg++;
      val = my_getnbr(arg);
      len += write(fd, &val, REG_SIZE);
    }
  else if (arg[0] == '%')
    {
      arg++;
      size_end = (arg[1] != ':') ? my_getnbr(arg) : 0;
      convert_short_endian(&size_end, my_endian());
      len += write(fd, &size_end, sizeof(short int));
    }
  else
    {
      size_end = my_getnbr(arg);
      convert_short_endian(&size_end, my_endian());
      len += write(fd, &size_end, sizeof(short int));
    }
  return (len);
}
