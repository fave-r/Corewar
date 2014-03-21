/*
** my_strncmp.c for my_strncmp in /home/alex-odet/work/Corewar/my
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Mar 11 08:06:40 2014 alex-odet
** Last update Thu Mar 13 10:20:47 2014 Thibaut Lopez
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
      if (s1[i] < s2[i] && i < n)
        return (-1);
      if (s1[i] > s2[i] && i < n)
        return (1);
      i++;
    }
  return (0);
}
