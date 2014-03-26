/*
** cycle_run.c for cycle_run in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Mon Mar 24 14:11:08 2014 Thibaut Lopez
** Last update Wed Mar 26 18:37:09 2014 thibaud
*/

#include "vm.h"
#include "my.h"

int	cycle_run(t_champ *champs, t_cor *map)
{
  t_champ	*cur_champ;

  cur_champ = champs;
  while (cur_champ != NULL)
    {
      if (cur_champ->wait < 0)
	get_wait(cur_champ, map);
      if (cur_champ->wait == 0)
	{
	  //printf("Num live = %d %d %d %d\n", map->live[0], map->live[1], map->live[2], map->live[3]);
	  champ_play(cur_champ, map);
	  get_wait(cur_champ, map);
	}
      cur_champ->wait -= 1;
      cur_champ = cur_champ->next;
    }
  //my_putstr("X", 1);
  map->cycle++;
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

int	free_champ(t_champ *champ)
{
  t_champ	*tmp;

  while (champ != NULL)
    {
      tmp = champ;
      champ = champ->next;
      free(tmp->head);
      free(tmp->path);
      free(tmp);
    }
  return (0);
}

int	end_game(t_champ *champ, t_cor *map)
{
  int	gg;

  (void)champ;
  gg = 0;
  //printf("\n%d%d%d%d\n\n", map->live[0], map->live[1], map->live[2], map->live[3]);
  while (map->live[gg] != 2)
    gg++;
  //free_champ(champ);
  free(map->mem);
  my_printf(1, "Le joueur %d(%s) a gagne\n", map->champs_nb[gg], champ->head->prog_name);
  exit(0);
}
