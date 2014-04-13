/*
** cycle_run.c for cycle_run in /home/thibaut.lopez/Corewar/Corewar/vm
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Mon Mar 24 14:11:08 2014 Thibaut Lopez
** Last update Sun Apr 13 19:18:10 2014 romaric
*/

#include "vm.h"
#include "my.h"

int		cycle_run(t_champ *champs, t_cor *map, int cycle_done)
{
  t_champ	*cur_champ;

  cur_champ = champs;
  while (cur_champ != NULL)
    {
      if (cur_champ->wait < 0)
	get_wait(cur_champ, map);
      if (cur_champ->wait == 0)
	{
	  champ_play(cur_champ, map);
	  get_wait(cur_champ, map);
	}
      cur_champ->wait -= 1;
      cur_champ = cur_champ->next;
    }
  map->cycle++;
  refresh_cycle(map, map->cycle + cycle_done);
  return (0);
}

int		someone_is_dead(t_champ *champs, t_cor *map)
{
  int		cpt;
  int		i;

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

int		free_champ(t_champ *champ)
{
  t_champ	*tmp;

  while (champ != NULL)
    {
      tmp = champ;
      champ = champ->next;
      free(tmp->head);
      free(tmp->path);
      if (tmp->graphic_name != NULL)
	free(tmp->graphic_name);
      free(tmp);
    }
  return (0);
}

int		end_game(t_champ *champ, t_cor *map)
{
  int		gg;
  int		cpt;

  (void)champ;
  gg = -1;
  cpt = 0;
  if (champ != NULL)
    {
      while (cpt < 4)
	{
	  if (map->live[cpt] == 2)
	    gg = cpt;
	  cpt++;
	}
      while (champ->champ_nb != map->champs_nb[gg])
	champ = champ->next;
      my_printf(1, "Le joueur %d(%s) a gagne\n",
		map->champs_nb[gg], champ->head->prog_name);
    }
  else
    my_printf(1, "Egalite\n");
  free_champ(champ);
  free(map->mem);
  exit(0);
}
