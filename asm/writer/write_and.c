/*
** write_and.c for write_end in /home/alex-odet/work/Corewar/asm/writer
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr 10 10:01:35 2014 alex-odet
** Last update Sun Apr 13 19:58:54 2014 
*/

#include "struct.h"

int		*write_and(char *args, int *len, int fd, t_lab *lab)
{
  char		**args_tab;
  char		val;

  args_tab = my_str_to_wordtab(args, ",");
  *len += write(fd, &op_tab[5].code, 1);
  val = encode_octet(args);
  *len += write(fd, &val, 1);
  write_arg_and(args_tab[0], len, fd, lab);
  write_arg_and(args_tab[1], len, fd, lab);
  write_arg_and(args_tab[2], len, fd, lab);
  return (len);
}

int		*write_arg_and(char *args, int *len, int fd, t_lab *lab)
{
  int		size;
  char		val;
  short int	size_end;

  if (args[0] == 'r')
    {
      args++;
      val = my_getnbr(args);
      *len += write(fd, &val, 1);
    }
  else if (args[0] == '%')
    {
      args++;
      size = (args[1] != ':') ? my_getnbr(args) : find_good_lab(lab, args);
      convert_endian(&size, my_endian());
      *len += write(fd, &size, sizeof(int));
    }
  else
    {
      size_end = my_getnbr(args);
      convert_short_endian(&size_end, my_endian());
      *len += write(fd, &size_end, sizeof(short int));
    }
  return (len);
}
