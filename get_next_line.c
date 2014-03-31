/*
** get_next_line.c for get_next_line in /home/thibaut.lopez/rendu/CPE_2013_getnextline
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Nov 20 18:33:20 2013 Thibaut Lopez
** Last update Thu Feb 20 19:08:02 2014 Thibaut Lopez
*/

#include "gnl.h"
#include "minishell.h"

char	*cat_gnl(char *dest, char *src)
{
  int	i;
  int	j;
  int	len1;
  char	*ret;

  i = 0;
  j = 0;
  len1 = (dest == NULL) ? 0 : my_strlen(dest);
  ret = malloc((len1 + my_strlen(src) +  1) * sizeof(char));
  if (ret == NULL)
    return (NULL);
  while (dest != NULL && dest[i] != '\0')
    {
      ret[i] = dest[i];
      i++;
    }
  while (src[j] != '\0')
    {
      ret[i + j] = src[j];
      j++;
    }
  ret[i + j] = '\0';
  free(dest);
  free(src);
  return (ret);
}

int	my_check_n(char **str, char **save)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while ((*str)[i])
    {
      if ((*str)[i] == '\n')
	{
	  while ((*str)[i + j + 1])
	    {
	      (*save)[j] = (*str)[i + j + 1];
	      j++;
	    }
	  (*save)[j] = 0;
	  (*str)[i] = 0;
	  return (1);
	}
      i++;
    }
  return (0);
}

char	*get_next_line(const int fd)
{
  t_struct	ptr;
  static char	*save = NULL;

  ptr.buffer = (save != NULL) ? save : x_mem_malloc(BUFF_SIZE * sizeof(char));
  save = xmalloc(BUFF_SIZE * sizeof(char));
  ptr.str = NULL;
  ptr.bool = 0;
  while (ptr.buffer != NULL && ptr.bool != 1)
    {
      ptr.bool = my_check_n(&(ptr.buffer), &save);
      ptr.str = cat_gnl(ptr.str, ptr.buffer);
      if (ptr.bool == 0)
	{
	  ptr.buffer = xmalloc(BUFF_SIZE * sizeof(char));
	  if ((ptr.len_read = read(fd, ptr.buffer, BUFF_SIZE - 1)) <= 0)
	    {
	      ptr.bool = 1;
	      free(ptr.buffer);
	    }
	  else
	    ptr.buffer[ptr.len_read] = 0;
	}
    }
  return ((my_strlen(ptr.str) < 1 && ptr.len_read <= 0) ? NULL : ptr.str);
}
