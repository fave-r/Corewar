/*
** check_arg.c for check_arg in /home/alex-odet/work/Corewar/asm/Parsing
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Tue Apr  1 09:11:47 2014 alex-odet
** Last update Wed Apr  2 15:05:13 2014 romaric
*/

#include "struct.h"

void	check_arg(char *cmd, char *args)
{
  //printf("cmd = %s\nargs = %s\n", cmd, args);
  if (my_strcmp(cmd, "live") == 0)
    check_live(args, cmd);
  if (my_strcmp(cmd, "fork") == 0)
    check_live(args, cmd);
  if (my_strcmp(cmd, "lfork") == 0)
    check_live(args, cmd);
  if (my_strcmp(cmd, "zjump") == 0)
    check_live(args, cmd);
  if ((my_strcmp("zjmp", cmd) == 0) || (my_strcmp("fork", cmd) == 0)
      || (my_strcmp("lfork", cmd) == 0))
    {
      if (args[0] != '%')
	{
	  my_putstr(cmd, 2);
	  my_putstr(" has a bad argument.\n", 2);
	  my_putstr(cmd, 2);
	  my_putstr(" needs a direct value.\n", 2);
	}
    }
}
