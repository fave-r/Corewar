/*
** ld_fun.c for ld in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:11:21 2014 Thibaut Lopez
** Last update Wed Apr  9 18:24:20 2014 Thibaut Lopez
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
  if (err != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1 &&
      tab[2][0] == 0 && tab[3][0] == 0)
    {
      my_putstr("\tld ", 1);
      my_printf(1, (tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
      my_printf(1, "r%d\n", tab[1][2]);
      champ->carry = 1;
      my_printf(1, "\t\t%d\n", arg);
      champ->reg[tab[1][2] - 1] = arg;
      my_printf(1, "\t\treg[%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", champ->reg[0], champ->reg[1], champ->reg[2], champ->reg[3], champ->reg[4], champ->reg[5], champ->reg[6], champ->reg[7], champ->reg[8], champ->reg[9], champ->reg[10], champ->reg[11], champ->reg[12], champ->reg[13], champ->reg[14], champ->reg[15]);
      change_pos_pc(champ, champ->pc + tab[0][1] + tab[1][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + 2;
    }
  else
    {
      my_putstr("\tld ", 1);
      my_printf(1, (tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
      my_printf(1, "r%d (%b)(fail)\n", tab[1][2], cor->mem[mod_mem(champ->pc + 1)]);
      my_none(champ, cor);
      champ->carry = 0;
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
      my_putstr("\tldi ", 1);
      my_printf(1, (tab[0][0] == 1) ? "r%d," :
		(tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
      my_printf(1, (tab[1][0] == 1) ? "r%d," : "%%%d,", tab[1][2]);
      my_printf(1, "r%d\n", tab[2][2]);
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      my_printf(1, "\t\treg[%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", champ->reg[0], champ->reg[1], champ->reg[2], champ->reg[3], champ->reg[4], champ->reg[5], champ->reg[6], champ->reg[7], champ->reg[8], champ->reg[9], champ->reg[10], champ->reg[11], champ->reg[12], champ->reg[13], champ->reg[14], champ->reg[15]);
      change_pos_pc(champ,
		    champ->pc + tab[0][1] + tab[1][1] + tab[2][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    {
      my_putstr("\tldi ", 1);
      my_printf(1, (tab[0][0] == 1) ? "r%d," :
		(tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
      my_printf(1, (tab[1][0] == 1) ? "r%d," : "%%%d,", tab[1][2]);
      my_printf(1, "r%d (fail)\n", tab[2][2]);
      champ->carry = 0;
      my_none(champ, cor);
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
      my_putstr("\tlld ", 1);
      my_printf(1, (tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
      my_printf(1, "r%d\n", tab[1][2]);
      champ->carry = 1;
      champ->reg[tab[1][2] - 1] = arg;
      my_printf(1, "\t\treg[%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", champ->reg[0], champ->reg[1], champ->reg[2], champ->reg[3], champ->reg[4], champ->reg[5], champ->reg[6], champ->reg[7], champ->reg[8], champ->reg[9], champ->reg[10], champ->reg[11], champ->reg[12], champ->reg[13], champ->reg[14], champ->reg[15]);
      change_pos_pc(champ, champ->pc + tab[0][1] + tab[1][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + 2;
    }
  else
    {
      my_putstr("\tlld ", 1);
      my_printf(1, (tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
      my_printf(1, "r%d (fail)\n", tab[1][2]);
      my_none(champ, cor);
      champ->carry = 0;
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
      my_putstr("\tlldi ", 1);
      my_printf(1, (tab[0][0] == 1) ? "r%d," :
		(tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
      my_printf(1, (tab[1][0] == 1) ? "r%d," : "%%%d,", tab[1][2]);
      my_printf(1, "r%d\n", tab[2][2]);
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      my_printf(1, "\t\treg[%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", champ->reg[0], champ->reg[1], champ->reg[2], champ->reg[3], champ->reg[4], champ->reg[5], champ->reg[6], champ->reg[7], champ->reg[8], champ->reg[9], champ->reg[10], champ->reg[11], champ->reg[12], champ->reg[13], champ->reg[14], champ->reg[15]);
      change_pos_pc(champ,
		    champ->pc + tab[0][1] + tab[1][1] + tab[2][1] + 2, cor->screen);
      champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 2;
    }
  else
    {
      my_putstr("\tlldi ", 1);
      my_printf(1, (tab[0][0] == 1) ? "r%d," :
		(tab[0][0] == 2) ? "%%%d," : "%d,", tab[0][2]);
      my_printf(1, (tab[1][0] == 1) ? "r%d," : "%%%d,", tab[1][2]);
      my_printf(1, "r%d (fail)\n", tab[2][2]);
      champ->carry = 0;
      my_none(champ, cor);
    }
  ifree(tab, 4);
}
