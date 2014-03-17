/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
** Last update Mon Mar 17 19:24:16 2014 thibaud
*/

#include "vm.h"
#include "my.h"

int	my_st(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  my_putstr("st du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", store ", 1);
  my_putstr(" du registre ", 1);
  my_putnbr(tab[0][2], 1);
  if (tab[1][0] == 1)
    my_putstr(" dans le registre ", 1);
  else
    my_putstr((tab[1][0] == 2) ? " dans le direct " : " dans le indirect ", 1);
  my_putnbr(tab[1][2], 1);
  my_putstr(", avance dans la mémoire de ", 1);
  my_putnbr(tab[0][1] + tab[1][1], 1);
  my_putchar('\n', 1);
  return (tab[0][1] + tab[1][1] + 2);
}

int	my_sti(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	tmp;
  int	i;
  int	oct_size;

  oct_size = 256;
  i = 0;
  tab = get_encode( cor->mem, champ->pc);
  if (tab[0][0] == 1 && tab[0][2] >= 0 && tab[0][2] <= REG_SIZE && (tab[1][0] != 0) && (tab[2][0] == 1 || tab[2][0] == 2))
    {
      tmp = tab[0][2];
      while (i < 4)
	{
	  tmp = tab[0][2] / (oct_size * (3 - i)) % (oct_size * i); 
	  cor->mem[tab[1][2] + tab[2][2] + i] = (unsigned char)tmp;
	  i++;
	}
      my_putstr("ldi du champion : ", 1);
      my_putstr(champ->head->prog_name, 1);
      my_putstr(", stisation ", 1);
      my_putstr(" du registre ", 1);
      my_putnbr(tab[0][2], 1);
      if (tab[1][0] == 1)
	my_putstr(" au registre ", 1);
      else
	my_putstr((tab[1][0] == 2) ? " au direct " : " au indirect ", 1);
      my_putnbr(tab[1][2], 1);
      my_putstr(" plus", 1);
      if (tab[2][0] == 1)
	my_putstr(" le registre ", 1);
      else
	my_putstr((tab[2][0] == 2) ? " le direct " : " le indirect ", 1);
      my_putnbr(tab[2][2], 1);
      my_putstr(", avance dans la mémoire de ", 1);
      my_putnbr(tab[0][1] + tab[1][1] + tab[2][1], 1);
      my_putchar('\n', 1);
    }
  champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 1;
  return (tab[0][1] + tab[1][1] + tab[2][1] + 1);
}

int	my_aff(t_champ *champ, t_cor *cor)
{
  my_putstr("aff du champion : ", 1);
  my_putstr(champ->head->prog_name, 1);
  my_putstr(", affichage de ", 1);
  my_putnbr(cor->mem[champ->pc + 2], 1);
  my_putstr(", avance dans la mémoire de 2\n", 1);
  return (3);
}
