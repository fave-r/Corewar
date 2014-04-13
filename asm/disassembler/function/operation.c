/*
** operation.c for operation in /home/thibaut.lopez/Corewar/Corewar/vm
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Wed Mar 12 18:52:51 2014 Thibaut Lopez
** Last update Sun Apr 13 22:50:27 2014 romaric
*/

#include "dasm.h"
#include "my.h"

int	my_add(unsigned char *buff, int fd, int i, int size)
{
  int	**tab;

  if ((tab = get_encode(buff, i, size)) == NULL)
    return (-1);
  if (tab[0][0] == 1 && tab[1][0] == 1 && tab[2][0] == 1 &&
      tab[3][0] == 0)
    my_printf(fd, "\tadd r%d, r%d, r%d\n", tab[0][2], tab[1][2], tab[2][2]);
  else
    {
      ifree(tab, 4);
      return (-1);
    }
  ifree(tab, 4);
  return (5);
}

int	my_sub(unsigned char *buff, int fd, int i, int size)
{
  int	**tab;

  if ((tab = get_encode(buff, i, size)) == NULL)
    return (-1);
  if (tab[0][0] == 1 && tab[1][0] == 1 && tab[2][0] == 1 &&
      tab[3][0] == 0)
    my_printf(fd, "\tsub r%d, r%d, r%d\n", tab[0][2], tab[1][2], tab[2][2]);
  else
    {
      ifree(tab, 4);
      return (-1);
    }
  ifree(tab, 4);
  return (5);
}

int	my_and(unsigned char *buff, int fd, int i, int size)
{
  int	ret;
  int	**tab;

  if ((tab = get_encode(buff, i, size)) == NULL)
    return (-1);
  if (tab[0][0] != 0 && tab[1][0] != 0 && tab[2][0] == 1 && tab[3][0] == 0)
    {
      my_putstr("\tand ", fd);
      my_printf(fd, (tab[0][0] == 1) ? "r%d," :
		(tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
      my_printf(fd, (tab[1][0] == 1) ? "r%d," :
		(tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
      my_printf(fd, "r%d\n", tab[2][2]);
    }
  else
    ret = -1;
  ret = tab[0][1] + tab[1][1] + 3;
  ifree(tab, 4);
  return (ret);
}

int	my_or(unsigned char *buff, int fd, int i, int size)
{
  int	ret;
  int	**tab;

  if ((tab = get_encode(buff, i, size)) == NULL)
    return (-1);
  if (tab[0][0] != 0 && tab[1][0] != 0 && tab[2][0] == 1 && tab[3][0] == 0)
    {
      my_putstr("\tor ", fd);
      my_printf(fd, (tab[0][0] == 1) ? "r%d," :
		(tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
      my_printf(fd, (tab[1][0] == 1) ? "r%d," :
		(tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
      my_printf(fd, "r%d\n", tab[2][2]);
    }
  else
    ret = -1;
  ret = tab[0][1] + tab[1][1] + 3;
  ifree(tab, 4);
  return (ret);
}

int	my_xor(unsigned char *buff, int fd, int i, int size)
{
  int	ret;
  int	**tab;

  if ((tab = get_encode(buff, i, size)) == NULL)
    return (-1);
  if (tab[0][0] != 0 && tab[1][0] != 0 && tab[2][0] == 1 && tab[3][0] == 0)
    {
      my_putstr("\txor ", fd);
      my_printf(fd, (tab[0][0] == 1) ? "r%d," :
		(tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
      my_printf(fd, (tab[1][0] == 1) ? "r%d," :
		(tab[1][0] == 2) ? "%%%d," : "%d,", tab[1][2]);
      my_printf(fd, "r%d\n", tab[2][2]);
    }
  else
    ret = -1;
  ret = tab[0][1] + tab[1][1] + 3;
  ifree(tab, 4);
  return (ret);
}
