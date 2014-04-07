/*
** create_dot_s.c for create_dot_s in /home/thibaut.lopez/Corewar/Corewar/asm/Disassembler
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Fri Apr  4 12:09:28 2014 Thibaut Lopez
** Last update Sat Apr  5 17:21:42 2014 Thibaut Lopez
*/

#include "dasm.h"
#include "my.h"

int	(*command[])() =
{&my_live,
 &my_ld,
 &my_st,
 &my_add,
 &my_sub,
 &my_and,
 &my_or,
 &my_xor,
 &my_zjmp,
 &my_ldi,
 &my_sti,
 &my_fork,
 &my_lld,
 &my_lldi,
 &my_lfork,
 &my_aff};

void	create_dot_s(int fd, int new_fd, int size, char *path)
{
  int		i;
  int		add;
  unsigned int	r_len;
  unsigned char	*buff;

  buff = xmalloc((size + 2) * sizeof(char));
  r_len = read(fd, buff, size);
  if (r_len != (unsigned int)size)
    {
      my_printf(1, "Error : %s : Wrong prog_size\n", path);
      return;
    }
  buff[r_len] = 0;
  i = 0;
  while (i < size)
    {
      my_printf(1, "%X|", buff[i]);
      i++;
    }
  i = 0;
  while (i < size)
    {
      if (buff[i] <= 0 || buff[i] > 16)
	return;
      add = command[(int)buff[i] - 1](buff, new_fd, i, size);
      if (add < 0)
	return;
      i += add;
    }
}
