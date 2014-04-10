/*
** my_str_to_wordtab.c for corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Mar 25 15:50:05 2014 romaric
** Last update Thu Apr 10 17:58:30 2014 romaric
*/

#include "struct.h"

int	len_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

int	count_words(char *line)
{
  int	i;
  int	nb_words;

  nb_words = 0;
  i = 0;
  while (line[i])
    {
      while ((line[i] == '\t') && line[i] != '\0')
	i = i + 1;
      if (line[i] !=  '\t' && line[i] != '\0')
	nb_words = nb_words + 1;
      while (line[i] !=  '\t' && line[i] != '\0')
	i = i + 1;
    }
  return (nb_words);
}

char	**my_str_to_wordtab(char *line)
{
  char	**tab;
  char	*ptr;
  int	nb_words;
  int	i;

  nb_words = count_words(line);
  tab = xmalloc(sizeof(char *) * (nb_words + 1) + my_strlen(line) + 1);
  if (tab == NULL)
    exit(EXIT_FAILURE);
  ptr = (char *)tab;
  ptr += sizeof(char *) * (nb_words + 1);
  ptr = my_strcpy(ptr, line);
  i = 0;
  while (*ptr != '\0')
    {
      while (*ptr != '\0' && (*ptr == '\t'))
	*ptr++ = '\0';
      if (*ptr != '\0' && *ptr != '\t')
	tab[i++] = ptr;
      while (*ptr != '\0' && *ptr != '\t')
	ptr += 1;
    }
  tab[i] = '\0';
  return (tab);
}
