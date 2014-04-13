/*
** write_lld.c for write_lld in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr 11 21:43:59 2014 alex-odet
** Last update Sun Apr 13 22:37:49 2014 romaric
*/

#include "struct.h"

void		write_lld(char *args, t_size *p, int fd, t_lab *lab)
{
  char		val;
  char		**args_tab;

  args_tab = my_str_to_wordtab(args, ", ");
  p->len += write(fd, &op_tab[12].code, 1);
  val = encode_octet(args);
  p->len += write(fd, &val, 1);
  write_lld_arg(args_tab[0], p, fd, lab);
  args_tab[1]++;
  val = my_getnbr(args_tab[1]);
  p->len += write(fd, &val, 1);
}

void		write_lld_arg(char *arg, t_size *p, int fd, t_lab *lab)
{
  int		size;
  short	int	size_end;

  if (arg[0] == '%')
    {
      arg++;
      size = (arg[1] != ':') ? my_getnbr(arg) :
	find_good_lab(lab, arg) - p->size;
      convert_endian(&size, my_endian());
      p->len += write(fd, &size, sizeof(int));
    }
  else
    {
      size_end = my_getnbr(arg);
      convert_short_endian(&size_end, my_endian());
      p->len += write(fd, &size_end, sizeof(short int));
    }
}
