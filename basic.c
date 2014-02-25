/*
** basic.c for basic in /home/odet_a/rendu/CPE_2014_corewar/asm
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Mon Feb 24 15:01:04 2014 
** Last update Mon Feb 24 15:02:31 2014 
*/

#include "struct.h"

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
