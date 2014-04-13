/*
** check_st.c for corewar in /home/blackbird/work/Corewar/asm/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun Apr  6 17:09:13 2014 romaric
** Last update Sun Apr 13 22:15:47 2014 romaric
*/

#include "struct.h"

void	errorstone(char *cmd)
{
  my_printf(2, "u've to put a reg first for this instruction : %s\n", cmd);
  exit(EXIT_FAILURE);
}

void	errorsttwo(void)
{
  my_printf(2, "wrong value for reg\n");
  exit(EXIT_FAILURE);
}

void	check_stmore(char *args, int i)
{
  if (args[i] == '-')
    {
      if (args[i + 1] < '0' || args[i + 1] > '9')
	{
	  my_printf(2, "wrong value : %s\n", args);
	  exit(EXIT_FAILURE);
	}
    }
  else if (args[i] < '0' || args[i] > '9')
    {
      my_printf(2, "wrong value : %s\n", args);
      exit(EXIT_FAILURE);
    }
}

void	check_st(char *args, char *cmd)
{
  int	i;

  i = 0;
  if (args[0] != 'r')
      errorstone(cmd);
  if (args[1] < '1' || args[1] > '9')
      errorsttwo();
  else if (args[2] != ',')
    if (args[2] < '0' || args[2] > '6' || args[1] != '1')
	errorsttwo();
  while (args[i] != ',')
    i++;
  i++;
  if (args[i] == 'r')
    {
      if (args[i + 1] < '1' || args[i + 1] > '9')
	errorsttwo();
      else if (args[i + 2] != '\0')
	if (args[i + 2] < '0' || args[i + 2] > '6' || args[i + 1] != '1')
	  errorsttwo();
    }
  else
    check_stmore(args, i);
}
