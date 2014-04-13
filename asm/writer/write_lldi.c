/*
** write_lldi.c for write_lldi in /home/alex-odet/work/Corewar/asm/writer
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr 11 22:12:37 2014 alex-odet
** Last update Sun Apr 13 22:35:47 2014 romaric
*/

#include "struct.h"

void		write_lldi(char *args, t_size *p, int fd, t_lab *lab)
{
  char		val;
  char		**args_tab;

  args_tab = my_str_to_wordtab(args, ",");
  p->len += write(fd, &op_tab[13].code, 1);
  val = encode_octet(args);
  p->len += write(fd, &val, 1);
  write_lldi_arg(args_tab[0], p, fd, lab);
  write_lldi_arg(args_tab[1], p, fd, lab);
  write_lldi_arg(args_tab[2], p, fd, lab);
}

void		write_lldi_arg(char *args, t_size *p, int fd, t_lab *lab)
{
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
      size_end = (args[1] != ':') ? my_getnbr(args) :
	find_good_lab(lab, args) - p->size;
      convert_short_endian(&size_end, my_endian());
      p->len += write(fd, &size_end, sizeof(short int));
    }
  else
    {
      size_end = my_getnbr(args);
      convert_short_endian(&size_end, my_endian());
      p->len += write(fd, &size_end, sizeof(short int));
    }
}
