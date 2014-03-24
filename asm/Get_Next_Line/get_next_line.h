/*
** get_next_line.h for corewar in /home/blackbird/work/Corewar/asm/Get_Next_Line
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Mar 24 11:49:34 2014 romaric
** Last update Mon Mar 24 11:49:37 2014 romaric
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
