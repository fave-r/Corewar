/*
** encode_function.c for encode_function in /home/alex-odet/work/Corewar/asm/writer
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  9 13:04:49 2014 alex-odet
** Last update Sun Apr 13 22:36:34 2014 romaric
*/

#include "struct.h"

void		my_write_st(char *args, t_size *p, int fd,
			    __attribute__((unused))t_lab *lab)
{
  char		**args_tab;
  short int	size_end;
  char		encode;
  char		val;

  args_tab = my_str_to_wordtab(args, "\t,");
  p->len = p->len + write(fd, &op_tab[2].code, 1);
  encode = encode_octet(args);
  p->len = p->len + write(fd, &encode, 1);
  args_tab[0]++;
  val = my_getnbr(args_tab[0]);
  p->len = p->len + write(fd, &val, 1);
  if (args_tab[1][0] == 'r')
    {
      args_tab[1]++;
      val = my_getnbr(args_tab[1]);
      p->len = p->len + write(fd, &val, 1);
    }
  else
    {
      size_end = my_getnbr(args_tab[1]);
      convert_short_endian(&size_end, my_endian());
      p->len = p->len + write(fd, &size_end, sizeof(short int));
    }
}
