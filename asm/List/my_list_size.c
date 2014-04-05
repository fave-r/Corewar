/*
** my_list_size.c for my_list_size in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Sat Apr  5 17:43:18 2014 alex-odet
** Last update Sat Apr  5 17:44:15 2014 alex-odet
*/

#include "struct.h"

int	my_file_list_size(t_file *list)
{
  int	i;

  i = 0;
  while (list != NULL)
    {
      i++;
      list = list->next;
    }
  return (i);
}
