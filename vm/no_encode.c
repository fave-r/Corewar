/*
** no_encode.c for no_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 12:05:37 2014 Thibaut Lopez
** Last update Tue Mar 11 15:48:33 2014 Thibaut Lopez
*/

#include "vm.h"

void	my_live(t_champ *champ, char *mem)
{
  int	i;
  int	nb;

  nb = 0;
  i = 1;
  while (i < 5)
    {
      nb = nb * 256 + mem[champ->adress + champ->pc + i];
      i++;
    }
}

void	my_zjmp()
{
  short int	jump;

  read(fd, &jump, sizeof(short int));
}

void	my_fork()
{
  short int	addr;

  read(fd, &jump, sizeof(short int));
}

void	my_lfork()
{
  short int	addr;

  read(fd, &jump, sizeof(short int));
}
