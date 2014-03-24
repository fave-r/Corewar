/*
** create_cor.c for create_cor in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Tue Mar 11 04:03:48 2014 alex-odet
** Last update Mon Mar 24 11:59:24 2014 romaric
*/

#include "struct.h"
#include "my.h"

void	create_cor(char *name, header_t *header)
{
  char	*new_name;
  char	*save_name;
  int	i;
  int	fd;

  i = 0;
  save_name = xmalloc(sizeof(char) * my_strlen(name) + 3);
  while (name[i] != '.')
    {
      save_name[i] = name[i];
      i++;
    }
  save_name[i] = 0;
  new_name = my_strcat(save_name, COR_EXT);
  free(save_name);
  fd = open(new_name, O_RDWR | O_CREAT, 0666);
  if (fd == -1)
    {
      my_putstr("Open Failed\n", 2);
      exit(EXIT_FAILURE);
    }
  print_assembling(name, header);
  write(fd, header, sizeof(header_t));
  free (new_name);
}

void	print_assembling(char *name, header_t *header)
{
  my_putstr("Assembling : ", 1);
  my_putstr(name, 1);
  my_putstr("\n\t", 1);
  my_putstr(header->prog_name, 1);
  my_putstr("\n\t", 1);
  my_putstr(header->comment, 1);
  my_putstr("\n", 1);
}
