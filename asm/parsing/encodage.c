/*
** encodage.c for encodagz in /home/alex-odet/work/Corewar/asm/parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Mon Apr  7 18:19:53 2014 alex-odet
** Last update Mon Apr  7 18:19:58 2014 alex-odet
*/

int	encode_octet(char *args)
{
  int	i;
  int nb;
  int power;

  i = 0;
  nb = 0;
  power = 64;
  while (args[i] != 0)
    {
      if (args[i] == '%')
	nb += 2 * power;
      else if (args[i] == 'r')
	nb += 1 * power;
      else
	nb += 3 * power;
      while (args[i] != ',' && args[i])
	i++;
      i++;
      power /= 4;
    }
  return (nb);
}
