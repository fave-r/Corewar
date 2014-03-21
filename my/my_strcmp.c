/*
** my_strcmp.c for my_strcmp in /home/thibaut.lopez/Piscine-C-Jour_06/ex_05
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Mon Oct  7 10:37:00 2013 Thibaut Lopez
** Last update Mon Dec  9 09:38:00 2013 Thibaut Lopez
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i])
    {
      i++;
      if ((s1[i] == '\0') && (s2[i] == '\0'))
	return (0);
    }
  if ((s2[i] - s1[i]) < 0)
    return (-1);
  else
    return (1);
}
