/*
** ld_fun.c for ld in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:11:21 2014 Thibaut Lopez
<<<<<<< HEAD
** Last update Mon Mar 31 15:36:05 2014 thibaud
=======
** Last update Wed Apr  2 13:23:50 2014 alex-odet
>>>>>>> 6bc7f99d48024bb806f7ee52e3ac6303d13f113f
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
  if (err != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      champ->carry = 1;
      champ->reg[tab[1][2] - 1] = arg;
      ld = tab[0][1] + tab[1][1] + 2;
      printf("LD SUCESS\n");
    }
  else
    {
      ld = 5;
      champ->carry = 0;
      printf("Carry = %d", champ->carry);
      printf("LD FAIL\n");
    }
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
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      ldi = tab[0][1] + tab[1][1] + tab[2][1] + 2;
      printf("LDI SUCESS\n");
    }
  else
    {
      champ->carry = 0;
      ldi = 5;
      printf("LDI FAIL\n");
    }
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
      champ->carry = 1;
      champ->reg[tab[1][2] - 1] = arg;
      ld = tab[0][1] + tab[1][1] + 2;
    }
  else
    {
      ld = 5;
      champ->carry = 0;
      printf("LLD FAIL\n");
    }
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
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      ldi = tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    {
      champ->carry = 0;
      ldi = 5;
      printf("LLDI FAIL\n");
    }
  champ->pc += ldi;
  return (ldi);
}
