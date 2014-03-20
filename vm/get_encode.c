/*
** get_encode.c for get_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 16:33:41 2014 Thibaut Lopez
** Last update Thu Mar 20 17:33:42 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	get_nbr_action(unsigned char *mem, int pc, int len)
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
  if (len == 2)
    nb = (short int)nb;
  else if (len == 1)
    nb = (char)nb;
  return (nb);
}

int	**get_encode(unsigned char *mem, int pc)
{
  int	i;
  int	add;
  int	puis;
  int	**tab;

  tab = xmalloc(4 * sizeof(int *)); //tableau principal de 4 cases, parce que 4 arguments
  puis = 256;
  i = 0;
  add = 2;
  while (i < 4)
    {
      tab[i] = xmalloc(3 * sizeof(int));//tableau de 3 cases
      tab[i][0] = mem[pc + 1] % puis / (puis / 4);//case 0 : récupération du type de l'argument (1 = registre, 2 = direct, 3 = indirect, 0 = pas d'argument)
      puis /= 4;
      if (tab[i][0] == 1) 
	tab[i][1] = 1;
      else if (tab[i][0] == 2)
	tab[i][1] = (mem[pc] == 10 || mem[pc] == 11 || mem[pc] == 14) ? 2 : 4;
      else
	tab[i][1] = (tab[i][0] == 3) ? 2 : 0; //case 1 : nombre d'octet que prend l'argument (registre = 1, direct = 2 ou 4, indirect = 2)
      tab[i][2] = get_nbr_action(mem, pc + add, tab[i][1]); // case 2 : récupérer la valeur de l'argument
      add += tab[i][1];
      i++;
    }
  return (tab);
}
