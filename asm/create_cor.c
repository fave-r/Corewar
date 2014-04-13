/*
** create_cor.c for create_cor in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Tue Mar 11 04:03:48 2014 alex-odet
** Last update Sun Apr 13 19:08:29 2014 romaric
*/

#include "struct.h"

int	create_cor(char *name, header_t *header)
{
  char	*new_name;
  char	*save_name;
  int	i;
  int	fd;

  i = 0;
  save_name = xmalloc(sizeof(char) * (my_strlen(name) + 3));
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
  write(fd, header, sizeof(header_t));
  free (new_name);
  return (fd);
}

void	print_assembling(char *names, char *name, char *comment)
{
  my_putstr("Assembling : ", 1);
  my_printf(1, "%s", names);
  my_putstr("\n\t", 1);
  my_printf(1, "%s", name);
  my_putstr("\n\t", 1);
  my_printf(1, "%s", comment);
  my_putstr("\n", 1);
  my_putstr("-----------------------------------------------------------\n"
	    , 1);
}
