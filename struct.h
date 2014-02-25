/*
** struct.h for struct in /home/odet_a/Corewar
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Mon Feb 17 04:27:37 2014 
** Last update Mon Feb 24 15:04:21 2014 
*/

#ifndef __COREWAR__
#define __COREWAR__

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define BUFF_SIZE 1024

typedef struct	s_gnl
{
  char		*save;
  int		c;
}		t_gnl;

int	my_putstr(char *str, int fd);
int	my_strlen(char *str);
void	check_my_arg(char *str);
void	check_instructions(char *str);
void	*xmalloc(size_t n);
int	xopen(char *pathname, int flags);
ssize_t	xread(int fd, void *buf, size_t count);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *src);
char	*get_next_line(const int fd);
void	parser(char *str);
char	*cmd_by_line(char *str);
int	check(char *str);
void	check_name(char *str);
int	count_quotes(char *str);

#endif
