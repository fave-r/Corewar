/*
** check_add.c for corewar in /home/blackbird/work/Corewar/asm/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Apr  7 12:58:30 2014 romaric
** Last update Mon Apr  7 13:21:49 2014 romaric
*/

#include "struct.h"

void	checkregnext(char *args, int *i, char *cmd)
{
  int	j;

  while (args[*i] != ',')
    *i = *i + 1;
  *i = *i + 1;
  if (args[*i] != 'r')
    {
      my_printf(2, "U've to put only reg for this instruction : %s\n", cmd);
      exit(EXIT_FAILURE);
    }
  *i = *i + 1;
  if (args[*i] < '1' || args[*i] > '9')
    {
      my_printf(2, "wrong value for reg : %c\n", args[*i]);
      exit(EXIT_FAILURE);
    }
  *i = *i + 1;
  j = *i - 1;
  if (args[*i] != ',' && args[*i] != '\0')
    if (args[*i] < '0' || args[*i] > '6' || args[j] != '1')
      {
	my_printf(2, "wrong value for reg : %c%c\n", args[j], args[*i]);
        exit(EXIT_FAILURE);
      }
}

void	check_add(char *args, char *cmd)
{
  int	i;

  i = 1;
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
  else if (args[2] != ',')
    if (args[2] < '0' || args[2] > '6' || args[1] != '1')
      {
	my_printf(2, "wrong value for reg : %c%c\n", args[1], args[2]);
	exit(EXIT_FAILURE);
      }
  checkregnext(args, &i, cmd);
  checkregnext(args, &i, cmd);
}
