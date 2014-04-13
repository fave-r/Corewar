/*
** champ_fun.c for champ_fun in /home/thibaut.lopez/Corewar/Corewar/vm
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Wed Feb 26 13:43:48 2014 Thibaut Lopez
** Last update Sun Apr 13 19:13:48 2014 romaric
*/

#include "vm.h"
#include "my.h"

void		set_var(t_champ *champ)
{
  champ->head = NULL;
  champ->path = NULL;
  champ->fd = -1;
  champ->pc = -1;
  champ->wait = -1;
  my_mem_set(champ->reg, REG_NUMBER);
  champ->carry = 1;
}

t_champ		*init_champ()
{
  int		i;
  t_champ	*champ;
  t_champ	*tmp;
  t_champ	*prev;

  i = 1;
  tmp = NULL;
  prev = NULL;
  champ = xmalloc(sizeof(t_champ));
  while (i < 5)
    {
      set_var(champ);
      champ->champ_nb = i;
      i++;
      champ->next = (i < 5) ? xmalloc(sizeof(t_champ)) : tmp;
      champ->prev = prev;
      prev = champ;
      tmp = (tmp == NULL) ? champ : tmp;
      champ = champ->next;
    }
  tmp->prev = prev;
  return (tmp);
}

void		find_next_available(t_champ **champ)
{
  t_champ	*tmp;

  tmp = *champ;
  *champ = (*champ)->next;
  while ((*champ)->path != NULL && *champ != tmp)
    *champ = (*champ)->next;
  if (*champ == tmp)
    my_putstr(ER_FULL, 2);
}

int		move_in_list(t_champ **champ, int nbr)
{
  t_champ	*tmp;

  tmp = *champ;
  if (tmp->champ_nb != nbr)
    tmp = tmp->next;
  while (tmp != *champ && tmp->champ_nb != nbr)
    tmp = tmp->next;
  if (tmp == *champ && tmp->champ_nb != nbr && tmp->path == NULL)
    tmp->champ_nb = nbr;
  *champ = tmp;
  if ((*champ)->champ_nb == nbr && (*champ)->path != NULL)
    if ((*champ)->path != NULL)
      {
	my_putstr(ER_POS1, 2);
	my_putnbr(nbr, 2);
	my_putstr(ER_POS2, 2);
	my_putstr((*champ)->path, 2);
	my_putstr(ER_POS3, 2);
	return (1);
      }
  return (0);
}

int		check_champ(t_champ **champ, char *path, int addr, int endian)
{
  unsigned int	r_len;

  (*champ)->fd = xopen(path, O_RDONLY);
  (*champ)->head = xmalloc(sizeof(header_t));
  (*champ)->head->magic = 0;
  (*champ)->head->prog_size = 0;
  r_len = read((*champ)->fd, (*champ)->head, sizeof(header_t));
  convert_endian(&((*champ)->head->magic), endian);
  convert_endian(&((*champ)->head->prog_size), endian);
  if (r_len < sizeof(header_t) || (*champ)->head->magic != COREWAR_EXEC_MAGIC
      || (*champ)->head->prog_size > MEM_SIZE)
    {
      my_putstr(path, 2);
      my_putstr((r_len < sizeof(header_t) || (*champ)->head->magic
		 != COREWAR_EXEC_MAGIC) ? ER_COR : ER_SIZE, 2);
      free((*champ)->head);
      (*champ)->head = NULL;
      close((*champ)->fd);
      return (1);
    }
  (*champ)->path = my_strdup(path);
  (*champ)->pc = addr;
  find_next_available(champ);
  return (-1);
}
