/*
** write_add.c for write_add in /home/alex-odet/work/Corewar/asm/writer
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr 10 09:53:11 2014 alex-odet
** Last update Sun Apr 13 19:51:03 2014 
*/

#include "struct.h"

int	*write_add(char *args, int *len, int fd, t_lab *lab)
{
  char	**args_tab;
  char	val;

  (void)lab;
  args_tab = my_str_to_wordtab(args, ",");
  *len += write(fd, &op_tab[3].code, 1);
  val = encode_octet(args);
  *len += write(fd, &val, 1);
  args_tab[0]++;
  val = my_getnbr(args_tab[0]);
  *len += write(fd, &val, 1);
  args_tab[1]++;
  val = my_getnbr(args_tab[1]);
  *len += write(fd, &val, 1);
  args_tab[2]++;
  val = my_getnbr(args_tab[2]);
  *len += write(fd, &val, 1);
  return (len);
}
