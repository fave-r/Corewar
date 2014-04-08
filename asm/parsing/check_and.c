/*
** check_and.c for corewar in /home/blackbird/work/Corewar/asm/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Apr  7 15:11:31 2014 romaric
** Last update Mon Apr  7 18:27:10 2014 romaric
*/

#include "struct.h"

void	init_labeldei(int *i, int *x, int *j, int *size)
{
  *x = *x + 2;
  *i = *x;
  *j = 0;
  *size = 0;
}

char    *copi_labeldei(char *args, int x)
{
  char  *str;
  int	i;
  int   j;
  int   size;

  init_labeldei(&i, &x, &j, &size);
  while (args[x + 2] != ',')
    {
      size++;
      x++;
    }
  str = xmalloc((size + 1) * sizeof(char));
  if (args[i - 1] == ':')
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

void    check_andnextnn(char *args, char *cmd, int i)
{
  i++;
  if (args[i] != 'r')
    {
      my_printf(2, "Bad last argument it must be a reg for : %s\n", cmd);
      exit(EXIT_FAILURE);
    }
  else
    {
      if (args[i + 1] < '1' || args[i + 1] > '9')
	errorvaluereg(args);
      else if (args[i + 2] != '\0')
	if (args[i + 2] < '0' || args[i + 2] > '6' || args[i + 1] != '1')
	  errorvaluereg(args);
    }
}

void	check_andnextn(char *args, char *cmd, t_label *list, int i)
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
  check_andnextnn(args, cmd, i);
}

void	check_andnext(char *args, char *cmd, t_label *list)
{
  int	i;

  i = 1;
  if (args[0] == 'r')
    {
      if (args[1] < '1' || args[1] > '9')
        errorvaluereg(args);
      else if (args[2] != ',')
        if (args[2] < '0' || args[2] > '6' || args[1] != '1')
          errorvaluereg(args);
    }
  while (args[i] != ',')
    i++;
  i++;
  if (args[i] != '%' && (args[i] < '0' || args[i] > '9')
      && args[i] != 'r' && args[i] != '-')
    {
      my_printf(2
                , "Bad argument u can put an indirect, a direct value, a reg\n");
      exit(EXIT_FAILURE);
    }
  check_andnextn(args, cmd, list, i);
}

void    check_and(char *args, char *cmd, t_label *list)
{
  if (args[0] != '%' && (args[0] < '0' || args[0] > '9')
      && args[0] != 'r' && args[0] != '-')
    {
      my_printf(2
		, "Bad argument u can put an indirect, a direct value, a reg\n");
      exit(EXIT_FAILURE);
    }
  else if (args[0] == '%' && args[1] == ':'
	   && check_label_exist(list, copi_labelde(args)) != 1)
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
    }
  check_andnext(args, cmd, list);
}
