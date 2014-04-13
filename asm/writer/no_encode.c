/*
** my_writer.c for my_writer in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Mar 26 10:43:51 2014 alex-odet
** Last update Sun Apr 13 02:23:30 2014 alex-odet
*/

#include "struct.h"

int		*my_write_live(char *value, int *len, int fd)
{
  int		save;

  if (value[0] == '%')
    {
      value++;
      save = (value[1] != ':') ? my_getnbr(value) : 0;
    }
  else
    save = 0;
  len += write(fd, &op_tab[0].code, 1);
  convert_endian(&save, my_endian());
  len += write(fd, &save, sizeof(int));
  return (len);
}

int		*my_write_zjmp(char *value, int *len, int fd)
{
  short int	save_v;

  if (value[0] == '%' && value[1] != ':')
    {
      value++;
      save_v = my_getnbr(value);
    }
  else
    save_v = 0;
  len += write(fd, &op_tab[8].code, 1);
  convert_short_endian(&save_v, my_endian());
  len += write(fd, &save_v, sizeof(short int));
  return (len);
}

int		*my_write_fork(char *value, int *len, int fd)
{
  short int	save_v;

  if (value[0] == '%' && value[1] != ':')
    {
      value++;
      save_v = my_getnbr(value);
    }
  else
    save_v = 0;
  len += write(fd, &op_tab[11].code, 1);
  convert_short_endian(&save_v, my_endian());
  len += write(fd, &save_v, sizeof(short int));
  return (len);
}

int	 *my_write_lfork(char *value, int *len, int fd)
{
  short int	save_v;

  if (value[0] == '%' && value[1] != ':')
    {
      value++;
      save_v = my_getnbr(value);
    }
  else
    save_v = 0;
  len += write(fd, &op_tab[14].code, 1);
  convert_short_endian(&save_v, my_endian());
  len += write(fd, &save_v, sizeof(short int));
  return (len);
}
