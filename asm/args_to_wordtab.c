/*
** args_to_wordtab.c for args_to_wordtab in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Wed Apr  9 15:19:03 2014 alex-odet
** Last update Wed Apr  9 15:37:57 2014 alex-odet
*/

#include "struct.h"

int	len_args(char **args_tab)
{
  int	i;

  i = 0;
  while (args_tab[i])
    i++;
  return (i);
}

int	count_args(char *args)
{
  int	i;
  int	nb_args;

  nb_args = 0;
  i = 0;
  while (args[i])
    {
      while ((line[i] != ',') && line[i] != 0)
	i++;
      if (line[i] != 0 && line[i] != ',')
	nb_args++;
      while (line[i] != ',' && line[i] != 0)
	i++;
    }
  return (nb_args);
}

char	**args_to_wordtab(char *args)
{
  char	**args_tab;
  char	*ptr;
  int	nb_args;
  int	i;

  nb_args = count_args(args);
  tab = xmalloc(sizeof(char *) * (nb_args + 1) + (my_strlen(args) + 1));
  if (tab == NULL)
    exit(1);
  ptr = (char *)tab;
  ptr += sizeof(char *) * (nb_args + 1);
  ptr = my_strcpy(ptr, line);
  i = 0;
  while (*ptr != 0)
    {
      while (*ptr != 0 && (*ptr == '\t') && (*ptr == ','))
	*ptr++ = 0;
      if (*ptr != 0 && *ptr != '\t' && *ptr != ',')
	tab[i++] = ptr;
      while (*ptr != 0 && *ptr != '\t' && *ptr != ',')
	ptr += 1;
    }
  tab[i] = 0;
  return (tab);
}
