/*
** write_or.c for write_or in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr 11 14:47:57 2014 alex-odet
** Last update Sun Apr 13 22:38:02 2014 romaric
*/

#include "struct.h"

void		write_or(char *args, t_size *p, int fd, t_lab *lab)
{
  char		**args_tab;
  char		val;

  args_tab = my_str_to_wordtab(args, ",");
  p->len += write(fd, &op_tab[6].code, 1);
  val = encode_octet(args);
  p->len += write(fd, &val, 1);
  write_arg_or(args_tab[0], p, fd, lab);
  write_arg_or(args_tab[1], p, fd, lab);
  write_arg_or(args_tab[2], p, fd, lab);
}

void		write_arg_or(char *args, t_size *p, int fd, t_lab *lab)
{
  int		size;
  char		val;
  short int	size_end;

  if (args[0] == 'r')
    {
      args++;
      val = my_getnbr(args);
      p->len += write(fd, &val, 1);
    }
  else if (args[0] == '%')
    {
      args++;
      size = (args[1] == ':') ? find_good_lab(lab, args) - p->size
	: my_getnbr(args);
      convert_endian(&size, my_endian());
      p->len += write(fd, &size, sizeof(int));
    }
  else
    {
      size_end = my_getnbr(args);
      convert_short_endian(&size_end, my_endian());
      p->len += write(fd, &size_end, sizeof(short int));
    }
}

void		write_xor(char *args, t_size *p, int fd, t_lab *lab)
{
  char		**args_tab;
  char		val;

  args_tab = my_str_to_wordtab(args, ",");
  p->len += write(fd, &op_tab[7].code, 1);
  val = encode_octet(args);
  p->len += write(fd, &val, 1);
  write_arg_and(args_tab[0], p, fd, lab);
  write_arg_and(args_tab[1], p, fd, lab);
  write_arg_and(args_tab[2], p, fd, lab);
}

void		write_arg_xor(char *args, t_size *p, int fd, t_lab *lab)
{
  int           size;
  char          val;
  short int     size_end;

  if (args[0] == 'r')
    {
      args++;
      val = my_getnbr(args);
      p->len += write(fd, &val, 1);
    }
  else if (args[0] == '%')
    {
      args++;
      size = (args[1] != ':') ? my_getnbr(args) :
	find_good_lab(lab, args) - p->size;
      convert_endian(&size, my_endian());
      p->len += write(fd, &size, sizeof(int));
    }
  else
    {
      size_end = my_getnbr(args);
      convert_short_endian(&size_end, my_endian());
      p->len += write(fd, &size_end, sizeof(short int));
    }
}
