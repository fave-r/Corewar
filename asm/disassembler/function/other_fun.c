/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
** Last update Sun Apr 13 22:50:44 2014 romaric
*/

#include "dasm.h"
#include "my.h"

int	my_st(unsigned char *buff, int fd, int i, int size)
{
  int	ret;
  int	**tab;

  if ((tab = get_encode(buff, i, size)) == NULL)
    return (-1);
  if (tab[0][0] == 1 && (tab[1][0] == 1 || tab[1][0] == 3) &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      my_putstr("\tst ", fd);
      my_printf(fd, "r%d,", tab[0][2]);
      my_printf(fd, (tab[1][0] == 1) ? "r%d\n" : "%d\n", tab[1][2]);
    }
  else
    ret = -1;
  ret = tab[0][1] + tab[1][1] + 2;
  ifree(tab, 4);
  return (ret);
}

int	my_sti(unsigned char *buff, int fd, int i, int size)
{
  int	ret;
  int	**tab;

  if ((tab = get_encode(buff, i, size)) == NULL)
    return (-1);
  if (tab[0][0] == 1 && tab[1][0] != 0 && (tab[2][0] == 1 || tab[2][0] == 2) &&
      tab[3][0] == 0)
    {
      my_printf(fd, "\tsti r%d,", tab[0][2]);
      my_printf(fd, (tab[1][0] == 1) ? "r%d," :
		(tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
      my_printf(fd, (tab[2][0] == 1) ? "r%d\n" : "%%%d\n", tab[2][2]);
    }
  else
    ret = -1;
  ret = tab[0][1] + tab[1][1] + tab[2][1] + 2;
  ifree(tab, 4);
  return (ret);
}

int	my_aff(unsigned char *buff, int fd, int i, int size)
{
  int	**tab;

  if ((tab = get_encode(buff, i, size)) == NULL)
    return (-1);
  if (tab[0][0] == 1 && tab[1][0] == 0 && tab[2][0] == 0 && tab[3][0] == 0)
    my_printf(fd, "\taff r%d\n", tab[0][2]);
  else
    {
      ifree(tab, 4);
      return (-1);
    }
  ifree(tab, 4);
  return (6);
}
