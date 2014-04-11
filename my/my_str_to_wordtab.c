/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/thibaut.lopez/Piscine-C-Jour_08/ex_04
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Oct  9 18:47:09 2013 Thibaut Lopez
** Last update Fri Apr 11 15:06:13 2014 Thibaut Lopez
*/

#include "minishell.h"
#include "my_str_to.h"

char	*my_strncpy(char *dest, char *src, int n);

int	strlen_1word(const char *str, char *sep)
{
  int	i;

  i = 0;
  if (str[0] == 0)
    return (0);
  else if (my_strchr(str[0], sep) != -1)
    return (0);
  while (my_strchr(str[i], sep) == -1 && str[i] != 0)
    i++;
  return (i);
}

int	lentab(char *str, char *sep)
{
  int	i;
  int	nbr_word;
  int	bool;

  i = 0;
  nbr_word = 0;
  bool = 0;
  while (my_strchr(str[i], sep) != -1)
    i++;
  while (str[i] != 0)
    {
      if (my_strchr(str[i], sep) != -1)
	  nbr_word = (++bool == 1) ? nbr_word + 1 : nbr_word;
      else
	bool = 0;
      i++;
    }
  if (bool == 0)
    nbr_word++;
  return (nbr_word);
}

char	**my_str_to_wordtab(char *str, char *sep)
{
  int	tmp;
  int	j;
  char	**tb;
  char	*first;

  j = 0;
  tmp = lentab(str, sep);
  tb = xmalloc((tmp + 1) * sizeof(char *));
  first = str;
  while (j != tmp && *str != 0)
    {
      if (strlen_1word(str, sep) > 0)
	{
	  tb[j] = xmalloc((strlen_1word(str, sep) + 1) * sizeof(char));
	  tb[j] = my_strncpy(tb[j], str, strlen_1word(str, sep));
	  str = str + strlen_1word(str, sep) + 1;
	  j++;
	}
      else
	str = str + 1;
    }
  tb[j] = NULL;
  str = first;
  return (tb);
}
