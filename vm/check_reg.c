/*
** check_reg.c for vm in /home/thibaud/rendu/Corewar/Corewar/vm
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Fri Mar 21 08:59:00 2014 thibaud
** Last update Fri Mar 21 09:26:51 2014 thibaud
*/

#include "vm.h"

int	check_reg(int reg_nb)
{
  if (reg_nb <= REG_NUMBER && reg_nb > 0)
    return (1);
  return (0);
}
