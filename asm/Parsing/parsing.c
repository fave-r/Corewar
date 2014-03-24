/*
** parsing.c for parsing in /home/odet_a/rendu/CPE_2014_corewar/asm
**
** Made by
** Login   <odet_a@epitech.net>
**
** Started on  Mon Feb 17 18:54:21 2014
** Last update Mon Mar 24 09:29:14 2014 alex-odet
*/

#include "struct.h"

void	parser(char *str)
{
  if (str[my_strlen(str) - 1] == 's'
      && str[my_strlen(str) - 2] == '.')
    check(str);
  else
    {
      my_putstr("Your file : ", 2);
      my_putstr(str, 2);
      my_putstr(" Has a bad extension.\n", 2);
      my_putstr("Please Choose a file with '.s' extension.\n", 2);
      exit(EXIT_FAILURE);
    }
}

int	check(char *str)
{
  t_label	*list;
  header_t	*ptr;
  char		*name;
  char		*comment;

  ptr = init();
  name = check_name(str);
  comment = check_comment(str);
  ptr = fill_header(name, comment);
  list = fill_list_of_label(str);
  check_cmd(str);
  create_cor(str, ptr);
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
      if (my_strncmp(tmp, ".name", 5) == 0)
	{
	  quotes = count_quotes(tmp, 0);
	  if (quotes != 2)
	    {
	      my_putstr("Unterminated string in the name.\n", 2);
	      exit(EXIT_FAILURE);
	    }
	  else
	    name = recup_name(tmp);
	}
    }
  if (name == NULL)
    print_header_error();
  close (fd);
  return (name);
}

int	count_quotes(char *str, int i)
{
  int	x;

  x = 0;
  while (str[i] != 0)
    {
      if (str[i] == '"')
	x++;
      i++;
    }
  return (x);
}
