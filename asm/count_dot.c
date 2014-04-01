/*
** count_dot.c for count_dot in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Apr  1 09:49:14 2014 alex-odet
** Last update Tue Apr  1 14:16:15 2014 alex-odet
*/

#include "struct.h"

int	count_dot(char *str, int i, char c)
{
  int	n;

  n = 0;
  while (str[i])
    {
      if (str[i] == c)
	n++;
      i++;
    }
  return (n);
}
