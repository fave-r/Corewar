/*
** my_strlen.c for my_strlen in /home/thibaut.lopez/Corewar/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Sun Feb 23 21:02:50 2014 Thibaut Lopez
** Last update Sat Mar 22 04:56:33 2014 alex-odet
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
