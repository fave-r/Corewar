/*
** fork_fun.c for fork_fun in /home/thibaut.lopez/Corewar/Corewar/vm/function
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Tue Apr  8 15:03:11 2014 Thibaut Lopez
** Last update Wed Apr  9 10:13:12 2014 Thibaut Lopez
*/

#include "my.h"
#include "vm.h"

t_champ	*champ_dup(t_champ *father, int new_pos)
{
  int	i;
  t_champ	*son;

  son = xmalloc(sizeof(t_champ));
  son->path = father->path;
  son->fd = father->fd;
  son->head = xmalloc(sizeof(header_t));
  son->head->magic = father->head->magic;
  i = 0;
  while (i++ < PROG_NAME_LENGTH + 1)
    son->head->prog_name[i -1] = father->head->prog_name[i -1];
  i = 0;
  while (i++ < COMMENT_LENGTH + 1)
    son->head->comment[i -1] = father->head->comment[i -1];
  son->head->prog_size = father->head->prog_size;
  son->champ_nb = father->champ_nb;
  son->pc = father->pc + new_pos;
  i = 0;
  while (i++ < REG_NUMBER)
      son->reg[i -1] = father->reg[i -1];
  son->carry = father->carry;
  son->wait = -1;
  son->color = father->color;
  son->a_col = father->a_col;
  return (son);
}

void	add_champ(t_champ *champ, int new_pos)
{
  t_champ	*son;

  son = champ_dup(champ, new_pos);
  son->prev = champ;
  son->next = champ->next;
  champ->next = son;
  if (son->next != NULL)
    son->next->prev = son;
}

void	my_fork(t_champ *champ, t_cor *cor)
{
  int		fork_dest;

  if (champ->champ_nb == 1)
    printf("FORK\n");
  fork_dest = get_nbr_action(cor->mem, champ->pc + 1, 2);
  add_champ(champ, fork_dest % IDX_MOD);
  change_pos_pc(champ, champ->pc + 3, cor->screen);
  change_pos_pc(champ->next, fork_dest, cor->screen);
  champ->pc += 3;
}

void	my_lfork(t_champ *champ, t_cor *cor)
{
  int		fork_dest;

  if (champ->champ_nb == 1)
    printf("LFORK\n");
  fork_dest = get_nbr_action(cor->mem, champ->pc + 1, 2);
  add_champ(champ, fork_dest);
  change_pos_pc(champ, champ->pc + 3, cor->screen);
  change_pos_pc(champ->next, fork_dest, cor->screen);
  champ->pc += 3;
}
