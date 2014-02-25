/*
** basic.c for basic in /home/odet_a/Corewar/lib
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Mon Feb 17 04:26:11 2014 
** Last update Mon Feb 17 18:58:02 2014 
*/

#include "../../struct.h"

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
  return(write(fd, str, my_strlen(str)));
}
