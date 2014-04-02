/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
<<<<<<< HEAD
** Last update Wed Apr  2 16:33:08 2014 Thibaut Lopez
=======
** Last update Mon Mar 31 16:53:42 2014 thibaud
>>>>>>> eed21003851b4dd21d93d9a944d4b154055a2634
*/

#include "vm.h"
#include "my.h"

int	my_st(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if ((tab[0][0] == 1 && check_reg(tab[0][2]))
      && ((tab[1][0] == 1 && check_reg(tab[1][2])) || tab[1][0] == 3) &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      if (tab[1][0] == 1)
	champ->reg[tab[1][2]] = champ->reg[tab[0][2]];
      else
<<<<<<< HEAD
	{
	  print_on_mem(cor, champ->reg[tab[0][2] - 1], champ->pc + tab[1][2]);
	  change_case_mem(champ->pc + tab[1][2], champ->color, cor->screen);
	}
    }
  else
    {
      champ->carry = 0;
      my_putstr("ST FAIL\n", 1);
=======
	print_on_mem(cor, champ->reg[tab[0][2] - 1], champ->pc + tab[1][2]);
      my_putstr("ST SUCESS\n", 1);
>>>>>>> eed21003851b4dd21d93d9a944d4b154055a2634
    }
  champ->pc += tab[0][1] + tab[1][1] + 2;
  return (tab[0][1] + tab[1][1] + 2);
}

int	my_sti(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2])
      && (tab[1][0] > 1 || (tab[1][0] == 1 && check_reg(tab[1][2])))
      && ((tab[2][0] == 1 && check_reg(tab[2][2])) || tab[2][0] == 2) &&
      tab[3][0] == 0)
    {
      print_on_mem(cor, champ->reg[tab[0][2] - 1],
		   champ->pc + tab[1][2] + tab[2][2]);
      change_case_mem(champ->pc + tab[1][2] + tab[2][2], champ->color, cor->screen);
      my_putstr("STI SUCESS\n", 1);
    }
  else
    {
      my_putstr("STI FAIL\n", 1);
      //exit(0);
    }
  champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
  return (tab[0][1] + tab[1][1] + tab[2][1] + 2);
}

int	my_aff(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2]) && tab[1][0] == 0 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      champ->carry = 1;
      my_putchar(champ->reg[tab[0][2]] % 256, 1);
    }
  champ->pc += 6;
  return (6);
}
