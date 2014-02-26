/*
** main.c for vm in /home/thibaud/rendu/Corewar/vm
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Tue Feb 25 15:57:49 2014 thibaud
** Last update Tue Feb 25 17:19:37 2014 thibaud
*/

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
      my_putstr("WARNING : Wrong value for nbr_cycle. Have been initialized at 150.\n", 2);
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

t_champ	*fill_champ(int argc, char **argv)
{
  int	i;
  int	dump;
  t_champ	*champ_list;

  dump = 150;
  i = 1;
  champ_list = malloc(sizeof (t_champ));
  while (argv[i] != NULL)
    {
      if (my_strcmp(argv[i], "-dump") == 0)
	{
	  dump = get_dump(argv[++i]);
	}
      else if (my_strcmp(argv[i], "-n") == 0)
	{
	  champ_list->champ_nb = my_getnbr(argv[++i]);
	}
      else if (my_strcmp(argv[i], "-a") == 0)
	{
	  champ_list->adress = my_getnbr(argv[++i]) % MEM_SIZE;
	}
      else
	check_champ();
      i++;
    }

}

int	main(int argc, char **argv)
{
  t_champ	*champ_list;

  champ = fill_champ(argc, argv);
  return (0);
}
