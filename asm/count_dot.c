/*
** count_dot.c for count_dot in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Apr  1 09:49:14 2014 alex-odet
** Last update Tue Apr  1 09:50:16 2014 alex-odet
*/

#include "struct.h"

int	count_dot(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (str[i])
    {
      if (str[i] == '.')
	n++;
      i++;
    }
  return (n);
}
