/*
** ld_fun.c for ld in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:11:21 2014 Thibaut Lopez
** Last update Wed Apr  2 17:55:47 2014 thibaud
*/

#include "vm.h"
#include "my.h"

int	my_ld(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	ld;
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
      //champ->carry *= -1;
      //champ->carry = 1;
      champ->reg[tab[1][2] - 1] = arg;
      ld = tab[0][1] + tab[1][1] + 2;
      printf("LD SUCESS\n");
    }
  else
    {
      ld = 5;
      //champ->carry = -1;
      printf("Carry = %d\n", champ->carry);
      printf("LD FAIL\n");
      aff_memdr(cor->mem);
      printf("PC = %X\n\n", champ->pc);
      //exit(0);
    }
  change_pos_pc(champ, champ->pc + ld, ld, cor->screen);
  champ->pc += ld;
  return (ld);
}

int	my_ldi(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	ldi;
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
      //champ->carry = 1;
      //champ->carry *= -1;
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      ldi = tab[0][1] + tab[1][1] + tab[2][1] + 2;
      printf("LDI SUCESS\n");
    }
  else
    {
      //champ->carry = -1;
      ldi = 5;
      printf("LDI FAIL\n");
      exit(0);
    }
  change_pos_pc(champ, champ->pc + ldi, ldi, cor->screen);
  champ->pc += ldi;
  return (ldi);
}

int	my_lld(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	ld;
  int	arg;
  int	err;

  tab = get_encode(cor->mem, champ->pc);
  err = 0;
  arg = get_dir_ind_arg_noidx(tab[0], champ, cor->mem, &err);
  if (err != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      //champ->carry = 1;
      //champ->carry *= -1;
      champ->reg[tab[1][2] - 1] = arg;
      ld = tab[0][1] + tab[1][1] + 2;
    }
  else
    {
      ld = 5;
      //champ->carry = -1;
      printf("LLD FAIL\n");
    }
  change_pos_pc(champ, champ->pc + ld, ld, cor->screen);
  champ->pc += ld;
  return (ld);
}

int	my_lldi(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	ldi;
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
      //champ->carry = 1;
      //champ->carry *= -1;
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      ldi = tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    {
      //champ->carry = -1;
      ldi = 5;
      printf("LLDI FAIL\n");
      exit(0);
    }
  change_pos_pc(champ, champ->pc + ldi, ldi, cor->screen);
  champ->pc += ldi;
  return (ldi);
}
