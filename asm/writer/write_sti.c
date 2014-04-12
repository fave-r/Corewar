/*
** write_sti.c for write_sti in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 11 15:44:53 2014 alex-odet
** Last update Sat Apr 12 20:34:08 2014 alex-odet
*/

#include "struct.h"

int		*write_sti(char *args, int *len, int fd)
{
  char		**args_tab;
  char		val;

  args_tab = my_str_to_wordtab(args, ",");
  len += write(fd, &op_tab[10].code, 1);
  val = encode_octet(args);
  len += write(fd, &val, 1);
  write_sti_arg(args_tab[0], len, fd);
  write_sti_arg(args_tab[0], len, fd);
  write_sti_arg(args_tab[0], len, fd);
  return (len);
}

void		write_sti_arg(char *arg, int *len, int fd)
{
  char		val;
  int		size_i;
  short int	size_s;
  
if (arg[0] == 'r')
    {
      arg++;
      val = my_getnbr(arg);
      len += write(fd, &val, REG_SIZE);
    }
  else if (arg[0] == '%')
    {
      arg++;
      size_i = my_getnbr(arg);
      convert_endian(&size_i, my_endian());
      len += write(fd, &size_i, sizeof(int));
    }
  else
    {
      size_s = my_getnbr(arg);
      convert_short_endian(&size_s, my_endian());
      len += write(fd, &size_s, sizeof(short int));
    }
}
