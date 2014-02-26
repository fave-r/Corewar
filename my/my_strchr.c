/*
** my_strchr.c for my_strchr in /home/thibaut.lopez/Corewar/my
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Sun Feb 23 20:59:59 2014 Thibaut Lopez
** Last update Sun Feb 23 21:01:21 2014 Thibaut Lopez
*/

int	my_strchr(char src, char *dest)
{
  int	i;

  i = 0;
  while (dest[i] != 0 && dest[i] != src)
    i++;
  if (dest[i] == 0)
    return (-1);
  return (i);
}
