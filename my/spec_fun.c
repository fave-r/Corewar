/*
** spec_fun.c for spec_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 17:06:30 2014 Thibaut Lopez
** Last update Fri Apr  4 19:31:43 2014 Thibaut Lopez
*/

#include "../op.h"
#include "my.h"

int	mod_mem(int nb)
{
  while (nb < 0)
    nb += MEM_SIZE;
  return (nb % MEM_SIZE);
}

int	prog_size_error(char *path)
{
  my_printf(2, "Error : %s have a wrong prog_size.\n", path);
  return (1);
}

int	**ifree(int **tab, int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  return (NULL);
}

void	sfree(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    {
      free(str[i]);
      i++;
    }
  free(str);
}
