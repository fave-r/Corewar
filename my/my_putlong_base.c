/*
** my_putnbr_base.c for my_putnbr_base in /home/odet_a/rendu/Piscine-C-Jour_06/ex_15
** 
** Made by alexandre.odet
** Login   <odet_a@epitech.net>
** 
** Started on  Mon Oct  7 20:30:16 2013 alexandre.odet
** Last update Fri Mar 14 08:50:56 2014 Thibaut Lopez
*/

void	my_putchar(unsigned char c, int fd);

int	my_strlen(char *str);

int	my_putlong_base(unsigned long nb, char *base, int *i, int fd)
{
  int	a;
  int	len_base;

  len_base = my_strlen(base);
  a = nb % len_base;
  nb = nb / len_base;
  (*i)++;
  if (nb > 0)
    my_putlong_base(nb, base, i, fd);
  my_putchar(base[a], fd);
  return (*i);
}
