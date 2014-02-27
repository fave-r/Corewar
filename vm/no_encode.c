/*
** no_encode.c for no_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 12:05:37 2014 Thibaut Lopez
** Last update Wed Feb 26 12:20:27 2014 Thibaut Lopez
*/

void	my_live()
{
  int	nb_player;

  read(fd, &nb_player, sizeof(int));
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
