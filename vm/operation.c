/*
** operation.c for operation in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 12 18:52:51 2014 Thibaut Lopez
** Last update Thu Mar 20 17:19:56 2014 thibaud
** Last update Thu Mar 20 08:43:58 2014 Thibaut Lopez
** Last update Thu Mar 20 16:24:11 2014 Thibaut Lopez
*/

#include "vm.h"
#include "my.h"

int	my_add(t_champ *champ, t_cor *cor)
{
  int	**tab;

  tab = get_encode(cor->mem, champ->pc);
  if (tab[0][0] == 1 && tab[1][0] == 1 && tab[2][0] == 1 && tab[3][0] == 0 &&
      tab[0][2] > 0 && tab[0][2] <= REG_NUMBER && tab[1][2] > 0 &&
      tab[1][2] <= REG_NUMBER && tab[2][2] > 0 && tab[2][2] <= REG_NUMBER)
    {
      champ->carry = 1;
      my_printf(1, "ADD du champion : %d, ajout du registre %d au registre %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, tab[0][2], tab[1][2], tab[2][2], add);
      champ->reg[tab[0][2] - 1] = champ->reg[tab[0][0] - 1] +
	champ->reg[tab[0][1] - 1];
    }
  champ->pc += tab[0][1] + tab[1][1] + tab[2][1] + 1;
  ifree(tab, 4);
  return (add);
}

int	my_sub(t_champ *champ, t_cor *cor)
{
  int	sub;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc, &sub);
  if (tab[0][0] == 1 && tab[1][0] == 1 && tab[2][0] == 1 && tab[3][0] == 0 &&
      tab[0][2] > 0 && tab[0][2] <= REG_NUMBER && tab[1][2] > 0 &&
      tab[1][2] <= REG_NUMBER && tab[2][2] > 0 && tab[2][2] <= REG_NUMBER)
    {
      champ->carry = 1;
      my_printf(1, "SUB du champion : %d, soustraction du registre %d au registre %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, tab[0][2], tab[1][2], tab[2][2], sub);
      champ->reg[tab[0][2] - 1] = champ->reg[tab[0][0] - 1] -
	champ->reg[tab[0][1] - 1];
    }
  ifree(tab, 4);
  return (sub);
}

int	my_and(t_champ *champ, t_cor *cor)
{
  int	and;
  int	arg1;
  int	arg2;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc, &and);
  arg1 = gat_all_type_arg(tab[0][0], tab[0][2], champ, cor->mem);
  arg2 = gat_all_type_arg(tab[0][0], tab[0][2], champ, cor->mem);
  if (arg1 != -1 && arg2 != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
      tab[2][2] > 0 && tab[2][2] <= REG_NUMBER)
    {
      champ->carry = 1;
      my_printf(1, "AND du champion : %d, '&' de la valeur %d avec la valeur %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, arg1, arg2, tab[2][2], and);
      champ->reg[tab[2][2] - 1] = arg1 & arg2;
    }
  ifree(tab, 4);
  return (and);
}

int	my_or(t_champ *champ, t_cor *cor)
{
  int	or;
  int	arg1;
  int	arg2;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc, &or);
  arg1 = gat_all_type_arg(tab[0][0], tab[0][2], champ, cor->mem);
  arg2 = gat_all_type_arg(tab[0][0], tab[0][2], champ, cor->mem);
  if (arg1 != -1 && arg2 != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
      tab[2][2] > 0 && tab[2][2] <= REG_NUMBER)
    {
      champ->carry = 1;
<<<<<<< HEAD
      my_printf(1, "OR du champion : %d, '&' de la valeur %d avec la valeur %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, arg1, arg2, tab[2][2], or);
=======
      my_printf(1, "or du champion : %d, '|' de la valeur %d avec la valeur %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, arg1, arg2, tab[2][2], or);
>>>>>>> a84314d3e8bb6a7f32960e71a84c45f0a48eb8f1
      champ->reg[tab[2][2] - 1] = arg1 | arg2;
    }
  ifree(tab, 4);
  return (or);
}

int	my_xor(t_champ *champ, t_cor *cor)
{
  int	xor;
  int	arg1;
  int	arg2;
  int	**tab;

  tab = get_encode(cor->mem, champ->pc, &xor);
  arg1 = gat_all_type_arg(tab[0][0], tab[0][2], champ, cor->mem);
  arg2 = gat_all_type_arg(tab[0][0], tab[0][2], champ, cor->mem);
  if (arg1 != -1 && arg2 != -1 && tab[2][0] == 1 && tab[3][0] == 0 &&
      tab[2][2] > 0 && tab[2][2] <= REG_NUMBER)
    {
      champ->carry = 1;
<<<<<<< HEAD
      my_printf(1, "XOR du champion : %d, '&' de la valeur %d avec la valeur %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, arg1, arg2, tab[2][2], xor);
=======
      my_printf(1, "xor du champion : %d, '^' de la valeur %d avec la valeur %d stocké dans le registre %d, avance dans la mémoire de %d\n", champ->head->prog_name, arg1, arg2, tab[2][2], xor);
>>>>>>> a84314d3e8bb6a7f32960e71a84c45f0a48eb8f1
      champ->reg[tab[2][2] - 1] = arg1 ^ arg2;
    }
  ifree(tab, 4);
  return (xor);
}
