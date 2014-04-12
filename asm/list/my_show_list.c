/*
** my_show_list.c for my_show_list in /home/alex-odet/work/Corewar/asm/List
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Mar 21 00:10:32 2014 alex-odet
** Last update Sat Apr 12 00:55:37 2014 romaric
*/

#include "struct.h"

void	my_show_list(t_label *list)
{
  while (list)
    {
      if (list->name == NULL)
	return;
      else
	{
	  my_putstr(list->name, 1);
	  my_putchar(' ', 1);
	  my_putchar('\n', 1);
	}
      list = list->next;
    }
}

void	my_show_file_list(t_file *list)
{
  while (list)
    {
      if (list->name_file == NULL)
	return;
      else
	my_putstr(list->name_file, 1);
      my_putchar('\n', 1);
      list = list->next;
    }
}
