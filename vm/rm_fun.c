/*
** rm_fun.c for rm_fun in /home/thibaut.lopez/Corewar/Corewar/vm
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Mon Mar 24 13:57:49 2014 Thibaut Lopez
** Last update Sun Apr 13 19:17:00 2014 romaric
*/

#include "my.h"
#include "vm.h"

void		rm_empty_champ(t_champ **tmp, t_champ **first, t_cor *cor)
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

void		epur_champ(t_cor *cor, t_champ **first)
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

t_champ		*del_chmp(t_champ *list, int nb)
{
  t_champ        *tmp;

  if (list == NULL)
    return (NULL);
  if (list->champ_nb == nb)
    {
      tmp = list->next;
      if (list->prev != NULL)
        {
          list->prev->next = tmp;
	  if (tmp != NULL)
	    tmp->prev = list->prev;
        }
      else if (tmp != NULL)
        tmp->prev = NULL;
      free(list->head);
      free(list->path);
      free(list);
      return (del_chmp(tmp, nb));
    }
  else
    {
      list->next = del_chmp(list->next, nb);
      return (list);
    }
}

int		kill_champ(t_champ **champs, t_cor *map)
{
  int		i;
  int		nb_alive;

  nb_alive = 0;
  i = 0;
  while (i < 4)
    {
      if (map->live[i] == 0)
	*champs = del_chmp(*champs, map->champs_nb[i]);
      else
	nb_alive++;
      i++;
    }
  if (nb_alive == 1)
      end_game(*champs, map);
  return (0);
}
