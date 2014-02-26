/*
** my_putnbr_base.c for my_putnbr_base in /home/blackbird/work/my_putnbr_base
** 
** Made by romaric
** Login   <fave_r@epitech.net>
** 
** Started on  Thu Nov 14 10:54:10 2013 romaric
** Last update Thu Nov 14 10:57:45 2013 romaric
*/

void    my_putnbr_base(int nb, char *base)
{
  int   result;
  int   div;
  int   sibase;

  sibase = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  div = 1;
  while ((nb / div) >= sibase)
    div = div * sibase;
  while (div > 0)
    {
      result = (nb / div) % sibase;
      my_putchar(base[result]);
      div = div / sibase;
    }
}
