/*
** my_show_list.c for my_show_list in /home/alex-odet/work/Corewar/asm/List
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Mar 21 00:10:32 2014 alex-odet
** Last update Fri Mar 21 00:11:32 2014 alex-odet
*/

#include "struct.h"

void	my_show_list(t_label *list)
{
  while (list)
    {
      my_putstr(list->name, 1);
      my_putchar('\n', 1);
      list = list->next;
    }
}
