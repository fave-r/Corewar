/*
** no_encode.c for no_encode in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Feb 26 12:05:37 2014 Thibaut Lopez
** Last update Sat Mar 22 18:04:51 2014 thibaud
** Last update Fri Mar 21 09:23:42 2014 Thibaut Lopez
*/

#include "my.h"
#include "vm.h"

int	my_live(t_champ *champ, t_cor *cor)
{
  int	i;
  int	j;
  int	direct_arg;

  my_printf(1, "Compteur de live = %d\n", cor->live_done);
  my_printf(1, "Compteur de cycle = %d\n", cor->cycle);
  i = 0;
  j = -1;
  direct_arg = get_nbr_action(cor->mem, champ->pc + 1, 4);
  while (i < 4)
    {
      if (cor->champs_nb[i] == direct_arg)
	j = i;
      i++;
    }
  if (j != -1)
    {
      i = 0;
      while (i++ < 4)
	if (cor->live[i - 1] == 2)
	  cor->live[i - 1] = 1;
      cor->live[j] = 2;
      my_printf(1, "Live du champion %s pour le champion numéro %d\n", champ->head->prog_name, direct_arg);
      i = 0;
      while (i++ < 4)
	if (cor->live[i - 1] == 2)
	  cor->live[i - 1] = 1;
      cor->live[j] = 2;
      cor->live_done++;
    }
  else
    my_putstr("Live ECHEC\n", 1);
  my_putstr(", avance dans la mémoire de 5\n", 1);
  champ->pc += 5;

  my_printf(1, "Num live = %d %d %d %d\n", cor->live[0], cor->live[1], cor->live[2], cor->live[3]);

  return (5);
}

int	my_zjmp(t_champ *champ, t_cor *cor)
{
  int	direct_arg;

  if (champ->carry == 1)
    {
      direct_arg = get_nbr_action(cor->mem, champ->pc + 1, 2);

      my_printf(1, "ZJMP du champion %s de %d cases.\n", champ->head->prog_name, direct_arg);
      champ->pc += direct_arg;
    }
  else
    my_putstr("ECHEC DE JUMP car carry = 0", 1);
  return (3);
}

t_champ	*champ_dup(t_champ *father, int new_pos)
{
  t_champ	*son;

  if ((son = malloc(sizeof(t_champ))) == NULL)
    exit(-1);
  son->head = father->head;
  son->path = father->path;
  son->fd = father->fd;
  son->champ_nb = father->champ_nb;
  son->pc = father->pc + new_pos;

  //son->reg = reg_dup(father->reg);
  int	i;
  i = 0;
  while (i < REG_NUMBER)
    {
      son->reg[i] = father->reg[i];
      i++;
    }

  son->carry = father->carry;
  son->wait = -1;
  son->color = father->color;
  son->next = NULL;
  son->prev = NULL;
  return (son);
}

int	add_champ(t_champ *champ, int new_pos)
{
  t_champ	*son;

  if ((son = malloc(sizeof(t_champ))) == NULL)
    exit(-1);
  son = champ_dup(champ, new_pos);
  son->prev = champ;
  son->next = champ->next;
  champ->next = son;
  if (son->next != NULL)
    son->next->prev = son;
  return (0);
}

int	my_fork(t_champ *champ, t_cor *cor)
{
  int	fork_dest;

  fork_dest = get_nbr_action(cor->mem, champ->pc + 1, 2);

  my_printf(1, "FORK du champion %s, vers la case mémoire : %d + PC\n", champ->head->prog_name, fork_dest);
  add_champ(champ, fork_dest);
  my_printf(1, "Le champion %s(%d) a fait un fils qui porte son nom : %s(%d)\n",champ->head->prog_name, champ->champ_nb, champ->next->head->prog_name, champ->next->champ_nb);


  int	len;
  len = read(champ->next->fd, cor->mem + champ->next->pc, champ->next->head->prog_size);
  printf("J'ai lu %d byte avec ce putain de read\n", len);
  if (len < champ->next->head->prog_size)
    {
    len = read(champ->next->fd, cor->mem + champ->next->pc + len, champ->next->head->prog_size);
  printf("J'ai lu %d byte au deuxième essaie.\n", len);
    }
  close(champ->next->fd);
  (void)len;
//Ca me casse les couilles j'arrive pas a utiliser cette putain de fonction read correctement. FUCK les fonctions système !!


  aff_memdr(cor->mem);
  my_putstr("\n\n\n", 1);
  
  exit(0);

  champ->pc += 3;
  my_putstr(", avance dans la mémoire de 2\n", 1);
  return (3);
}

int	my_lfork(t_champ *champ, t_cor *cor)
{
  int	frk;

  my_putstr("lfork du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", vers le numéro : ", 1);
  frk = get_nbr_action(cor->mem, champ->pc + 1, 2);
  my_putnbr(frk, 1);
  my_putstr(", avance dans la mémoire de 2\n", 1);
  return (3);
}

int	my_none(t_champ *champ, t_cor *cor)
{
  (void)cor;
  my_printf(1, "NONE du champion %s\n", champ->head->prog_name);
  my_putstr("Avance dans la mémoire de 1\n", 1);
  champ->pc++;
  return (0);
}
