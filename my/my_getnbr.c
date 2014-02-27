/*
** my_getnbr.c for Corewar in /home/blackbird/work/Corewar/my
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Feb 26 16:46:37 2014 romaric
** Last update Thu Feb 27 15:12:47 2014 Thibaut Lopez
*/

#include "my.h"

int     my_getnbr(char *str)
{
  int   cpt;
  int   i;
  int   result;

  if (str == NULL)
    return (0);
  result = 0;
  i = 0;
  cpt = 1;
  while (str[i] >= 48 && str[i] <= 57)
    {
      cpt = cpt * 10;
      i++;
    }
  cpt = cpt / 10;
  i = 0;
  while (str[i] >= 48 && str[i] <= 57)
    {
      result = result + ((str[i] - 48) * cpt);
      cpt = cpt / 10;
      i++;
    }
  return (result);
}
