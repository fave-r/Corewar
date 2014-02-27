/*
** my_putnbr.c for Corewar in /home/blackbird/work/Corewar/my
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Feb 26 16:46:01 2014 romaric
** Last update Wed Feb 26 16:46:04 2014 romaric
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
