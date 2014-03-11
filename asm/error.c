/*
** error.c for error in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Mar 11 08:04:10 2014 alex-odet
** Last update Tue Mar 11 08:05:47 2014 alex-odet
*/

#include "struct.h"

void	print_header_error()
{
  my_putstr("Bad Header.\n", 2);
  my_putstr("Your Header needs to be like :\n", 2);
  my_putstr(".name \"name_of_the_champion\"\n", 2);
  my_putstr(".comment \"comment_on_your_champion\"\n", 2);
  exit(EXIT_FAILURE);
}
