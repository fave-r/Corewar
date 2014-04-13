/*
** main.c for main in /home/thibaut.lopez/Corewar/Corewar/asm/Disassembler
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Wed Apr  2 19:53:38 2014 Thibaut Lopez
** Last update Sun Apr 13 22:47:20 2014 romaric
*/

#include "op.h"
#include "my.h"
#include "dasm.h"

int	open_dot_s(char *path)
{
  char	*new_name;
  char	*save_name;
  int	i;
  int	fd;

  i = 0;
  save_name = xmalloc(sizeof(char) * (my_strlen(path) - 2));
  while (path[i] != '.')
    {
      save_name[i] = path[i];
      i++;
    }
  save_name[i] = 0;
  new_name = my_strcat(save_name, S_EXT);
  free(save_name);
  fd = open(new_name, O_RDWR | O_CREAT, 0666);
  if (fd == -1)
    {
      my_printf(2, "%s : Open failed", new_name);
      return (-1);
    }
  free(new_name);
  return (fd);
}

header_t	*make_header(int fd, char *path)
{
  unsigned int	r_len;
  header_t	*head;

  head = xmalloc(sizeof(header_t));
  head->magic = 0;
  head->prog_size = 0;
  r_len = read(fd, head, sizeof(header_t));
  convert_endian(&(head->magic), my_endian());
  convert_endian(&(head->prog_size), my_endian());
  if (r_len < sizeof(header_t) || head->magic != COREWAR_EXEC_MAGIC)
    {
      my_putstr(path, 2);
      my_putstr(ER_COR, 2);
      free(head);
      head = NULL;
      close(fd);
    }
  return (head);
}

void		disassembler(char *path)
{
  header_t	*head;
  int		fd;
  int		new_fd;

  fd = xopen(path, O_RDONLY);
  if (fd == -1)
    return;
  head = make_header(fd, path);
  if (head == NULL)
    return;
  new_fd = open_dot_s(path);
  if (new_fd == -1)
    return;
  my_printf(new_fd, ".name\t\t\"%s\"\n.comment\t\"%s\"\n\n",
	    head->prog_name, head->comment);
  create_dot_s(fd, new_fd, head->prog_size, path);
  close(fd);
  close(new_fd);
}

int		main(int argc, char **argv)
{
  int		i;

  if (argc == 1)
    {
      my_putstr(NO_ARG, 2);
      return (1);
    }
  i = 1;
  while (argv[i] != NULL)
    {
      disassembler(argv[i]);
      i++;
    }
  return (0);
}
