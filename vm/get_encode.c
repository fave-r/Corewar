/*
** get_encode.c for get_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 16:33:41 2014 Thibaut Lopez
** Last update Fri Mar 14 17:36:25 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	get_nbr_action(char *mem, int pc, int len)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (i < len)
    {
      nb = nb * 256 + mem[pc + i];
      i++;
    }
  return (nb);
}

int	**get_encode(char *mem, int pc)
{
  int	i;
  int	puis;
  int	**tab;
  int	add;

  tab = xmalloc(4 * sizeof(int *));
  puis = 256;
  i = 0;
  add = 0;
  while (i < 4)
    {
      tab[i] = xmalloc(3 * sizeof(int));
      tab[i][0] = mem[pc + 1] % puis / ((puis / 4 == 0) ? 1 : puis / 4);
      puis /= 4;
      if (tab[i][0] == 1)
	tab[i][1] = 1;
      else if (tab[i][0] == 2)
	tab[i][1] = (mem[pc] == 10 || mem[pc] == 11 || mem[pc] == 14) ? 2 : 4;
      else
	tab[i][1] = (tab[i][0] == 3) ? 2 : 0;
      tab[i][2] = get_nbr_action(mem, pc + add, tab[i][1]);
      add += tab[i][1];
      i++;
    }
  return (tab);
}
