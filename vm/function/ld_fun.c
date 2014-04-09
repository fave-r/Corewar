/*
** ld_fun.c for ld in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:11:21 2014 Thibaut Lopez
<<<<<<< HEAD:vm/Function/ld_fun.c
** Last update Wed Apr  2 17:55:47 2014 thibaud
=======
** Last update Wed Apr  9 10:13:14 2014 Thibaut Lopez
>>>>>>> 0bdc69373077ab9e9596fe66f10e1dabcab981e4:vm/function/ld_fun.c
*/

#include "vm.h"
#include "my.h"

void	my_ld(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	arg;
  int	err;

  err = 0;
  tab = get_encode(cor->mem, champ->pc);
  arg = get_dir_ind_arg(tab[0], champ, cor->mem, &err);
  printf("Octet d'encodage : %X\n", cor->mem[champ->pc + 1]);
  printf("%d != -1\n%d == 1\n %d == 1\n%d == 0\n%d == 0\n", err, tab[1][0], check_reg(tab[1][2]), tab[2][0], tab[3][0]);
  if (err != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
<<<<<<< HEAD:vm/Function/ld_fun.c
      //champ->carry *= -1;
      //champ->carry = 1;
=======
      if (champ->champ_nb == 1)
	printf("LD\n");
      champ->carry = 1;
>>>>>>> 0bdc69373077ab9e9596fe66f10e1dabcab981e4:vm/function/ld_fun.c
      champ->reg[tab[1][2] - 1] = arg;
      change_pos_pc(champ, champ->pc + tab[0][1] + tab[1][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + 2;
    }
  else
    {
<<<<<<< HEAD:vm/Function/ld_fun.c
      ld = 5;
      //champ->carry = -1;
      printf("Carry = %d\n", champ->carry);
      printf("LD FAIL\n");
      aff_memdr(cor->mem);
      printf("PC = %X\n\n", champ->pc);
      //exit(0);
=======
      if (champ->champ_nb == 1)
	printf("LD (fail)\n");
      my_none(champ, cor);
      champ->carry = 0;
>>>>>>> 0bdc69373077ab9e9596fe66f10e1dabcab981e4:vm/function/ld_fun.c
    }
  ifree(tab, 4);
}

void	my_ldi(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	arg1;
  int	arg2;
  int	err;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg1 = get_all_type_arg(tab[0], champ, cor->mem, &err);
  arg2 = get_dir_reg_arg(tab[1], champ, cor->mem, &err);
  if (err != -1 &&
      (tab[2][0] == 1 && check_reg(tab[2][2]) == 1) && tab[3][0] == 0)
    {
<<<<<<< HEAD:vm/Function/ld_fun.c
      //champ->carry = 1;
      //champ->carry *= -1;
=======
      if (champ->champ_nb == 1)
	printf("LDI\n");
      champ->carry = 1;
>>>>>>> 0bdc69373077ab9e9596fe66f10e1dabcab981e4:vm/function/ld_fun.c
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      change_pos_pc(champ,
		    champ->pc + tab[0][1] + tab[1][1] + tab[2][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    {
<<<<<<< HEAD:vm/Function/ld_fun.c
      //champ->carry = -1;
      ldi = 5;
      printf("LDI FAIL\n");
      exit(0);
=======
      if (champ->champ_nb == 1)
	printf("LDI (fail)\n");
      champ->carry = 0;
      my_none(champ, cor);
>>>>>>> 0bdc69373077ab9e9596fe66f10e1dabcab981e4:vm/function/ld_fun.c
    }
  ifree(tab, 4);
}

void	my_lld(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	arg;
  int	err;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg = get_dir_ind_arg_noidx(tab[0], champ, cor->mem, &err);
  if (err != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
<<<<<<< HEAD:vm/Function/ld_fun.c
      //champ->carry = 1;
      //champ->carry *= -1;
=======
      if (champ->champ_nb == 1)
	printf("LLD\n");
      champ->carry = 1;
>>>>>>> 0bdc69373077ab9e9596fe66f10e1dabcab981e4:vm/function/ld_fun.c
      champ->reg[tab[1][2] - 1] = arg;
      change_pos_pc(champ, champ->pc + tab[0][1] + tab[1][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + 2;
    }
  else
    {
<<<<<<< HEAD:vm/Function/ld_fun.c
      ld = 5;
      //champ->carry = -1;
      printf("LLD FAIL\n");
=======
      if (champ->champ_nb == 1)
	printf("LLD (fail)\n");
      my_none(champ, cor);
      champ->carry = 0;
>>>>>>> 0bdc69373077ab9e9596fe66f10e1dabcab981e4:vm/function/ld_fun.c
    }
  ifree(tab, 4);
}

void	my_lldi(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	arg1;
  int	arg2;
  int	err;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg1 = get_all_type_arg_noidx(tab[0], champ, cor->mem, &err);
  arg2 = get_dir_reg_arg(tab[1], champ, cor->mem, &err);
  if (err != -1 &&
      (tab[2][0] == 1 && check_reg(tab[2][2]) == 1) && tab[3][0] == 0)
    {
<<<<<<< HEAD:vm/Function/ld_fun.c
      //champ->carry = 1;
      //champ->carry *= -1;
=======
      if (champ->champ_nb == 1)
	printf("LLDI\n");
      champ->carry = 1;
>>>>>>> 0bdc69373077ab9e9596fe66f10e1dabcab981e4:vm/function/ld_fun.c
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      change_pos_pc(champ,
		    champ->pc + tab[0][1] + tab[1][1] + tab[2][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    {
<<<<<<< HEAD:vm/Function/ld_fun.c
      //champ->carry = -1;
      ldi = 5;
      printf("LLDI FAIL\n");
      exit(0);
=======
      if (champ->champ_nb == 1)
	printf("LLDI (fail)\n");
      champ->carry = 0;
      my_none(champ, cor);
>>>>>>> 0bdc69373077ab9e9596fe66f10e1dabcab981e4:vm/function/ld_fun.c
    }
  ifree(tab, 4);
}
