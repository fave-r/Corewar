/*
** my_getnbr.c for corewar in /home/blackbird/work/Corewar/my
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun Apr 13 00:13:39 2014 romaric
** Last update Sun Apr 13 00:13:42 2014 romaric
*/

int	nbrsign(char *str)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  while (*(str + i) == '-' || *(str + i) == '+')
    {
      if (*(str + i) == '-')
	{
	  k = k + 1;
	}
      i = i + 1;
    }
  k = k % 2;
  return (k);

}

int	my_getnbr(char *str)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = nbrsign(str);
  while (*(str + i) < '0' || *(str + i) > '9')
    {
      i = i + 1;
    }
  while (*(str + i) >= '0' && *(str + i) <= '9')
    {
      if (j < ((-2147483647 - k + (*(str + i) - 48)) / 10))
	return (0);
      else
	{
	  j = (10 * j) - (*(str + i) - 48);
	  i = i + 1;
	}
    }
  if (k == 0)
    j = j * -1;
  return (j);
}

