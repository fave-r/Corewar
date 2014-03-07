/*
** my_putchar.c for my_putchar in /home/thibaut.lopez/Corewar/Corewar/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 20:57:45 2014 Thibaut Lopez
** Last update Wed Feb 26 20:58:27 2014 Thibaut Lopez
*/

#include "my.h"

void	my_putchar(char c, int fd)
{
  write(fd, &c, 1);
}
