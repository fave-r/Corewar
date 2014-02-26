/*
** my_putnbr.c for my_putnbr in /home/blackbird/work/my_putnbr
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun Nov 17 17:01:56 2013 romaric
** Last update Wed Feb 26 16:44:08 2014 romaric
*/

void    my_putnbr(int n)
{
  if (n < 0)
    {
      my_putchar('-');
      n = -n;
    }
  if (n >= 10)
    {
      my_putnbr(n / 10);
      my_putnbr(n % 10);
    }
  else
    my_putchar(48 + n);
}
