/*
** my_putnbr_base.c for Corewar in /home/blackbird/work/Corewar/my
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Feb 26 16:47:20 2014 romaric
** Last update Wed Feb 26 16:47:23 2014 romaric
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
