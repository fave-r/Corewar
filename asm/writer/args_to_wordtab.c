/*
** args_to_wordtab.c for args_to_wordtab in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Wed Apr  9 15:19:03 2014 alex-odet
** Last update Thu Apr 10 18:08:19 2014 romaric
*/

#include "struct.h"

int	count_args(char *args)
{
  int	i;
  int	nb_args;

  nb_args = 0;
  i = 0;
  while (args[i])
    {
      while ((args[i] != ',') && args[i] != 0)
	i++;
      if (args[i] != 0 && args[i] != ',')
	nb_args++;
      while (args[i] != ',' && args[i] != 0)
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
  args_tab = xmalloc(sizeof(char *) * (nb_args + 1) + (my_strlen(args) + 1));
  if (args_tab == NULL)
    exit(EXIT_FAILURE);
  ptr = (char *)args_tab;
  ptr += sizeof(char *) * (nb_args + 1);
  ptr = my_strcpy(ptr, args);
  i = 0;
  while (*ptr != 0)
    {
      while (*ptr != 0 && (*ptr == '\t') && (*ptr == ','))
	*ptr++ = 0;
      if (*ptr != 0 && *ptr != '\t' && *ptr != ',')
	args_tab[i++] = ptr;
      while (*ptr != 0 && *ptr != '\t' && *ptr != ',')
	ptr += 1;
    }
  args_tab[i] = 0;
  return (args_tab);
}
