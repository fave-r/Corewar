/*
** size_to_malloc.c for size_to_malloc in /home/alex-odet/work/Corewar/asm/writer
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr  9 17:09:24 2014 alex-odet
** Last update Fri Apr 11 09:46:23 2014 alex-odet
*/

#include "struct.h"

int	size_to_malloc(char **args, int boool)
{
  int	size;
  int	i;

  i = 0;
  size = 2;
  while (args[i])
    {
      if (args[i][0] == 'r')
	size += 1;
      else if (args[i][0] == '%')
	size += (boool == 1) ? 2 : 4;
      else
	size += 2;
      i++;
    }
  return (size);
}
