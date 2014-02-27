/*
** basic.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Feb 26 18:12:20 2014 romaric
** Last update Wed Feb 26 20:18:44 2014 Thibaut Lopez
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_putstr(char *str, int fd)
{
  return (write(fd, str, my_strlen(str)));
}
