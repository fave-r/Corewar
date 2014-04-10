/*
** check_arg.c for check_arg in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Tue Apr  1 09:11:47 2014 alex-odet
** Last update Wed Apr  9 13:32:07 2014 romaric
*/

#include "struct.h"

void	check_argnext(char *cmd, char *args, t_label *list)
{
  if (my_strcmp(cmd, "lld") == 0)
    check_ld(args, cmd, list);
  else if (my_strcmp(cmd, "lldi") == 0)
    check_ldi(args, cmd, list);
  else if (my_strcmp(cmd, "aff") == 0)
    check_aff(args, cmd);
}

void	check_arg(char *cmd, char *args, t_label *list)
{
  if (my_strcmp(cmd, "live") == 0)
    check_live(args, cmd, list);
  else if (my_strcmp(cmd, "fork") == 0)
    check_live(args, cmd, list);
  else if (my_strcmp(cmd, "lfork") == 0)
    check_live(args, cmd, list);
  else if (my_strcmp(cmd, "zjump") == 0)
    check_live(args, cmd, list);
  else if (my_strcmp(cmd, "ld") == 0)
    check_ld(args, cmd, list);
  else if (my_strcmp(cmd, "st") == 0)
    check_st(args, cmd);
  else if (my_strcmp(cmd, "add") == 0)
    check_add(args, cmd);
  else if (my_strcmp(cmd, "sub") == 0)
    check_add(args, cmd);
  else if (my_strcmp(cmd, "and") == 0)
    check_and(args, cmd, list);
  else if (my_strcmp(cmd, "or") == 0)
    check_and(args, cmd, list);
  else if (my_strcmp(cmd, "xor") == 0)
    check_and(args, cmd, list);
  else if (my_strcmp(cmd, "ldi") == 0)
    check_ldi(args, cmd, list);
  check_argnext(cmd, args, list);
}
