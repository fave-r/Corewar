/*
** main.c for main in /home/thibaut.lopez/Corewar/Corewar/asm/Disassembler
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Apr  2 19:53:38 2014 Thibaut Lopez
** Last update Wed Apr  2 22:09:54 2014 Thibaut Lopez
*/

#include "my.h"

int	open_dot_s(char *path)
{
  char	*new_name;
  char	*save_name;
  int	i;
  int	fd;

  i = 0;
  save_name = xmalloc(sizeof(char) * (my_strlen(name) - 2));
  while (name[i] != '.')
    {
      save_name[i] = name[i];
      i++;
    }
  save_name[i] = 0;
  new_name = my_strcat(save_name, S_EXT);
  free(save_name);
  fd = open(new_name, O_RDWR | O_CREAT, 0666);
  if (fd == -1)
    {
      my_printf("%s : Open failed", new_name);
      return (-1);
    }
  free (new_name);
  return (fd);
}

int	disassembler(char *path)
{
  int	fd;
  int	new_fd;

  fd = xopen(path, O_RDONLY);
  if (fd == -1)
    return (0);
  new_fd = open_dot_s(path);
  return (0);
}

int	main(int argc, char **argv)
{
  int	i;

  if (argc == 1)
    {
      my_putstr(NO_ARG, 2);
      return (1);
    }
  i = 1;
  while (argv[i] != NULL)
    {
      if (disassembler(argv[i]) == 1)
	return (1);
      i++;
    }
  return (0);
}
