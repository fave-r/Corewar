/*
** check_arg.c for check_arg in /home/alex-odet/work/Corewar/asm/Parsing
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Apr  1 09:11:47 2014 alex-odet
** Last update Tue Apr  1 11:17:08 2014 romaric
*/

#include "struct.h"

void	check_arg(char *cmd, char *args)
{
  //printf("cmd = %s\nargs = %s\n", cmd, args);
  if (my_strcmp(cmd, "live") == 0)
    {
      if (args[0] != '%' || (args[1] < '0') || (args[1] > '9'))
	{
	  my_putstr("Live has a bad Argument.\nLive needs a direct value.\n", 2);
	  exit(EXIT_FAILURE);
	}
    }
}
