/*
** my_writer.c for my_writer in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Mar 26 10:43:51 2014 alex-odet
** Last update Sun Apr 13 20:15:31 2014 
*/

#include "struct.h"

int		*my_write_live(char *value, int *len, int fd, t_lab *lab)
{
  int	size;

  if (value[1] == ':')
    size = find_good_lab(lab, value);
  else
    {
      value++;
      size = my_getnbr(value);
    }
  *len += write(fd, &op_tab[0].code, 1);
  convert_endian(&size, my_endian());
  *len += write(fd, &size, sizeof(int));
  return (len);
}

int		*my_write_zjmp(char *value, int *len, int fd, t_lab *lab)
{
  short int	save_v;

  if (value[0] == '%' && value[1] != ':')
    {
      value++;
      save_v = my_getnbr(value);
    }
  else
    save_v = find_good_lab(lab, value);
  *len += write(fd, &op_tab[8].code, 1);
  convert_short_endian(&save_v, my_endian());
  *len += write(fd, &save_v, sizeof(short int));
  return (len);
}

int		*my_write_fork(char *value, int *len, int fd, t_lab *lab)
{
  short int	save_v;

  if (value[0] == '%' && value[1] != ':')
    {
      value++;
      save_v = my_getnbr(value);
    }
  else
    save_v = find_good_lab(lab, value);
  *len += write(fd, &op_tab[11].code, 1);
  convert_short_endian(&save_v, my_endian());
  *len += write(fd, &save_v, sizeof(short int));
  return (len);
}

int		* my_write_lfork(char *value, int *len, int fd, t_lab *lab)
{
  short int	save_v;

  if (value[0] == '%' && value[1] != ':')
    {
      value++;
      save_v = my_getnbr(value);
    }
  else
    save_v = find_good_lab(lab, value);
  *len += write(fd, &op_tab[14].code, 1);
  convert_short_endian(&save_v, my_endian());
  *len += write(fd, &save_v, sizeof(short int));
  return (len);
}
