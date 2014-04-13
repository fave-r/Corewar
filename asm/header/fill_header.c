/*
** fill_header.c for corewar in /home/blackbird/work/Corewar/asm/header
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun Apr 13 04:44:50 2014 romaric
** Last update Sun Apr 13 06:51:14 2014 alex-odet
*/

#include "struct.h"
#include "my.h"

header_t	*fill_header(char *name, char *comment, int len)
{
  int		i;
  header_t	*new;

  i = 0;
  new = xmalloc(sizeof(header_t));
  new->magic = COREWAR_EXEC_MAGIC;
  convert_endian(&(new->magic), my_endian());
  while (i < my_strlen(name) && i < PROG_NAME_LENGTH)
    {
      new->prog_name[i] = name[i];
      i++;
    }
  new->prog_name[i] = 0;
  new->prog_size = len;
  convert_endian(&(new->prog_size), my_endian());
  i = 0;
  while (i < my_strlen(comment) && i < COMMENT_LENGTH)
    {
      new->comment[i] = comment[i];
      i++;
    }
  new->comment[i] = 0;
  return (new);
}
