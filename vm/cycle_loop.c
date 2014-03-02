/*
** cycle_loop.c for cycle_loop in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Feb 27 15:26:28 2014 Thibaut Lopez
** Last update Sun Mar  2 12:45:25 2014 Thibaut Lopez
*/

void	cycle_loop(t_cor *cor)
{
  while (cor->cycle_to_die > cor->dump)
    {
      cor->cycle = 0;
      while (cor->cycle < cor->cycle_to_die)
	{
	  cor->cycle++;
	}
      cor->cycle_to_die -= CYCLE_DELTA;
    }
}
