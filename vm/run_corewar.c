/*
** repartisseur.c for vm in /home/thibaud/rendu/Corewar/Corewar/vm/fonctions
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Wed Mar  5 18:19:35 2014 thibaud
** Last update Wed Mar 12 19:39:56 2014 thibaud
*/

#include "vm.h"
#include "my.h"

t_struct	fct_tab[] =
  {
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
    {0, &my_none, 0},
  };

int	find_in_tab(char octet)
{
  int	i;
  i = 0;

  while (fct_tab[i].mnemonique != 0)
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
  return (0);}
    

int	get_wait(t_champ *cur_champ, t_cor *map)
{
  cur_champ->wait = fct_tab[find_in_tab(map->mem[cur_champ->pc])].wait;
  return (cur_champ->wait);
}

int	cycle_run(t_champ *champs, t_cor *map)
{
  t_champ	*cur_champ;

  cur_champ = champs;
  while (cur_champ != NULL)
    {
      if (cur_champ->wait < 0)
	get_wait(cur_champ, map);
      if (cur_champ->wait == 0)
	champ_play(cur_champ, map);
      cur_champ->wait -= 1;
      cur_champ = cur_champ->next;
    }
  map->cycle_done++;
  return (0);
}

t_champ	*del_chmp(t_champ *champs, int champ_del)
{
  t_champ	*tmp;

  if (champs == NULL)
    return (NULL);
  if (champs->champ_nb == champ_del)
    {
      tmp = champs->next;
      free(champs);
      tmp = del_chmp(tmp, champ_del);
      return (tmp);
    }
  else
    {
      champs->next = del_chmp(champs->next, champ_del);
      return (champs);
    }
  return (NULL);
}

int	kill_champ(t_champ *champs, t_cor *map)
{
  //  t_champ	*cur_champ;
  int	champ_nb;

  champ_nb = 1;
  while (champ_nb <= 4)
    {
      //      cur_champ = champs;
      if (map->live[champ_nb - 1] == 0)
	{
	  del_chmp(champs, map->champs_nb[champ_nb - 1]);
	  map->nb_chmps_alive--;
	}
      champ_nb++;
      if (map->nb_chmps_alive == 1)
	end_game(champs, map);
    }
  return (0);
}

int	someone_is_dead(t_champ *champs, t_cor *map)
{
  int	cpt;
  int	i;

  (void)champs;
  i = 0;
  cpt = 0;
  while (i < 4)
    {
      if (map->live[i] != 0)
	cpt++;
      i++;
    }
  if (map->nb_chmps_alive != cpt)
    return (1);
  return (0);
}

int	end_game(t_champ *champ, t_cor *map)
{
  int	gg;

  (void)champ;
  gg = 0;
  while (map->live[gg] != 2)
    gg++;
  my_putstr("le joueur ", 0);
  my_putnbr(map->champs_nb[gg], 0);
  my_putstr(" a gagné yéyéyé !!", 0);
  // A refaire avec un my_printf et en moins con
  return (0);
}

int	run_corewar(t_champ *champs, t_cor *map)
{
  map->cycle_to_die = CYCLE_TO_DIE;
  while ((map->cycle_to_die) > 100)
    {
      while (map->cycle_done <= map->cycle_to_die)
	{
	  cycle_run(champs, map);
	  if (map->live_done >= NBR_LIVE)
	    {
	      if (!someone_is_dead(champs, map))
		{
		  map->cycle_to_die -= CYCLE_DELTA;
		}
	      map->live_done = 0;
	      map->cycle_done = 0;
	    }
	}      
      kill_champ(champs, map);
      map->live_done = 0;
      map->cycle_done = 0;
    }
  end_game(champs, map);
  return (0);
}