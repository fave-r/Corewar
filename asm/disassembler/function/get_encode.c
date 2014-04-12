/*
** get_encode.c for get_encode in /home/thibaut.lopez/Corewar/Corewar/vm
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Wed Mar 12 16:33:41 2014 Thibaut Lopez
** Last update Sat Apr 12 14:50:08 2014 romaric
*/

#include "dasm.h"
#include "my.h"

int	get_nbr_action(unsigned char *buff, int pc, int len)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (i < len)
    {
      nb = nb * 256 + buff[pc + i];
      i++;
    }
  if (len == 2)
    nb = (short int)nb;
  else if (len == 1)
    nb = (char)nb;
  return (nb);
}

int	**init_tab()
{
  int	i;
  int	**tab;

  tab = xmalloc(4 * sizeof(int *));
  i = 0;
  while (i < 4)
    {
      tab[i] = xmalloc(3 * sizeof(int));
      i++;
    }
  return (tab);
}

int	**get_encode(unsigned char *buff, int i, int size)
{
  int	j;
  int	add;
  int	puis;
  int	**tab;

  tab = init_tab();
  puis = 256;
  j = 0;
  add = 2;
  if (i > size - add)
    return (NULL);
  while (j < 4)
    {
      tab[j][0] = buff[i + 1] % puis / (puis / 4);
      puis /= 4;
      tab[j][1] = (tab[j][0] == 1) ? 1 : (tab[j][0] == 2) ?
	(buff[i] == 10 || buff[i] == 11 || buff[i] == 14) ?
	2 : 4 : (tab[j][0] == 3) ? 2 : 0;
      tab[j][2] = get_nbr_action(buff, i + add, tab[j][1]);
      add += tab[j][1];
      if (i > size - add)
	return (ifree(tab, 4));
      j++;
    }
  return (tab);
}
