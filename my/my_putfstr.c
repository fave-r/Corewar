/*
** my_putfstr.c for my_pufstr in /home/thibaut.lopez/Corewar/Corewar/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Fri Mar 14 09:53:32 2014 Thibaut Lopez
** Last update Fri Mar 14 09:53:41 2014 Thibaut Lopez
*/

#include "my.h"

int	my_putfstr(const char *str, int fd)
{
  while (*str != '\0')
    {
      my_putchar(*str, fd);
      str++;
    }
  return (0);
}
