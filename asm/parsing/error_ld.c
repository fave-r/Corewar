/*
** error_ld.c for corewar in /home/blackbird/work/Corewar/asm/parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun Apr  6 14:20:25 2014 romaric
** Last update Sun Apr 13 22:14:48 2014 romaric
*/

#include "struct.h"

void	printthiserror(char *cmd)
{
  my_printf(2, "%s needs a direct or indirect value.\n", cmd);
  my_putstr("u don't have put one.\n", 2);
  my_putstr("u can put one like this '%value' or 'value'", 2);
  exit(EXIT_FAILURE);
}

void	printthisseconderror(char *cmd)
{
  my_printf(2, "%s needs a reg.\n", cmd);
  my_putstr("u don't have put one.\n", 2);
  my_putstr("a reg value is writed like this : rnbr (ex: r5).\n", 2);
  exit(EXIT_FAILURE);
}

void	errorlabel(char *label)
{
  my_printf(2, "Undefined reference to the label : %s\n", label);
  exit(EXIT_FAILURE);
}

void	errorvalue(char *args)
{
  my_printf(2, "Wrong Value: %s\n", args);
  exit(EXIT_FAILURE);
}

void	errorvaluereg(char *args)
{
  my_printf(2, "Wrong Value of reg: %s\n", args);
  exit(EXIT_FAILURE);
}
