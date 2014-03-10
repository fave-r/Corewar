/*
** parsing.c for parsing in /home/odet_a/rendu/CPE_2014_corewar/asm
**
** Made by
** Login   <odet_a@epitech.net>
**
** Started on  Mon Feb 17 18:54:21 2014
** Last update Mon Mar 10 16:03:34 2014 alex-odet
*/

#include "struct.h"
#include "op.h"

void	parser(char *str)
{
  if (str[my_strlen(str) - 1] == 's'
      && str[my_strlen(str) - 2] == '.')
    check(str);
  else
    {
      my_putstr("Bad file Extension. Please Choose a file with '.s'extension.\n", 2);
      exit(EXIT_FAILURE);
    }
}

int	check(char *str)
{
  header_t	*ptr;
  char		*name;

  ptr = xmalloc(sizeof(header_t));
  name = check_name(str);
  ptr = init();
  ptr = fill_header(name);
  return (0);
}

char	*check_name(char *str)
{
  int	fd;
  int	quotes;
  char	*tmp;
  char	*name;

  fd = xopen(str, O_RDONLY);
  tmp = get_next_line(fd);
  if (tmp[0] != '.')
    {
      my_putstr("The header is not valid.\n", 2);
      my_putstr("Your header needs to be like :\n", 2);
      my_putstr(".name \"Name_Of_The_Champion\"\n", 2);
      my_putstr(".comment \"Comment_on_your_champion\"\n", 2);
      exit(EXIT_FAILURE);
    }
  else
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
  return (name);
}

int	count_quotes(char *str, int i)
{
  int	x;

  x = 0;
  while (str[i])
    {
      if (str[i] == '"')
	x++;
      i++;
    }
  return (x);
}
