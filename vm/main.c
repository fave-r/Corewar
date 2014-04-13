/*
** main.c for vm in /home/thibaud/rendu/Corewar/vm
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Tue Feb 25 15:57:49 2014 thibaud
** Last update Sun Apr 13 19:19:32 2014 romaric
*/

#include "my.h"
#include "vm.h"

int		get_good_nbr(char *str)
{
  int		ret;

  ret = my_getnbr(str);
  if (ret < 0)
    {
      my_printf(1, "%s is not a good value (needed a number >= 0)\n", str);
      exit(0);
    }
  return (ret);
}

void		fill_champ(char **argv, t_cor *cor)
{
  int		addr;
  t_champ	*tmp;

  cor->champ = init_champ();
  tmp = cor->champ;
  addr = -1;
  while (argv[cor->cycle] != NULL)
    {
      if (my_strcmp(argv[cor->cycle], "-dump") == 0)
	cor->dump = get_good_nbr(argv[++cor->cycle]);
      else if (my_strcmp(argv[cor->cycle], "-n") == 0)
	{
	  if (move_in_list(&cor->champ, get_good_nbr(argv[++cor->cycle])) != 0)
	    exit(1);
	}
      else if (my_strcmp(argv[cor->cycle], "-a") == 0)
	addr = get_good_nbr(argv[++cor->cycle]) % MEM_SIZE;
      else if ((addr = check_champ(&(cor->champ),
				   argv[cor->cycle], addr, cor->endian)) == 1)
	exit(1);
      if (argv[cor->cycle] != NULL)
	cor->cycle++;
    }
  epur_champ(cor, &tmp);
  cor->champ = tmp;
}

int		init_champs_nb(t_cor *cor)
{
  int		i;
  t_champ	*cur_champ;

  cur_champ = cor->champ;
  i = 0;
  while (cur_champ != NULL)
    {
      cor->champs_nb[i] = cur_champ->champ_nb;
      cur_champ = cur_champ->next;
      i++;
      cor->nb_chmps_alive++;
    }
  i = 0;
  while (i++ < 4)
    {
      if (cor->champs_nb[i -1] == 0)
	cor->champs_nb[i -1] = -42;
    }
  return (0);
}

int		main(__attribute__((unused))int argc, char **argv)
{
  t_cor		cor;

  fmode();
  cor.dump = 250000;
  cor.live_done = 0;
  cor.cycle = 1;
  cor.cycle_to_die = CYCLE_TO_DIE;
  cor.endian = my_endian();
  fill_champ(argv, &cor);
  cor.cycle = 0;
  my_mem_set(cor.champs_nb, 4);
  init_adress(cor.champ);
  cor.mem = xmalloc((MEM_SIZE + 1) * sizeof(char));
  cor_mem_set(cor.mem, MEM_SIZE);
  fill_mem(&(cor.mem), cor.champ);
  cor.nb_chmps_alive = 0;
  my_mem_set(cor.live, 4);
  init_champs_nb(&cor);
  if (init_graphic(&(cor.graphic), cor.champ, cor.dump) == 1)
    return (1);
  run_corewar(cor.champ, &cor);
  free_graphic(&(cor.graphic));
  return (0);
}
