/*
** write_ldi.c for write_ldi in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr 11 14:53:20 2014 alex-odet
** Last update Sun Apr 13 22:35:32 2014 romaric
*/

#include "struct.h"

void		write_ldi(char *args, t_size *p, int fd, t_lab *lab)
{
  char		**args_tab;
  char		ret;

  args_tab = my_str_to_wordtab(args, ",");
  p->len += write(fd, &op_tab[9].code, 1);
  ret = encode_octet(args);
  p->len += write(fd, &ret, 1);
  write_ldi_arg(args_tab[0], p, fd, lab);
  write_ldi_arg(args_tab[1], p, fd, lab);
  write_ldi_arg(args_tab[2], p, fd, lab);
}

void		write_ldi_arg(char *arg, t_size *p, int fd, t_lab *lab)
{
  char		val;
  short int	size_end;

  if (arg[0] == 'r')
    {
      arg++;
      val = my_getnbr(arg);
      p->len += write(fd, &val, 1);
    }
  else if (arg[0] == '%')
    {
      arg++;
      size_end = (arg[1] != ':') ? my_getnbr(arg) :
	find_good_lab(lab, arg) - p->size;
      convert_short_endian(&size_end, my_endian());
      p->len += write(fd, &size_end, sizeof(short int));
    }
  else
    {
      size_end = my_getnbr(arg);
      convert_short_endian(&size_end, my_endian());
      p->len += write(fd, &size_end, sizeof(short int));
    }
}
