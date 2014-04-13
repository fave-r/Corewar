/*
** check_ld.c for corewar in /home/blackbird/work/Corewar/asm/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun Apr  6 12:21:40 2014 romaric
** Last update Sun Apr 13 22:13:35 2014 romaric
*/

#include "struct.h"

void	moresize(int *size, int *i)
{
  *size = *size + 1;
  *i = *i + 1;
}

char	*copi_labelde(char *args)
{
  char	*str;
  int	i;
  int	j;
  int	size;

  i = 2;
  j = 0;
  size = 0;
  while (args[i] != ',')
    moresize(&size, &i);
  i = 2;
  str = xmalloc((size + 1) * sizeof(char));
  if (args[1] == ':')
    {
      while (args[i] != ',')
        {
	  str[j] = args[i];
          j++;
          i++;
        }
      str[j++] = '\0';
      return (str);
    }
  return (NULL);
}

void	check_reg(char *args, char *cmd)
{
  int	i;

  i = 0;
  while (args[i] != ',')
    i++;
  i = i + 1;
  if (args[i] != 'r')
    printthisseconderror(cmd);
  i++;
  if (args[i] < '1' || args[i] > '9')
    errorvaluereg(args);
  else if (args[i + 1] != '\0')
    if (args[i + 1] < '0' || args[i + 1] > '6' || args[i] != '1')
      errorvaluereg(args);
}

void	check_ld(char *args, char *cmd, t_label *list)
{
  if (args[0] != '%' && (args[0] < '0' || args[0] > '9') && args[0] != '-')
    printthiserror(cmd);
  else if (args[1] == ':' && check_label_exist(list, copi_labelde(args)) != 1)
    errorlabel(copi_labelde(args));
  else if (args[1] != ':' && args[0] == '%')
    {
      if (args[1] < '0' || args[1] > '9' || args[1] == '-')
	{
	  if (args[1] != '-')
	    errorvalue(args);
	  else if (args[2] < '0' || args[2] > '9')
	    errorvalue(args);
	}
      check_reg(args, cmd);
    }
}
