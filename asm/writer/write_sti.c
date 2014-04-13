/*
** write_sti.c for write_sti in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr 11 15:44:53 2014 alex-odet
** Last update Sun Apr 13 22:38:20 2014 romaric
*/

#include "struct.h"

void		write_sti(char *args, t_size *p, int fd, t_lab *lab)
{
  char		**args_tab;
  char		val;

  args_tab = my_str_to_wordtab(args, ",");
  p->len += write(fd, &op_tab[10].code, 1);
  val = encode_octet(args);
  p->len += write(fd, &val, 1);
  write_sti_arg(args_tab[0], p, fd, lab);
  write_sti_arg(args_tab[1], p, fd, lab);
  write_sti_arg(args_tab[2], p, fd, lab);
}

void		write_sti_arg(char *arg, t_size *p, int fd, t_lab *lab)
{
  char		val;
  short int	size_s;

  if (arg[0] == 'r')
    {
      arg++;
      val = my_getnbr(arg);
      p->len += write(fd, &val, 1);
    }
  else if (arg[0] == '%')
    {
      arg++;
      size_s = (arg[1] != ':') ? my_getnbr(arg) :
	find_good_lab(lab, arg) - p->size;
      convert_short_endian(&size_s, my_endian());
      p->len += write(fd, &size_s, sizeof(short int));
    }
  else
    {
      size_s = my_getnbr(arg);
      convert_short_endian(&size_s, my_endian());
      p->len += write(fd, &size_s, sizeof(short int));
    }
}
