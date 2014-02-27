/*
** recup.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Feb 25 18:56:54 2014 romaric
** Last update Wed Feb 26 15:43:20 2014 
*/

#include "struct.h"
#include "op.h"

char	*recup_name(char *str)
{
  int	i;
  int	j;
  char	save[PROG_NAME_LENGTH];

  i = 6;
  j = 0;
  while (str[++i] != '"' && count_quotes(str, i) >= 1)
    {
      save[j] = str[i];
      j++;
    }
  save[j] = 0;
  printf("save = %s\n", save);
  return (save);
}
