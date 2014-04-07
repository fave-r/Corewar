/*
** bad_value.c for bad_value in /home/alex-odet/work/Corewar/asm/Error
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr  2 12:45:21 2014 alex-odet
** Last update Wed Apr  2 12:46:09 2014 alex-odet
*/

#include "struct.h"

void	no_direct()
{
  my_putstr("Live needs a direct value.\n", 2);
  my_putstr("you don't have put one.\n", 2);
  my_putstr("a direct value is writed like this : %value.\n", 2);
  exit(EXIT_FAILURE);
}
