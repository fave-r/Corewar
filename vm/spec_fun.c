/*
** spec_fun.c for spec_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 17:06:30 2014 Thibaut Lopez
** Last update Wed Mar 19 17:09:54 2014 Thibaut Lopez
*/

#include "vm.h"

void	ifree(int **tab, int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
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
