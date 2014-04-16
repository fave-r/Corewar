/*
** my_list_size.c for corewar in /home/blackbird/work/Corewar/asm/list
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Apr 16 18:05:01 2014 romaric
** Last update Wed Apr 16 18:06:41 2014 romaric
*/

#include "struct.h"

int	my_cmd_size(t_lst *list)
{
  int	i;

  i = 0;
  while(list)
    {
      i++;
      list = list->next;
    }
  return (i);
}
