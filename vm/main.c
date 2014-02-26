/*
** main.c for vm in /home/thibaud/rendu/Corewar/vm
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Tue Feb 25 15:57:49 2014 thibaud
** Last update Wed Feb 26 18:48:45 2014 Thibaut Lopez
*/

void	rm_empty_champ(t_champ *champ, t_champ *first)
{
  t_champ	*to_free;

  if (first == tmp)
    first = first->next;
  to_free = tmp;
  tmp = tmp->next;
  tmp->prev = to_free->prev;
  to_free->prev->next = tmp;
  free(to_free);
}

void	epur_champ(t_champ *champ, t_champ *first)
{
  int		i;
  t_champ	*tmp;

  i = 0;
  tmp = champ;
  while (i < 4)
    {
      if (tmp->path == NULL && tmp != tmp->next)
	rm_empty_champ(tmp, first);
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
  char	base[16];

  len = my_strlen(nbr);
  base = "0123456789ABCDEF";
  if (len == 0 || len > 2 || my_strchr(nbr[0], base) == -1 ||
      my_strchr(nbr[1], base) == -1)
    {
      my_putstr(ER_DUMP, 2);
      return (150);
    }
  pow = (len == 2) ? 10 : 1;
  i = 0;
  ret = 0;
  while (nbr[i] != 0)
    {
      ret += my_strchr(nbr[i], base) * 16 * pow;
      pow /= 10;
      i++;
    }
  return (ret);
}

void	fill_champ(int argc, char **argv, t_cor *cor)
{
  int		addr;
  t_champ	*tmp;

  cor->champ = init_champ();
  tmp = cor->champ;
  addr = 0;
  while (argv[i] != NULL)
    {
      if (my_strcmp(argv[i], "-dump") == 0)
	cor->dump = get_dump(argv[++i]);
      else if (my_strcmp(argv[i], "-n") == 0)
	move_in_list(cor->champ, my_getnbr(argv[++i]) % 4 + 1);
      else if (my_strcmp(argv[i], "-a") == 0)
	addr = my_getnbr(argv[++i]) % MEM_SIZE;
      else
	addr = check_champ(cor->champ, argv[i], addr);
      i++;
    }
  epur_champ(cor->champ, tmp);
  cor->champ = tmp;
}

int	main(int argc, char **argv)
{
  t_champ	*tmp;
  t_cor	cor;

  cor.dump = 150;
  cor.cycle = 1;
  cor.cycle_to_die = CYCLE_TO_DIE;
  fill_champ(argc, argv, &cor);
  cor.cycle = 0;
  printf("dump = %d\n", cor->dump);
  tmp = cor->champ;
  printf("path : %s, fd = %d, nb = %d, adress = %d, prog_name = %s, comment = %s\n", tmp->path, tmp->fd, tmp->champ_nb, tmp->adress, tmp->head->prog_name, tmp->head->comment);
  tmp = tmp->next;
  while (tmp != cor->champ)
    {
      printf("path : %s, fd = %d, nb = %d, adress = %d, prog_name = %s, comment = %s\n", tmp->path, tmp->fd, tmp->champ_nb, tmp->adress, tmp->head->prog_name, tmp->head->comment);
      tmp = tmp->next;
    }
  return (0);
}
