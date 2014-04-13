/*
** write_sub.c for write_sub in /home/alex-odet/work/Corewar/asm/writer
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Thu Apr 10 09:56:35 2014 alex-odet
** Last update Sun Apr 13 22:36:50 2014 romaric
*/

#include "struct.h"

void	write_sub(char *args, t_size *p, int fd, t_lab *lab)
{
  char	**args_tab;
  char	val;

  (void)lab;
  args_tab = my_str_to_wordtab(args, ",");
  p->len += write(fd, &op_tab[4].code, 1);
  val = encode_octet(args);
  p->len += write(fd, &val, 1);
  args_tab[0]++;
  val = my_getnbr(args_tab[0]);
  p->len += write(fd, &val, 1);
  args_tab[1]++;
  val = my_getnbr(args_tab[1]);
  p->len += write(fd, &val, 1);
  args_tab[2]++;
  val = my_getnbr(args_tab[2]);
  p->len += write(fd, &val, 1);
}
