/*
** no_encode.c for no_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 12:05:37 2014 Thibaut Lopez
** Last update Wed Apr  2 17:56:46 2014 thibaud
** Last update Fri Mar 21 09:23:42 2014 Thibaut Lopez
*/

#include "my.h"
#include "vm.h"

int	find_champ(t_cor *cor, int direct_arg)
{
  int	j;
  int	i;

  i = 0;
  j = -1;
  while (i < 4)
    {
      if (cor->champs_nb[i] == direct_arg)
	j = i;
      i++;
    }
  return (j);
}

int	my_live(t_champ *champ, t_cor *cor)
{
  int	i;
  int	j;
  int	direct_arg;

  direct_arg = get_nbr_action(cor->mem, champ->pc + 1, 4);
  j = find_champ(cor, direct_arg);
  if (j != -1)
    {
      i = 0;
      while (i++ < 4)
	if (cor->live[i - 1] == 2)
	  cor->live[i - 1] = 1;
      cor->live[j] = 2;
      my_printf(1, "le joueur %d(%s) est en vie\n", direct_arg, champ->head->prog_name);
      i = 0;
      while (i++ < 4)
	if (cor->live[i - 1] == 2)
	  cor->live[i - 1] = 1;
      cor->live[j] = 2;
      cor->live_done++;
    }
  else
    {
      my_printf(1, "le joueur %d(%s) A FOIRE SON LIVE\n", direct_arg, champ->head->prog_name);
    }
  change_pos_pc(champ, champ->pc + 5, 5, cor->screen);
  champ->pc += 5;
  return (5);
}


int	my_zjmp(t_champ *champ, t_cor *cor)
{
  int	direct_arg;

  if (champ->carry == 1)
    {
      direct_arg = get_nbr_action(cor->mem, champ->pc + 1, 2);
      //my_printf(1, "ZJMP du champion %s de %d cases.\n", champ->head->prog_name, direct_arg);
      change_pos_pc(champ, champ->pc + direct_arg, 3, cor->screen);
      champ->pc += direct_arg;
      printf("JUNMP du champion %s\n", champ->head->prog_name);
    }
  else
    {
      my_putstr("ECHEC DE JUMP car carry = 0", 1);
      change_pos_pc(champ, champ->pc + 3, 3, cor->screen);
      champ->pc += 3;
      exit(0);
    }
  return (3);
}

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
  return (son);
}

t_champ	*add_champ(t_champ *champ, int new_pos)
{
  t_champ	*son;

  son = champ_dup(champ, new_pos);
  son->prev = champ;
  son->next = champ->next;
  champ->next = son;
  if (son->next != NULL)
    son->next->prev = son;
  return (son);
}

int	my_fork(t_champ *champ, t_cor *cor)
{
  int		fork_dest;
  t_champ	*son;

  fork_dest = get_nbr_action(cor->mem, champ->pc + 1, 2);
  son = add_champ(champ, fork_dest % IDX_MOD);
  my_printf(1, "Le champion %s(%d) a fait un fils qui porte son nom : %s(%d)\n",champ->head->prog_name, champ->champ_nb, son->head->prog_name, son->champ_nb);
  change_pos_pc(champ, champ->pc + 3, 3, cor->screen);
  champ->pc += 3;
  return (3);
}

int	my_lfork(t_champ *champ, t_cor *cor)
{
  int		fork_dest;
  int		len;
  t_champ	*son;

  fork_dest = get_nbr_action(cor->mem, champ->pc + 1, 2);

  //champ->carry *= -1;
  son = add_champ(champ, fork_dest);
  len = read(son->fd, cor->mem + son->pc, MEM_SIZE - son->pc);
  if (len < son->head->prog_size)
    read(son->fd, cor->mem, son->head->prog_size);
  close(son->fd);
  change_pos_pc(champ, champ->pc + 3, 3, cor->screen);
  champ->pc += 3;
  return (3);
}

int	my_none(t_champ *champ, t_cor *cor)
{
  (void)cor;
  champ->pc++;
  return (0);
}
