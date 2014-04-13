/*
** write_aff.c for write_aff in /home/alex-odet/work/Corewar/asm/writer
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Thu Apr 10 14:47:40 2014 alex-odet
** Last update Sun Apr 13 21:48:11 2014 
*/

#include "struct.h"

void	write_aff(char *arg, t_size *p, int fd, t_lab *lab)
{
  char	val;

  (void)lab;
  p->len += write(fd, &op_tab[15].code, 1);
  val = encode_octet(arg);
  p->len += write(fd, &val, 1);
  arg++;
  val = my_getnbr(arg);
  p->len += write(fd, &val, 1);
}
