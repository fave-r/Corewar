/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
** Last update Wed Mar 12 19:31:21 2014 Thibaut Lopez
*/

int	my_st(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, cor->pc);
  my_putstr("st du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", store ", 1);
  my_putstr(" du registre ");
  my_put_nbr(tab[0][2], 1);
  if (tab[1][0] == 1)
    my_putstr(" dans le registre ", 1);
  else
    my_putstr((tab[1][0] == 2) ? " dans le direct " : " dans le indirect ", 1);
  my_put_nbr(tab[1][2], 1);
  my_putstr(", avance dans la mémoire de ", 1);
  my_put_nbr(tab[0][1] + tab[1][1], 1);
  my_putchar('\n', 1);
  return (tab[0][1] + tab[1][1] + 2);
}

int	my_sti(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, cor->pc);
  my_putstr("ldi du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", stisation ", 1);
  my_putstr(" du registre ");
  my_put_nbr(tab[0][2], 1);
  if (tab[1][0] == 1)
    my_putstr(" au registre ");
  else
    my_putstr((tab[1][0] == 2) ? " au direct " : " au indirect ", 1);
  my_put_nbr(tab[1][2], 1);
  my_putstr(" plus", 1);
  if (tab[2][0] == 1)
    my_putstr(" le registre ");
  else
    my_putstr((tab[2][0] == 2) ? " le direct " : " le indirect ", 1);
  my_put_nbr(tab[2][2], 1);
  my_putstr(", avance dans la mémoire de ", 1);
  my_put_nbr(tab[0][1] + tab[1][1] + tab[2][1], 1);
  my_putchar('\n', 1);
  return (tab[0][1] + tab[1][1] + tab[2][1] + 2);
}

int	my_aff(t_champ *champ, t_cor *cor)
{
  my_putstr("aff du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", affichage de ", 1);
  my_put_nbr(tab[0][0], 1);
  my_putstr(", avance dans la mémoire de ", 1);
  my_put_nbr(tab[0][1], 1);
  my_putchar('\n', 1);
  return (tab[0][1] + 2);
}
