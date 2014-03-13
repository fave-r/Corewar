/*
** struct.h for struct in /home/odet_a/Corewar
**
** Made by
** Login   <odet_a@epitech.net>
**
** Started on  Mon Feb 17 04:27:37 2014
** Last update Thu Mar 13 10:14:56 2014 Thibaut Lopez
*/

#ifndef __COREWAR__
#define __COREWAR__

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#include "op.h"

#define BUFF_SIZE 1024
#define COR_EXT ".cor"

typedef struct	s_gnl
{
  char		*save;
  int		c;
}		t_gnl;

typedef struct s_label
{
  int	fd;
  char	*line;
  int	i;
  char	**labels;
  int	x;
  int	k;
  int	nbrlabels;  
}		t_label;

void		check_my_arg(char *str);
void		check_instructions(char *str);
char		*get_next_line(const int fd);
void		parser(char *str);
char		*cmd_by_line(char *str);
int		check(char *str);
char		*check_name(char *str);
int		count_quotes(char *str, int i);
char		*recup_name(char *str);
header_t	*fill_header(char *name, char *comment);
header_t	*init();
char		*check_comment(char *str);
char		*recup_comment(char *str);
void		print_header_error();
void		create_cor(char *name, header_t *header);
void		print_assembling(char *name, header_t *header);
void		check_label(char *str);
char		**create_label(char *line, char **labels, int i, int *y);
void		check_label_exist(char **labels, char *str, int nbrlabels);

#endif
