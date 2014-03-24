/*
** struct.h for corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Thu Mar 13 10:29:46 2014 romaric
** Last update Mon Mar 24 17:36:15 2014 romaric
*/

#ifndef __COREWAR__
#define __COREWAR__

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#include "op.h"
#include "my.h"

#define BUFF_SIZE 1024
#define COR_EXT ".cor"
#define COR_SEP "%:,"

typedef struct	s_get
{
  char		*s;
  int		c;
  int		l;
}		t_get;

typedef struct s_label
{
  struct s_label *next;
  char		*name;
}		t_label;

typedef struct	s_file
{
  struct s_file *next;
  char		*name_file;
}		t_file;

typedef struct	s_word
{
  int   nbwords;
  int   i;
  char  **strpar;
  char  *ptr;
}		t_word;

char		*get_next_line(const int fd);
void		parser(char *str);
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
void		check_cmd(char *str);
void		cmd_exist(char *str);
int		countword(char *str, char sep);
char		**my_str_to_wordtab(char *str, char sep);
void		my_show_list(t_label *list);
t_label		*fill_list_of_label(char *str);
t_label		*my_put_in_list(t_label *list, char *name);
t_label		*check_label(char *tmp, t_label *list);
t_label		*copy_label(char *save, char *tmp, int len, t_label *list);
void		my_show_file_list(t_file *list);
t_file		*create_node(char *name);
t_file		*my_put_in_file_list(t_file *list, char *name);
void		send_file_to_parser(t_file *list);
void		check_cmd_exist(char *cmd);
char		*my_get_strdup(char *src);
char		*cmd_next_label(char *cmd, int j, int i, char *str);

#endif
