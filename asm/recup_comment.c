/*
** recup_comment.c for recup_comment in /home/alex-odet/work/Corewar/asm
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Mon Mar 10 16:12:02 2014 alex-odet
** Last update Tue Mar 11 03:56:19 2014 alex-odet
*/

#include "struct.h"

char	*check_comment(char *str)
{
  int	fd;
  int	quotes;
  char	*comment;
  char	*tmp;

  comment = NULL;
  fd = xopen(str, O_RDONLY);
  while ((my_strncmp(tmp, ".comment", 8)) != 0)
    tmp = get_next_line(fd);
  if (tmp == NULL)
    print_header_error();
  else
    {
      quotes = count_quotes(tmp, 0);
      if (quotes != 2)
	{
	  my_putstr("Unterminated string in the comment", 2);
	  exit(EXIT_FAILURE);
	}
      else
	comment = recup_comment(tmp);
    }
  return (comment);
}

char	*recup_comment(char *str)
{
  char	*save;
  int	i;
  int	j;

  i = 9;
  j = 0;
  save = xmalloc(sizeof(char) * COMMENT_LENGTH + 1);
  while (str[++i] != '"' && count_quotes(str, i) >= 1)
    {
      save[j] = str[i];
      j++;
    }
  return (save);
}
