/*
** check_aff.c for corewar in /home/blackbird/work/Corewar/asm/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Apr  9 13:09:29 2014 romaric
** Last update Sun Apr 13 22:14:16 2014 romaric
*/

#include "struct.h"

void	check_aff(char *args, char *cmd)
{
  if (args[0] != 'r')
    {
      my_printf(2, "U've to put only reg for this instruction : %s\n", cmd);
      exit(EXIT_FAILURE);
    }
  if (args[1] < '1' || args[1] > '9')
    {
      my_printf(2, "wrong value for reg : %c\n", args[1]);
      exit(EXIT_FAILURE);
    }
  else if (args[2] != '\0')
    if (args[2] < '0' || args[2] > '6' || args[1] != '1')
      {
	my_printf(2, "wrong value for reg : %c%c\n", args[1], args[2]);
	exit(EXIT_FAILURE);
      }
}
