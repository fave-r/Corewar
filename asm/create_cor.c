/*
** create_cor.c for create_cor in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Mar 11 04:03:48 2014 alex-odet
** Last update Tue Mar 11 04:24:56 2014 alex-odet
*/

#include "struct.h"

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
  new_name = strcat(save_name, COR_EXT);
  fd = xopen(new_name, O_CREAT|O_WRONLY);
  write(fd, header, sizeof(header_t));
}
