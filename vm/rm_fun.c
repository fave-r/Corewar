/*
** rm_fun.c for rm_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Mon Mar 24 13:57:49 2014 Thibaut Lopez
** Last update Wed Mar 26 18:36:25 2014 thibaud
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

t_champ		*del_chmp(t_champ *champs, int champ_del)
{
  t_champ	*cur;
  t_champ	*del;

  cur = champs->next;
  del = NULL;
  while (cur != NULL)
    {
      if (cur->champ_nb == champ_del)
	{
	  del = cur;
	  cur = cur->next;
	  if (del == champs->next)
	    {
	      champs = champs->next;
	    }
	  if (del->prev != NULL)
	    del->prev->next = cur;
	  if (del->next != NULL)
	    del->next->prev = del->prev;
	  free(del);
	}
      cur = cur->next;
    }
  return (NULL);
}

/*
t_champ	*del_chmp(t_champ *champs, int champ_del)
{
  t_champ	*tmp;

  if (champs == NULL)
    return (NULL);
  if (champs->champ_nb == champ_del)
    {
      tmp = champs->next;
      if (champs->prev != NULL)
	champs->prev->next = champs->next;
      else
	tmp->prev = NULL;
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
*/
int	kill_champ(t_champ *champs, t_cor *map)
{
  int	i;
  int	nb_alive;

  nb_alive = 0;
  i = 0;
  while (i < 4)
    {
      if (map->live[i] == 0)
	{
	  del_chmp(champs, map->champs_nb[i]);
	}
      else
	nb_alive++;
      i++;
    }
  if (nb_alive == 1)
    {
      printf("Il n'en reste qu'un\n");
      end_game(champs, map);
    }
  return (0);
}
