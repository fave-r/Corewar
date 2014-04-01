/*
** check_live.c for check_live in /home/alex-odet/work/Corewar/asm/Parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Apr  1 15:32:49 2014 alex-odet
** Last update Tue Apr  1 16:05:00 2014 alex-odet
*/

#include "struct.h"

void	check_live(char *args)
{
  if (args[0] != '%')
    {
      my_putstr("Live needs a direct value.\n", 2);
      my_putstr("you don't have put one.\n", 2);
      my_putstr("a direct value is writed like this : %value.\n", 2);
      exit(EXIT_FAILURE);
    }
  else if (args[1] < '0' || args[1] > '9' || args[1] != '-')
    {
      my_putstr("Wrong Value.\n", 2);
      exit(EXIT_FAILURE);
    }
}
