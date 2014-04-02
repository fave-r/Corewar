/*
** check_live.c for check_live in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Tue Apr  1 15:32:49 2014 alex-odet
** Last update Wed Apr  2 17:22:48 2014 romaric
*/

#include "struct.h"

char	*copi_label(char *args)
{
  char	*str;
  int	i;
  int	j;

  i = 2;
  j = 0;
  str = xmalloc((my_strlen(args) - 1) * sizeof(char));
  if (args[1] == ':')
    {
      while (i <= my_strlen(args))
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

void	check_live(char *args, char *cmd)
{
  if (args[0] != '%')
    {
      my_printf(2, "%s needs a direct value.\n", cmd);
      my_putstr("you don't have put one.\n", 2);
      my_putstr("a direct value is writed like this : %value.\n", 2);
      exit(EXIT_FAILURE);
    }
  else if (args[1] == ':' && check_label_exist(&list, copi_label(args) == 1))
    {
      cmd[1] = 'c';
    }
  else if ((args[1] < '0' || args[1] > '9') || args[1] == '-')
    {
      if (args[1] != '-')
	{
	  my_printf(2, "Wrong Value: %s\n", args);
	  exit(EXIT_FAILURE);
	}
      else if (args[2] < '0' || args[2] > '9')
	{
	  my_printf(2, "Wrong Value: %s\n", args);
	  exit(EXIT_FAILURE);
	}
    }
}
