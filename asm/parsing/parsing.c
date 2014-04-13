/*
** parsing.c for corewar in /home/blackbird/work/Corewar/asm/Parsing
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Mar 24 12:33:43 2014 romaric
** Last update Sun Apr 13 18:55:07 2014 romaric
*/

#include "struct.h"

void	parser(char *str)
{
  if (str[my_strlen(str) - 1] == 's'
      && str[my_strlen(str) - 2] == '.')
    check(str);
  else
    print_bad_ext(str);
}

int	check(char *str)
{
  t_label	*list;

  list = fill_list_of_label(str);
  check_cmd(str, list);
  free(list);
  return (0);
}

char	*check_name(char *str)
{
  int	fd;
  int	quotes;
  char	*tmp;
  char	*name;

  fd = xopen(str, O_RDONLY);
  name = NULL;
  while ((tmp = get_next_line(fd)))
    {
      if (my_strncmp(tmp, NAME_CMD_STRING, 5) == 0)
	{
	  quotes = count_dot(tmp, 0, '"');
	  if (quotes < 2)
	    print_bad_name();
	  else
	    return (recup_name(tmp));
	}
    }
  close (fd);
  if (name == NULL)
    print_header_error();
  return (NULL);
}
