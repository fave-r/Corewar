/*
** ld_fun.c for ld in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:11:21 2014 Thibaut Lopez
** Last update Sat Mar 29 16:31:57 2014 thibaud
*/

#include "vm.h"
#include "my.h"

int	my_ld(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	ld;
  int	arg;

  tab = get_encode(cor->mem, champ->pc);
  arg = get_dir_ind_arg(tab, 0, champ, cor->mem);
  if (arg != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1 &&
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
      printf("LD FAIL\n");
      //exit(0);
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

  tab = get_encode(cor->mem, champ->pc);
  arg1 = get_all_type_arg(tab, 0, champ, cor->mem);
  arg2 = get_dir_reg_arg(tab, 1, champ, cor->mem);
  if (arg1 != -1 && arg2 != -1 &&
      (tab[2][0] == 1 && check_reg(tab[2][2]) == 1) && tab[3][0] == 0)
    {
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      ldi = tab[0][1] + tab[1][1] + tab[2][1] + 2;
      printf("LDI SUCESS\n");
      //exit(0);

    }
  else
    {
      champ->carry = 0;
      ldi = 5;
      printf("LDI FAIL\n");
      //exit(0);
    }
  champ->pc += ldi;
  return (ldi);
}

int	my_lld(t_champ *champ, t_cor *cor)
{
  int	**tab;
  int	ld;
  int	arg;

  tab = get_encode(cor->mem, champ->pc);
  arg = get_dir_ind_arg_noidx(tab, 0, champ, cor->mem);
  if (arg != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1 &&
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
      //exit(0);
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

  tab = get_encode(cor->mem, champ->pc);
  arg1 = get_all_type_arg_noidx(tab, 0, champ, cor->mem);
  arg2 = get_dir_reg_arg(tab, 1, champ, cor->mem);
  if (arg1 != -1 && arg2 != -1 &&
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
      //exit(0);
    }
  champ->pc += ldi;
  return (ldi);
}
