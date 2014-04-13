/*
** write_lldi.c for write_lldi in /home/alex-odet/work/Corewar/asm/writer
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr 11 22:12:37 2014 alex-odet
** Last update Sun Apr 13 19:58:12 2014 
*/

#include "struct.h"

int		*write_lldi(char *args, int *len, int fd, t_lab *lab)
{
  char		val;
  char		**args_tab;

  args_tab = my_str_to_wordtab(args, ",");
  *len += write(fd, &op_tab[13].code, 1);
  val = encode_octet(args);
  *len += write(fd, &val, 1);
  write_lldi_arg(args_tab[0], len, fd, lab);
  write_lldi_arg(args_tab[1], len, fd, lab);
  write_lldi_arg(args_tab[2], len, fd, lab);
  return (len);
}

int		write_lldi_arg(char *args, int *len, int fd, t_lab *lab)
{
  char		val;
  short int	size_end;

  if (args[0] == 'r')
    {
      args++;
      val = my_getnbr(args);
      *len += write(fd, &val, 1);
    }
  else if (args[0] == '%')
    {
      args++;
      size_end = (args[1] != ':') ? my_getnbr(args) : find_good_lab(lab, args);
      convert_short_endian(&size_end, my_endian());
      *len += write(fd, &size_end, sizeof(short int));
    }
  else
    {
      size_end = my_getnbr(args);
      convert_short_endian(&size_end, my_endian());
      *len += write(fd, &size_end, sizeof(short int));
    }
  return (*len);
}
