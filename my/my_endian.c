/*
** my_endian.c for my_endian in /home/thibaut.lopez/Corewar/Corewar/vm
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Thu Feb 27 09:31:58 2014 Thibaut Lopez
** Last update Mon Mar 24 13:52:26 2014 Thibaut Lopez
*/

#include "my.h"

int	my_endian()
{
  int	x;
  char	*y;

  x = 1;
  y = (char *) & x;
  if (*y)
    return (1);
  else
    return (0);
}

int	convert_endian(int *nb, int endian)
{
  if (endian == 1)
    {
      *nb = ((*nb << 8) & 0xFF00FF00FF00FF00ULL)
	| ((*nb >> 8) & 0x00FF00FF00FF00FFULL);
      *nb = ((*nb << 16) & 0xFFFF0000FFFF0000ULL)
	| ((*nb >> 16) & 0x0000FFFF0000FFFFULL);
    }
  return (*nb);
}
