/*
** no_encode.c for no_encode in /home/thibaut.lopez/Corewar/Corewar/vm
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Wed Feb 26 12:05:37 2014 Thibaut Lopez
** Last update Sun Apr 13 22:50:06 2014 romaric
*/

#include "dasm.h"
#include "my.h"

int	my_live(unsigned char *buff, int fd, int i, int size)
{
  int	direct_arg;

  if (i > size - 4)
    return (-1);
  direct_arg = get_nbr_action(buff, i + 1, 4);
  my_printf(fd, "\tlive %%%d\n", direct_arg);
  return (5);
}

int	my_zjmp(unsigned char *buff, int fd, int i, int size)
{
  int	direct_arg;

  if (i > size - 2)
    return (-1);
  direct_arg = get_nbr_action(buff, i + 1, 2);
  my_printf(fd, "\tzjmp %%%d\n", direct_arg);
  return (3);
}

int	my_fork(unsigned char *buff, int fd, int i, int size)
{
  int	fork_dest;

  if (i > size - 2)
    return (-1);
  fork_dest = get_nbr_action(buff, i + 1, 2);
  my_printf(fd, "\tfork %%%d\n", fork_dest);
  return (3);
}

int	my_lfork(unsigned char *buff, int fd, int i, int size)
{
  int	fork_dest;

  if (i > size - 2)
    return (-1);
  fork_dest = get_nbr_action(buff, i + 1, 2);
  my_printf(fd, "\tlfork %%%d\n", fork_dest);
  return (3);
}
