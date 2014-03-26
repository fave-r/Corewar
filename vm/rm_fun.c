/*
** rm_fun.c for rm_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Mon Mar 24 13:57:49 2014 Thibaut Lopez
** Last update Wed Mar 26 14:08:19 2014 thibaud
*/

#include "my.h"
#include "vm.h"

void	rm_empty_champ(t_champ **tmp, t_champ **first, t_cor *cor)
{
  t_champ	*prev;
  t_champ	*to_free;

  if (*first == *tmp)
    *first = (*first)->next;
  prev = (*tmp)->prev;
  to_free = *tmp;
  *tmp = (*tmp)->next;
  prev->next = *tmp;
  (*tmp)->prev = prev;
  free(to_free);
  cor->nb_chmps_alive--;
}

void	epur_champ(t_cor *cor, t_champ **first)
{
  int		i;
  t_champ	*tmp;

  i = 0;
  tmp = cor->champ;
  while (i < 4)
    {
      if (tmp->path == NULL && tmp != tmp->next)
	rm_empty_champ(&tmp, first, cor);
      else if (tmp->path == NULL)
	{
	  free(tmp);
	  my_putstr(ER_VOID, 2);
	  exit(1);
	}
      else
	tmp = tmp->next;
      i++;
    }
}

t_champ	*del_chmp(t_champ *champs, int champ_del)
{
  t_champ	*tmp;
  //t_champ	*tmp2;

  if (champs == NULL)
    return (NULL);
  if (champs->champ_nb == champ_del)
    {
      tmp = champs->next;
      if (champs->prev != NULL)
	champs->prev->next = champs->next;
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
  int	champ_nb;
  int	nb_alive;

  nb_alive = 0;
  champ_nb = 1;
  while (champ_nb <= 4)
    {
      if (map->live[champ_nb - 1] == 0)
	{
	  del_chmp(champs, map->champs_nb[champ_nb - 1]);
	}
      else
	nb_alive++;
      champ_nb++;
    }
  if (nb_alive == 1)
    {
      printf("Il n'en reste qu'un\n");
      end_game(champs, map);
    }
  return (0);
}
