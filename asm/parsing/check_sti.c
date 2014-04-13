/*
** check_sti.c for corewar in /home/blackbird/work/Corewar/asm/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Apr  8 12:51:16 2014 romaric
** Last update Sun Apr 13 22:12:04 2014 romaric
*/

#include "struct.h"

void	check_stinextnnn(char *args, int i)
{
  if (args[i + 1] != ':' && args[i] == '%')
    {
      if (args[i + 1] < '0' || args[i + 1] > '9' || args[i + 1] == '-')
        {
          if (args[i + 1] != '-')
            errorvalue(args);
          else if (args[i + 2] < '0' || args[i + 2] > '9')
            errorvalue(args);
        }
    }
}

void	check_stinextnn(char *args, char *cmd, t_label *list, int i)
{
  i++;
  if (args[i] != 'r' && args[i] != '%')
    {
      my_printf(2, "Bad last argument it must be");
      my_printf(2, " a reg or a direct for : %s\n", cmd);
      exit(EXIT_FAILURE);
    }
  else if (args[i] == 'r')
    {
      if (args[i + 1] < '1' || args[i + 1] > '9')
        errorvaluereg(args);
      else if (args[i + 2] != '\0')
        if (args[i + 2] < '0' || args[i + 2] > '6' || args[i + 1] != '1')
          errorvaluereg(args);
    }
  else if (args[i] == '%' && args[i + 1] == ':'
      && check_label_exist(list, copi_labeldei(args, i)) != 1)
    errorlabel(copi_labeldei(args, i));
  check_stinextnnn(args, i);
}

void	check_stinextn(char *args, char *cmd, t_label *list, int i)
{
  if (args[i] == '%' && args[i + 1] == ':'
      && check_label_exist(list, copi_labeldei(args, i)) != 1)
    errorlabel(copi_labeldei(args, i));
  else if (args[i + 1] != ':' && args[i] == '%')
    {
      if (args[i + 1] < '0' || args[i + 1] > '9' || args[i + 1] == '-')
	{
	  if (args[i + 1] != '-')
            errorvalue(args);
          else if (args[i + 2] < '0' || args[i + 2] > '9')
            errorvalue(args);
        }
    }
  else if (args[i] == 'r')
    {
      if (args[i + 1] < '1' || args[i + 1] > '9')
        errorvaluereg(args);
      else if (args[i + 2] != ',')
        if (args[i + 2] < '0' || args[i + 2] > '6' || args[i + 1] != '1')
          errorvaluereg(args);
    }
  while (args[i] != ',')
    i++;
  check_stinextnn(args, cmd, list, i);
}

void	check_stinext(char *args, char *cmd, t_label *list)
{
  int	i;

  i = 1;
  while (args[i] != ',')
    i++;
  i++;
  if (args[i] != '%' && (args[i] < '0' || args[i] > '9')
      && args[i] != 'r' && args[i] != '-')
    {
      my_printf(2, "Bad argument u can put an indirect");
      my_printf(2, ", a direct value, a reg for second argument\n");
      exit(EXIT_FAILURE);
    }
  check_stinextn(args, cmd, list, i);
}
void	check_sti(char *args, char *cmd, t_label *list)
{
  if (args[0] != 'r')
    {
      my_printf(2, "Bad first argument u can only put a reg\n");
      exit(EXIT_FAILURE);
    }
  else
    {
      if (args[1] < '1' || args[1] > '9')
        errorvaluereg(args);
      else if (args[2] != ',')
        if (args[2] < '0' || args[2] > '6' || args[1] != '1')
          errorvaluereg(args);
    }
  check_stinext(args, cmd, list);
}
