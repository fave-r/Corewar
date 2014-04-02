/*
** struct.h for corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Thu Mar 13 10:29:46 2014 romaric
** Last update Wed Apr  2 17:21:52 2014 romaric
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

typedef struct	s_buf
{
  char		*tmp;
  char		*buff;
}		t_buf;

typedef struct	s_lst
{
  struct s_lst	*next;
  struct s_lst	*prev;
  char		**cmd;
}		t_lst;

typedef struct s_label
{
  struct s_label *next;
  char		*name;
  int		line;
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

typedef struct	s_cmd
{
  char		*cmd;
  char		*(*ptr)(char *, int *);
}		t_cmd;

char		*get_next_line(const int fd);
void		parser(char *str);
int		check(char *str);
char		*check_name(char *str);
char		*recup_name(char *str);
header_t	*fill_header(char *name, char *comment);
header_t	*init();
char		*check_comment(char *str);
char		*recup_comment(char *str);
void		print_header_error();
void		create_cor(char *name, header_t *header);
void		print_assembling(char *name, header_t *header);
void		check_cmd(char *str);
char		*cmd_exist(char *str, int *bool);
int		count_words(char *line);
char		**my_str_to_wordtab(char *line);
void		my_show_list(t_label *list);
t_label		*fill_list_of_label(char *str);
t_label		*my_put_in_list(t_label *list, char *name, int line);
t_label		*new_node(char *name, int line);
t_label		*check_label(char *tmp, t_label *list, int line);
t_label		*copy_label(char *tmp, int len, t_label *list, int line);
void		my_show_file_list(t_file *list);
t_file		*create_node(char *name);
t_file		*my_put_in_file_list(t_file *list, char *name);
void		send_file_to_parser(t_file *list);
void		check_cmd_exist(char *cmd);
char		*my_get_strdup(char *src);
char		*cmd_next_label(char *cmd, int *j, int i, char *str);
int		my_strlen_mod(char *str);
void		check_cmd_arg(char *args, char *cmd);
void		operations(t_get *l, int *i, char buff[]);
void		operationss(char buff[], int *i, int *a);
void		check_arg(char *cmd, char *args);
void		print_bad_ext(char *filename);
void		print_bad_name();
void		print_bad_comment();
int		count_dot(char *str, int i, char c);
int		len_tab(char **tab);
void		print_bad_instruction(char *cmd);
void		check_live(char *args, char *cmd);
int		check_label_exist(t_label *list, char *label_check);

#endif
