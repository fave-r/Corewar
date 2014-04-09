/*
** repartisseur.c for vm in /home/thibaud/rendu/Corewar/Corewar/vm/fonctions
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Wed Mar  5 18:19:35 2014 thibaud
** Last update Wed Apr  9 10:08:18 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

t_struct	fct_tab[] =
  {
    {0, &my_none, 0},
    {1, &my_live, 10},
    {2, &my_ld, 5},
    {3, &my_st, 8},
    {4, &my_add, 10},
    {5, &my_sub, 10},
    {6, &my_and, 6},
    {7, &my_or, 6},
    {8, &my_xor, 6},
    {9, &my_zjmp, 20},
    {10, &my_ldi, 25},
    {11, &my_sti, 25},
    {12, &my_fork, 800},
    {13, &my_lld, 10},
    {14, &my_lldi, 50},
    {15, &my_lfork, 1000},
    {16, &my_aff, 2},
  };

int	find_in_tab(char octet)
{
  int	i;

  i = 0;
  while (i <= 16)
    {
      if (octet == fct_tab[i].mnemonique)
	return (i);
      i++;
    }
  return (0);
}

int	champ_play(t_champ *cur_champ, t_cor *map)
{
  fct_tab[find_in_tab(map->mem[cur_champ->pc])].ptr_fct(cur_champ, map);
  return (0);
}


int	get_wait(t_champ *cur_champ, t_cor *map)
{
  cur_champ->wait = fct_tab[find_in_tab(map->mem[cur_champ->pc])].wait;
  return (cur_champ->wait);
}

int	list_size(t_champ *champ)
{
  int	nb;
  t_champ	*tmp;

  tmp = champ;
  nb = 0;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      nb++;
    }
  return (nb);
}


int	run_corewar(t_champ *champs, t_cor *map)
{
  int	cycle_done;

  cycle_done = 0;
  map->cycle_to_die = CYCLE_TO_DIE;
  while ((map->cycle_to_die) > 100)
    {
      my_mem_set(map->live, 4);
      while (map->cycle <=  map->cycle_to_die)
	{
	  if ((map->cycle + cycle_done) == map->dump)
	    {
	      aff_mem(map->mem);
	      exit(0);
	    }
	  cycle_run(champs, map);
	  if (map->live_done >= NBR_LIVE)
	    {
	      if (!someone_is_dead(champs, map))
		{
		  // printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
		  //printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
		  //printf("Cycle_done = %d\n", cycle_done + map->cycle);
		  //printf("Personne n'est MORT bordel !!\n");
		  map->cycle_to_die -= CYCLE_DELTA;
		  //printf("Cycle_to_die = %d\n", map->cycle_to_die);
		  map->live_done = 0;
		}
	    }
	}
      //printf("Num live = %d %d %d %d\n", map->live[0], map->live[1], map->live[2], map->live[3]);
      //printf("Live_done = %d\n\n\n\n", map->live_done);
      kill_champ(champs, map);
      cycle_done += map->cycle;
      map->cycle = 0;
    }
  end_game(champs, map);
  return (0);
}
