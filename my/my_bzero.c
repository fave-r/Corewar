/*
** my_bzero.c for my_bzero in /home/thibaut.lopez/Corewar/Corewar/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 16:24:50 2014 Thibaut Lopez
** Last update Wed Feb 26 20:37:07 2014 Thibaut Lopez
*/

#include "my.h"

void	my_mem_set(int *s, size_t n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      s[i] = 0;
      i++;
    }
}
