/*
** write_ld.c for write_ld in /home/alex-odet/work/Corewar/asm/writer
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  9 17:16:18 2014 alex-odet
** Last update Sun Apr 13 05:52:22 2014 alex-odet
*/

#include "struct.h"

int		*my_write_ld(char *args, int *len, int fd)
{
  char		reg;
  char		**args_tab;

  args_tab = my_str_to_wordtab(args, ",");
  *len += write(fd, &op_tab[1].code, 1);
  write_ld_first(args_tab[0], len, fd);
  if (args_tab[1][0] == 'r')
    args_tab[1]++;
  reg = my_getnbr(args_tab[1]);
  *len += write(fd, &reg, 1);
  return (len);
}

int		*write_ld_first(char *args, int *len, int fd)
{
  short int	ind;
  int		direct;

  if (args[0] == '%' && args[1] != ':')
    {
      args++;
      direct = (args[1] != ':') ? my_getnbr(args) : 0;
      convert_endian(&direct, my_endian());
      *len += write(fd, &direct, sizeof(int));
    }
  else if (args[0] != '%')
    {
      ind = my_getnbr(args);
      convert_short_endian(&ind, my_endian());
      *len += write(fd, &ind, sizeof(short int));
    }
  return (len);  
}
