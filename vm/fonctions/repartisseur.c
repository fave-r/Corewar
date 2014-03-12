/*
** repartisseur.c for vm in /home/thibaud/rendu/Corewar/Corewar/vm/fonctions
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Wed Mar  5 18:19:35 2014 thibaud
** Last update Wed Mar 12 16:21:34 2014 thibaud
*/

#include"vm.h"

t_struct	fct_tab[] =
  {
    {1, &live, 10},
    {2, &ld, 5},
    {3, &st, 8},
    {4, &add, 10},
    {5, &sub, 10},
    {6, &and, 6},
    {7, &or, 6},
    {8, &xor, 6},
    {9, &zjmp, 20},
    {10, &ldi, 25},
    {11, &sti, 25},
    {12, &fork, 800},
    {13, &lld, 10},
    {14, &lldi, 50},
    {15, &lfork, 1000},
    {16, &aff, 2},
    {0, &none, 0},
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
int	champ_play(t_champ *champ, t_cor *map)
{
  int	fct_nb;

  if ((fct_nb = find_in_tab(champ->pc)) != 0)
    {
      fct_tab[fct_nb].ptr_fct(champ, map);

    }
  else
    none(champ, map);
  return (0);
}

int	get_ctw(t_champ *champ, t_cor *map)
{
  int	fct_nb;

  if ((fct_nb = find_in_tab(champ->pc)) != 0)
    champ->wait = fct_tab[fct_nb].ctw;
  else
    champ->wait = 0;
  return (0);
}

int	cycle_run(t_champ *champs, t_cor *map)
{
  t_champ	*tmp_champ;

  tmp_champ = champs->next;
  while (tmp_champ != champs)
    {
      if (champ->wait < 0)
	champ->wait = get_ctw(champs, map);
      if (cycle_to_wait == 0)
	champ_play(tmp_champ, map);
      tmp_champ->wait -= 1;
      tmp_champ = tmp_champ->next;
    }
  map->cycle_done++;
  return (0);
}

t_champ	*del_chmp(t_champ *champs, int champ_del)
{
  t_champ	*tmp;

  if (champs == NULL)
    return (NULL);
  if (champ->champ_nb == champ_del)
    {
      tmp = champs->next;
      free(champs);
      tmp = del_chmp(tmp, champ_del);
      return (tmp);
    }
  else
    {
      champs->next = del_chmp(champs->next);
      return (champs);
    }
  return (NULL);
}

int	kill_champ(t_champ *champs, t_cor *map)
{
  t_champ	*cur_champ;
  int	champ_nb;

  champ_nb = 1;
  while (champ_nb <= 4)
    {
      cur_champ = champs->next;
      if (map->live[champ_nb - 1] == 0)
	  del_chmp(t_champs, champ_nb);
    }
  return (0);
}

int	repartisseur(t_champ *champs, t_cor *map)
{

  map->cycle_to_die = CYCLE_TO_DIE + CYCLE_DELTA;
  while ((map->cycle_to_die -= CYCLE_DELTA) > 100)
    {
      while (NBR_LIVE > map->nbr_live && map->cycle_done < cycle_to_die )
	cycle_run(champs, map);
      kill_champ(champs, map);
      map->nbr_live = 0;
      map->cycle_done = 0;
    }
  end_game(champs);
  return (0);
}
