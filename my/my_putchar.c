/*
** my_putchar.c for my_putchar in /home/thibaut.lopez/Corewar/Corewar/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 20:57:45 2014 Thibaut Lopez
** Last update Thu Mar 13 10:38:35 2014 Thibaut Lopez
*/

#include "my.h"

void	my_putchar(char c, int fd)
{
  write(fd, &c, 1);
}
