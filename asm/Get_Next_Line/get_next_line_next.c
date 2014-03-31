/*
** get_next_line_next.c for corewar in /home/blackbird/work/Corewar/asm/Get_Next_Line
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Mar 31 19:53:36 2014 romaric
** Last update Mon Mar 31 19:55:58 2014 romaric
*/

#include "struct.h"

void    operations(t_get *l, int *i, char buff[])
{
  l->s = my_get_strdup(l->s);
  l->s[l->c] = buff[*i];
  *i = *i + 1;
  l->c++;
}

void    operationss(char buff[], int *i, int *a)
{
  my_memset(buff, BUFF_SIZE);
  *i = 0;
  *a = 0;
}
