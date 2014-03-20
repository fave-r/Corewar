/*
** count_tab.c for count_tab in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Mar 20 16:54:54 2014 alex-odet
** Last update Thu Mar 20 16:59:20 2014 alex-odet
*/

#include "struct.h"

int	count_tab(char *str)
{
  int	i;
  int	tab;

  i = 0;
  tab = 0;
  while (str[i])
    {
      if (str[i] == '\t')
	tab++;
      i++;
    }
  return (tab);
}
