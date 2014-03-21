/*
** my_strflen.c for my_strflen in /home/thibaut.lopez/Corewar/Corewar/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Fri Mar 14 09:50:59 2014 Thibaut Lopez
** Last update Fri Mar 14 09:52:44 2014 Thibaut Lopez
*/

#include "my.h"

int	my_strflen(const char *str)
{
  int	len;

  len = 0;
  while (str[len] != '\0')
    {
      len++;
    }
  return (len);
}
