/*
** my_str_to_wordtab.c for corewar in /home/blackbird/work/Corewar/my
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Fri Apr 11 15:10:11 2014 romaric
** Last update Fri Apr 11 15:25:04 2014 romaric
*/

#include "my.h"

int	strlen_word(const char *str, char *sep)
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
      if (strlen_word(str, sep) > 0)
	{
	  tb[j] = xmalloc((strlen_word(str, sep) + 1) * sizeof(char));
	  tb[j] = my_strncpy(tb[j], str, strlen_word(str, sep));
	  str = str + strlen_word(str, sep) + 1;
	  j++;
	}
      else
	str = str + 1;
    }
  tb[j] = NULL;
  str = first;
  return (tb);
}
