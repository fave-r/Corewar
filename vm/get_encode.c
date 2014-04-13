/*
** get_encode.c for get_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 16:33:41 2014 Thibaut Lopez
** Last update Sun Apr 13 19:15:06 2014 romaric
*/

#include "vm.h"
#include "my.h"

void		print_on_mem(t_cor *cor, int to_add, int pc)
{
  int		i;
  unsigned char	*tmp;

  i = (cor->endian == 1) ? 3 : 1;
  tmp = (unsigned char *)&to_add;
  cor->mem[mod_mem(pc + i)] = tmp[0];
  i += (cor->endian == 1) ? -1 : 1;
  cor->mem[mod_mem(pc + i)] = tmp[1];
  i += (cor->endian == 1) ? -1 : 1;
  cor->mem[mod_mem(pc + i)] = tmp[2];
  i += (cor->endian == 1) ? -1 : 1;
  cor->mem[mod_mem(pc + i)] = tmp[3];
}

int		get_nbr_action(unsigned char *mem, int pc, int len)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (i < len)
    {
      nb = nb * 256 + mem[mod_mem(pc + i)];
      i++;
    }
  if (len == 2)
    nb = (short int)nb;
  else if (len == 1)
    nb = (unsigned char)nb;
  return (nb);
}

int		**get_encode(unsigned char *mem, int pc)
{
  int		i;
  int		add;
  int		puis;
  int		**tab;

  tab = xmalloc(4 * sizeof(int *));
  puis = 256;
  i = 0;
  add = 2;
  while (i < 4)
    {
      tab[i] = xmalloc(3 * sizeof(int));
      tab[i][0] = mem[mod_mem(pc + 1)] % puis / (puis / 4);
      puis /= 4;
      tab[i][1] = (tab[i][0] == 1) ? 1 : (tab[i][0] == 2) ?
	(mem[mod_mem(pc)] == 10 || mem[mod_mem(pc)] == 11 ||
	 mem[mod_mem(pc)] == 14) ?
	2 : 4 : (tab[i][0] == 3) ? 2 : 0;
      tab[i][2] = get_nbr_action(mem, mod_mem(pc + add), tab[i][1]);
      add += tab[i][1];
      i++;
    }
  return (tab);
}
