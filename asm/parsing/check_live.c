/*
** check_live.c for check_live in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Tue Apr  1 15:32:49 2014 alex-odet
** Last update Fri Apr 11 16:35:09 2014 romaric
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

void	check_live(char *args, char *cmd, t_label *list)
{
  if (args[0] != '%')
    {
      my_printf(2, "%s needs a direct value.\n", cmd);
      my_putstr("you don't have put one.\n", 2);
      my_putstr("a direct value is writed like this : %value.\n", 2);
      exit(EXIT_FAILURE);
    }
  else if (args[0] == '%' && args[1] == ':'
	   && check_label_exist(list, copi_label(args)) != 1)
    errorlabel(copi_label(args));
  else if (args[1] != ':' && args[0] == '%')
    {
      if (args[1] < '0' || args[1] > '9' || args[1] == '-')
        {
          if (args[1] != '-')
            errorvalue(args);
          else if (args[2] < '0' || args[2] > '9')
            errorvalue(args);
	}
    }
}
