/*
** other_fun.c for other_fun in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:20:50 2014 Thibaut Lopez
** Last update Wed Apr  9 22:46:24 2014 thibaud
*/

#include "vm.h"
#include "my.h"

void	my_st(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);

  printf("Octet d'encodage : %X\n", cor->mem[champ->pc + 1]);
  printf("Encode = \n%d %d %d\n %d %d %d\n", tab[0][0], tab[0][1], tab[0][2], tab[1][0], tab[1][1], tab[1][2]);
  if ((tab[0][0] == 1 && check_reg(tab[0][2]))
      && ((tab[1][0] == 1 && check_reg(tab[1][2])) || tab[1][0] == 3) &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      if (tab[1][0] == 1)
	champ->reg[tab[1][2] - 1] = champ->reg[tab[0][2] - 1];
      else
	{
	  printf("ST\n");
	  print_on_mem(cor, champ->reg[tab[0][2] - 1], champ->pc + tab[1][2]);
	  change_case_mem(champ->pc + tab[1][2], champ->color, cor->screen);
	}
      change_pos_pc(champ, champ->pc + tab[0][1] + tab[1][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + 2;
    }
  else
    {
      my_putstr("ST FAILLL\n", 1);
      aff_mem(cor->mem);
      printf("PC = %X\n", champ->pc + 1);
      //exit(0);
    }

  printf("Encode = \n%d %d %d\n %d %d %d\n", tab[0][0], tab[0][1], tab[0][2], tab[1][0], tab[1][1], tab[1][2]);
  if (tab[0][2] == 3)
    {
      printf("LE NOMBRE CHIANT TROUVE\n");
      printf("r3 = %d\n", champ->reg[2]);
      aff_mem(cor->mem);
      //exit(0);
    }

  change_pos_pc(champ, champ->pc + tab[0][1] + tab[1][1] + 2, cor->screen);
  ifree(tab, 4);
}

void	my_sti(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2])
      && (tab[1][0] > 1 || (tab[1][0] == 1 && check_reg(tab[1][2])))
      && ((tab[2][0] == 1 && check_reg(tab[2][2])) || tab[2][0] == 2) &&
      tab[3][0] == 0)
    {
      if (champ->champ_nb == 1)
	printf("STI\n");
      print_on_mem(cor, champ->reg[tab[0][2] - 1],
		   champ->pc + tab[1][2] + tab[2][2]);
      change_case_mem(champ->pc + tab[1][2] + tab[2][2],
		      champ->color, cor->screen);
      change_pos_pc(champ,
		    champ->pc + tab[0][1] + tab[1][1] + tab[2][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    {
      my_putstr("STI FAIL\n", 1);
      //exit(0);
      if (champ->champ_nb == 1)
	printf("STI (fail)\n");
      my_none(champ, cor);
    }
  ifree(tab, 4);
}

void	my_aff(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && check_reg(tab[0][2]) && tab[1][0] == 0 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      //champ->carry *= -1;
      //champ->carry = 1;
      if (champ->champ_nb == 1)
	printf("AFF\n");
      champ->carry = 1;
      my_putchar(champ->reg[tab[0][2]] % 256, 1);
      change_pos_pc(champ, champ->pc + 6, cor->screen);
      champ->pc += 6;
    }
  else
    {
      if (champ->champ_nb == 1)
	printf("AFF (fail)\n");
      my_none(champ, cor);
    }
  ifree(tab, 4);
}
