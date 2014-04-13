/*
** check_cmdini.c for corewar in /home/blackbird/work/Corewar/asm/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Apr  8 15:28:07 2014 romaric
** Last update Sun Apr 13 22:13:50 2014 romaric
*/

#include "struct.h"

void	check_cmd_n(t_chkcmd ch, t_label *list)
{
  if (ch.i == 0)
    {
      ch.line = my_str_to_wordtab(ch.tmp, "\t");
      if (ch.line != NULL && ch.line[0] != NULL && ch.line[1] != NULL)
        check_cmd_arg(ch.line[1], ch.cmd, list);
    }
  else
    {
      ch.line = my_str_to_wordtab(ch.tmp, "\t");
      if (ch.line != NULL && ch.line[0] != NULL && ch.line[2] != NULL)
        check_cmd_arg(ch.line[2], ch.cmd, list);
    }
}
