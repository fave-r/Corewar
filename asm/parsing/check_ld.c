/*
** check_ld.c for corewar in /home/blackbird/work/Corewar/asm/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun Apr  6 12:21:40 2014 romaric
** Last update Sun Apr  6 13:55:59 2014 romaric
*/

#include "struct.h"

char    *copi_labelde(char *args)
{
  char  *str;
  int   i;
  int   j;
  int	size;

  i = 2;
  j = 0;
  size = 0;
  while (args[i] != ',')
    size++;
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

void	check_ld(char *args, char *cmd, t_label *list)

{
  int	i;

  i = 0;
  if (args[0] != '%')
    {
      my_printf(2, "%s needs a direct or indirect value.\n", cmd);
      my_putstr("you don't have put one.\n", 2);
      my_putstr("u can put one like this '%value' or '%:label'", 2);
      exit(EXIT_FAILURE);
    }
  else if (args[1] == ':' && check_label_exist(list, copi_labelde(args)) != 1)
    {
      my_putstr("this label does not exist !", 2);
      exit(EXIT_FAILURE);
    }
  else if (args[1] != ':')
    {
      if (args[1] < '0' || args[1] > '9' || args[1] == '-')
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
  while (args[i] != ',')
    i++;
  i = i + 1;
  if (args[i] != 'r')
    {
      my_printf(2, "%s needs a reg.\n", cmd);
      my_putstr("you don't have put one.\n", 2);
      my_putstr("a reg value is writed like this : rnbr (ex: r5).\n", 2);
      exit(EXIT_FAILURE);
    }
  i++;
  if (args[i] < '0' || args[i] > '9')
    {
      my_printf(2, "Wrong Value of reg: %s\n", args);
      exit(EXIT_FAILURE);
    }
  else if (args[i + 1] != '\0')
    if (args[i + 1] < '0' || args[i + 1] > '5')
    {
      my_printf(2, "Wrong Value of reg: %s\n", args);
      exit(EXIT_FAILURE);
    }
}
