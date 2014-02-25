/*
** recup.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Feb 25 18:56:54 2014 romaric
** Last update Tue Feb 25 19:42:59 2014 romaric
*/

#include "struct.h"

char	*recup_name(char *str)
{
  int	i;

  i = 6;
  while (str[++i] != '"' && count_quotes(str, i) >= 1)
    {
      write(1, &str[i], 1);
    }
  return ("BG");
}
