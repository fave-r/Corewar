/*
** recup.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Feb 25 18:56:54 2014 romaric
** Last update Tue Mar  4 16:29:08 2014 romaric
*/

#include "struct.h"
#include "op.h"

void	recup_name(char *str)
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
  printf("save = %s\n", save);
  //return (save);
}
