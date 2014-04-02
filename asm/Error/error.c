/*
** error.c for error in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Mar 11 08:04:10 2014 alex-odet
** Last update Tue Apr  1 14:15:40 2014 alex-odet
*/

#include "struct.h"
#include "my.h"

void	print_header_error()
{
  my_putstr("Bad Header.\n", 2);
  my_putstr("Your Header needs to be like :\n", 2);
  my_putstr(".name \"name_of_the_champion\"\n", 2);
  my_putstr(".comment \"comment_on_your_champion\"\n", 2);
  exit(EXIT_FAILURE);
}

void	print_bad_ext(char *filename)
{
  my_putstr("Your file : ", 2);
  my_putstr(filename, 2);
  my_putstr(" Has a bad extension.\n", 2);
  my_putstr("Please Choose a file with '.s' extension.\n", 2);
  exit(EXIT_FAILURE);
}

void	print_bad_name()
{
  my_putstr("Unterminated string in the name.\n", 2);
  print_header_error();
}

void	print_bad_comment()
{
  my_putstr("Unterminated string in the comment.\n", 2);
  print_header_error();
}

void	print_bad_instruction(char *cmd)
{
  my_putstr("The instruction : ", 2);
  my_putstr(cmd, 2);
  my_putstr(" doesn't exists.\n", 2);
  exit(EXIT_FAILURE);
}
