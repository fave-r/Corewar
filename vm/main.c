/*
** main.c for vm in /home/thibaud/rendu/Corewar/vm
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Tue Feb 25 15:57:49 2014 thibaud
** Last update Thu Feb 27 15:55:29 2014 Thibaut Lopez
*/

#include "my.h"
#include "vm.h"

void	rm_empty_champ(t_champ **tmp, t_champ **first)
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
}

void	epur_champ(t_champ *champ, t_champ **first)
{
  int		i;
  t_champ	*tmp;

  i = 0;
  tmp = champ;
  while (i < 4)
    {
      if (tmp->path == NULL && tmp != tmp->next)
	rm_empty_champ(&tmp, first);
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

int     get_dump(char *nbr)
{
  int   i;
  int   ret;
  int	len;
  int	pow;
  char	*base;

  len = my_strlen(nbr);
  base = "0123456789ABCDEF";
  if (len == 0 || len > 2 || my_strchr(nbr[0], base) == -1 ||
      my_strchr(nbr[1], base) == -1)
    {
      my_putstr(ER_DUMP, 2);
      return (150);
    }
  pow = (len == 2) ? 16 : 1;
  i = 0;
  ret = 0;
  while (nbr[i] != 0)
    {
      ret += my_strchr(nbr[i], base) * pow;
      pow /= 16;
      i++;
    }
  return (ret);
}

void	fill_champ(char **argv, t_cor *cor)
{
  int		addr;
  t_champ	*tmp;

  cor->champ = init_champ();
  tmp = cor->champ;
  addr = 0;
  while (argv[cor->cycle] != NULL)
    {
      if (my_strcmp(argv[cor->cycle], "-dump") == 0)
	cor->dump = get_dump(argv[++cor->cycle]);
      else if (my_strcmp(argv[cor->cycle], "-n") == 0)
	move_in_list(&cor->champ, my_getnbr(argv[++cor->cycle]) % 5);
      else if (my_strcmp(argv[cor->cycle], "-a") == 0)
	addr = my_getnbr(argv[++cor->cycle]) % MEM_SIZE;
      else
	if ((addr = check_champ(&(cor->champ),
				argv[cor->cycle], addr, cor->endian)) == 1)
	  exit(1);
      if (argv[cor->cycle] != NULL)
	cor->cycle++;
    }
  epur_champ(cor->champ, &tmp);
  cor->champ = tmp;
}

int	main(int argc, char **argv)
{
  t_cor	cor;

  (void)argc;
  cor.dump = 150;
  cor.cycle = 1;
  cor.cycle_to_die = CYCLE_TO_DIE;
  cor.endian = my_endian();
  fill_champ(argv, &cor);
  cor.cycle = 0;
  return (0);
}