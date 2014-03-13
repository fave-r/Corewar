/*
** cycle_loop.c for cycle_loop in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Thu Feb 27 15:26:28 2014 Thibaut Lopez
** Last update Thu Mar 13 10:26:02 2014 Thibaut Lopez
*/



int	(*command[16])() =
{&my_live,
 &my_ld,
 &my_st,
 &my_add,
 &my_sub,
 &my_and,
 &my_or,
 &my_xor,
 &my_zjmp,
 &my_ldi,
 &my_sti,
 &my_fork,
 &my_lld,
 &my_lldi,
 &my_lfork,
 &my_aff};

void	champ_action(t_champ *champ, char *mem)
{
  int	action;

  action = mem[champ->adress + champ->pc];
  if (champ->wait == 0 && action < 17 && action > 0)
    {
      champ->wait = op_tab[action]->nbr_cycle;
    }
}

void	cycle_loop(t_cor *cor)
{
  t_champ	*tmp;

  while (cor->cycle_to_die > cor->dump)
    {
      cor->cycle = 0;
      while (cor->cycle < cor->cycle_to_die)
	{
	  tmp = cor->champ;

	  cor->cycle++;
	}
      cor->cycle_to_die -= CYCLE_DELTA;
    }
}
