/*
** my_memset.c for corewar in /home/blackbird/work/Corewar/my
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Mar 24 17:20:50 2014 romaric
** Last update Mon Mar 24 17:21:27 2014 romaric
*/

#include "my.h"

void	my_memset(char *str, size_t n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      str[i] = 0;
      i++;
    }
}
