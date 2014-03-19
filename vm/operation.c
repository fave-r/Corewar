/*
** operation.c for operation in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 18:52:51 2014 Thibaut Lopez
** Last update Wed Mar 19 18:14:33 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	my_add(t_champ *champ, t_cor *cor)
{
  int	add;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  add = tab[0][1] + tab[1][1] + tab[2][1] + tab[3][1] + 2;
  if (tab[0][2] > 0 && tab[0][2] <= REG_NUMBER &&
      tab[1][2] > 0 && tab[1][2] <= REG_NUMBER &&
      tab[2][2] > 0 && tab[2][2] <= REG_NUMBER)
    {
      champ->carry = 1;
      my_printf(1, "add du champion : %d, ajout du registre %d au registre %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, tab[0][2], tab[1][2], tab[2][2], add);
      champ->reg[tab[0][2] - 1] = champ->reg[tab[0][0] - 1] +
	champ->reg[tab[0][1] - 1];
    }
  change_pos_pc(champ, champ->pc + add, add, cor->screen);
  ifree(tab, 4);
  return (add);
}

int	my_sub(t_champ *champ, t_cor *cor)
{
  int	sub;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  sub = tab[0][1] + tab[1][1] + tab[2][1] + tab[3][1] + 2;
  if (tab[0][2] > 0 && tab[0][2] <= REG_NUMBER &&
      tab[1][2] > 0 && tab[1][2] <= REG_NUMBER &&
      tab[2][2] > 0 && tab[2][2] <= REG_NUMBER)
    {
      champ->carry = 1;
      my_printf(1, "sub du champion : %d, soustraction du registre %d au registre %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, tab[0][2], tab[1][2], tab[2][2], sub);
      champ->reg[tab[0][2] - 1] = champ->reg[tab[0][0] - 1] -
	champ->reg[tab[0][1] - 1];
    }
  change_pos_pc(champ, champ->pc + sub, sub, cor->screen);
  ifree(tab, 4);
  return (sub);
}

int	my_and(t_champ *champ, t_cor *cor)
{
  int	and;
  int	arg1;
  int	arg2;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  and = tab[0][1] + tab[1][1] + tab[2][1] + tab[3][1] + 2;
  arg1 = get_arg(tab[0][0], tab[0][2], champ->reg, cor->mem);
  arg2 = get_arg(tab[0][0], tab[0][2], champ->reg, cor->mem);
  if (arg1 != -1 && arg2 != -1 &&
      tab[2][2] > 0 && tab[0][2] <= REG_NUMBER)
    {
      champ->carry = 1;
      my_printf(1, "and du champion : %d, '&' de la valeur %d avec la valeur %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, arg1, arg2, tab[2][2], and);
      champ->reg[tab[2][2] - 1] = arg1 & arg2;
    }
  change_pos_pc(champ, champ->pc + and, and, cor->screen);
  ifree(tab, 4);
  return (and);
}

int	my_or(t_champ *champ, t_cor *cor)
{
  int	or;
  int	arg1;
  int	arg2;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  or = tab[0][1] + tab[1][1] + tab[2][1] + tab[3][1] + 2;
  arg1 = get_arg(tab[0][0], tab[0][2], champ->reg, cor->mem);
  arg2 = get_arg(tab[0][0], tab[0][2], champ->reg, cor->mem);
  if (arg1 != -1 && arg2 != -1 &&
      tab[2][2] > 0 && tab[0][2] <= REG_NUMBER)
    {
      champ->carry = 1;
      my_printf(1, "or du champion : %d, '&' de la valeur %d avec la valeur %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, arg1, arg2, tab[2][2], or);
      champ->reg[tab[2][2] - 1] = arg1 | arg2;
    }
  change_pos_pc(champ, champ->pc + or, or, cor->screen);
  ifree(tab, 4);
  return (or);
}

int	my_xor(t_champ *champ, t_cor *cor)
{
  int	xor;
  int	arg1;
  int	arg2;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  xor = tab[0][1] + tab[1][1] + tab[2][1] + tab[3][1] + 2;
  arg1 = get_arg(tab[0][0], tab[0][2], champ->reg, cor->mem);
  arg2 = get_arg(tab[0][0], tab[0][2], champ->reg, cor->mem);
  if (arg1 != -1 && arg2 != -1 &&
      tab[2][2] > 0 && tab[0][2] <= REG_NUMBER)
    {
      champ->carry = 1;
      my_printf(1, "xor du champion : %d, '&' de la valeur %d avec la valeur %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, arg1, arg2, tab[2][2], xor);
      champ->reg[tab[2][2] - 1] = arg1 ^ arg2;
    }
  change_pos_pc(champ, champ->pc + xor, xor, cor->screen);
  ifree(tab, 4);
  return (xor);
}
