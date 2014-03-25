/*
** ld_fun.c for ld in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 19:11:21 2014 Thibaut Lopez
** Last update Fri Mar 21 18:47:31 2014 Thibaut Lopez
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
  if (tab[0][0] == 3)
    aff_memdr(cor->mem);
  if (arg != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1)
    {
      champ->carry = 1;
      champ->reg[tab[1][2] - 1] = arg;
      ld = tab[0][1] + tab[1][1] + 2;
      my_printf(1, "LD du champion %s, load la valeur %d dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, arg, tab[1][2], ld);
    }
  else
    {
      ld = 5;
      champ->carry = 0;
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
  if (arg1 != -1 && arg2 != -1 && (tab[2][0] == 1) && check_reg(tab[2][2]))
    {
      aff_memdr(cor->mem);
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      ldi = tab[0][1] + tab[1][1] + tab[2][1] + 2;
      my_printf(1, "LDI du champion %s, load la valeur %d dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, champ->reg[tab[2][2] - 1], tab[2][2], ldi);
    }
  else
    ldi = 5;
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
  if (tab[0][0] == 3)
    aff_memdr(cor->mem);
  if (arg != -1 && tab[1][0] == 1 && check_reg(tab[1][2]) == 1)
    {
      champ->carry = 1;
      champ->reg[tab[1][2] - 1] = arg;
      ld = tab[0][1] + tab[1][1] + 2;
      my_printf(1, "LLD du champion %s, load la valeur %d dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, arg, tab[1][2], ld);
    }
  else
    {
      ld = 5;
      champ->carry = 0;
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
  if (arg1 != -1 && arg2 != -1 && (tab[2][0] == 1) && check_reg(tab[2][2]))
    {
      aff_memdr(cor->mem);
      champ->carry = 1;
      champ->reg[tab[2][2] - 1] = get_nbr_action(cor->mem,
						 champ->pc + arg1 + arg2, 4);
      ldi = tab[0][1] + tab[1][1] + tab[2][1] + 2;
      my_printf(1, "LLDI du champion %s, load la valeur %d dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, champ->reg[tab[2][2] - 1], tab[2][2], ldi);
    }
  else
    ldi = 5;
  champ->pc += ldi;
  return (ldi);
}