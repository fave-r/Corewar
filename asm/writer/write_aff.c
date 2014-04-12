/*
** write_aff.c for write_aff in /home/alex-odet/work/Corewar/asm/writer
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr 10 14:47:40 2014 alex-odet
** Last update Sat Apr 12 20:01:03 2014 alex-odet
*/

#include "struct.h"

int	*write_aff(char *arg, int *len, int fd)
{
  char	val;

  len += write(fd, &op_tab[15].code, 1);
  val = encode_octet(arg);
  len += write(fd, &val, 1); 
  arg++;
  val = my_getnbr(arg);
  len += write(fd, &val, REG_SIZE);
  return (len);
}
