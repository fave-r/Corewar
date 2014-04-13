/*
** my_writer.c for my_writer in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Mar 26 10:43:51 2014 alex-odet
** Last update Sun Apr 13 22:34:48 2014 romaric
*/

#include "struct.h"

void		my_write_live(char *value, t_size *p, int fd, t_lab *lab)
{
  int		size;

  if (value[1] == ':')
    {
      size = find_good_lab(lab, value);
      size = size - p->size;
    }
  else
    {
      value++;
      size = my_getnbr(value);
    }
  p->len += write(fd, &op_tab[0].code, 1);
  convert_endian(&size, my_endian());
  p->len += write(fd, &size, sizeof(int));
}

void		my_write_zjmp(char *value, t_size *p, int fd, t_lab *lab)
{
  short int	save_v;

  if (value[0] == '%' && value[1] != ':')
    {
      value++;
      save_v = my_getnbr(value);
    }
  else
    {
      save_v = find_good_lab(lab, value);
      save_v = save_v - p->size;
    }
  p->len += write(fd, &op_tab[8].code, 1);
  convert_short_endian(&save_v, my_endian());
  p->len += write(fd, &save_v, sizeof(short int));
}

void		my_write_fork(char *value, t_size *p, int fd, t_lab *lab)
{
  short int	save_v;

  if (value[0] == '%' && value[1] != ':')
    {
      value++;
      save_v = my_getnbr(value);
    }
  else
    {
      save_v = find_good_lab(lab, value);
      save_v = save_v - p->size;
    }
  p->len += write(fd, &op_tab[11].code, 1);
  convert_short_endian(&save_v, my_endian());
  p->len += write(fd, &save_v, sizeof(short int));
}

void		my_write_lfork(char *value, t_size *p, int fd, t_lab *lab)
{
  short int	save_v;

  if (value[0] == '%' && value[1] != ':')
    {
      value++;
      save_v = my_getnbr(value);
    }
  else
    {
      save_v = find_good_lab(lab, value);
      save_v = save_v - p->size;
    }
  p->len += write(fd, &op_tab[14].code, 1);
  convert_short_endian(&save_v, my_endian());
  p->len += write(fd, &save_v, sizeof(short int));
}
