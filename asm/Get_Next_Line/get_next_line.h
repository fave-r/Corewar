/*
** get_next_line.h for get_next_line in /home/blackbird/work/get_next_line
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Nov 19 19:22:47 2013 romaric
** Last update Sun Nov 24 16:56:08 2013 romaric
*/

#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 4096

typedef struct  s_get
{
  char  *s;
  int   c;
  int   l;
}               t_get;

char	*get_next_line(const int fd);
char    *my_strcpy(char *dest, char *src);
int     my_strlen(char *str);
void    my_putstr(char *str);
char    *my_strdup(char *src);
