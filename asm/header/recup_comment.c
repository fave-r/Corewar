/*
** recup_comment.c for recup_comment in /home/alex-odet/work/Corewar/asm
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Mon Mar 10 16:12:02 2014 alex-odet
** Last update Sun Apr 13 00:46:20 2014 alex-odet
*/

#include "struct.h"
#include "my.h"

char	*check_comment(char *str)
{
  int	fd;
  int	quotes;
  char	*comment;
  char	*tmp;

  fd = xopen(str, O_RDONLY);
  comment = NULL;
  while ((tmp = get_next_line(fd)))
    {
      if (my_strncmp(tmp, COMMENT_CMD_STRING, 8) == 0)
	{
	  quotes = count_dot(tmp, 0, '"');
	  if (quotes < 2)
	    print_bad_comment();
	  else
	    return (recup_comment(tmp));
	}
    }
  close(fd);
  if (comment == NULL)
    print_header_error();
  return (NULL);
}

char	*recup_comment(char *str)
{
  char	*save;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\"')
    i++;
  save = xmalloc(sizeof(char) * COMMENT_LENGTH + 1);
  while (str[++i] != '"' && count_dot(str, i, '"') >= 1)
    {
      save[j] = str[i];
      j++;
    }
  save[j] = 0;
  return (save);
}
