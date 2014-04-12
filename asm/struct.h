/*
** struct.h for corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Thu Mar 13 10:29:46 2014 romaric
** Last update Sun Apr 13 01:05:46 2014 alex-odet
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

#define BUFF_SIZE 4096
#define COR_EXT ".cor"
#define COR_SEP "%:,"

typedef struct	s_get
{
  char		*s;
  int		c;
  int		l;
}		t_get;

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
}		t_label;

typedef struct	s_file
{
  struct s_file *next;
  char		*name_file;
}		t_file;

typedef struct	s_cmd
{
  char		*cmd;
  int		*(*ptr)(char *, int *, int fd);
}		t_cmd;

typedef struct	s_chkcmd
{
  int		fd;
  char		*tmp;
  int		i;
  char		*cmd;
  char		**line;
}		t_chkcmd;

typedef struct	s_chklab
{
  int	fd;
  char	*tmp;
  char	*save;
}		t_chklab;

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
int		create_cor(char *name, header_t *header);
void		print_assembling(char *name, header_t *header);
void		check_cmd(char *str, t_label *list);
char		*cmd_exist(char *str, int *bool);
void		my_show_list(t_label *list);
t_label		*fill_list_of_label(char *str);
t_label		*my_put_in_list(t_label *list, char *name);
t_label		*new_node(char *name);
t_label		*check_label(char *tmp, t_label *list);
t_label		*copy_label(char *tmp, int len, t_label *list);
void		my_show_file_list(t_file *list);
t_file		*create_node(char *name);
t_file		*my_put_in_file_list(t_file *list, char *name);
void		send_file_to_parser(t_file *list);
void		check_cmd_exist(char *cmd);
char		*my_get_strdup(char *src);
char		*cmd_next_label(char *cmd, int *j, int i, char *str);
int		my_strlen_mod(char *str);
void		check_cmd_arg(char *args, char *cmd, t_label *list);
void		operations(t_get *l, int *i, char buff[]);
void		operationss(char buff[], int *i, int *a);
void		check_arg(char *cmd, char *args, t_label *list);
void		print_bad_ext(char *filename);
void		print_bad_name();
void		print_bad_comment();
int		count_dot(char *str, int i, char c);
void		print_bad_instruction(char *cmd);
void		check_live(char *args, char *cmd, t_label *list);
int		check_label_exist(t_label *list, char *label_check);
int		*my_write_live(char *value, int *len, int fd);
int		*my_write_zjmp(char *value, int *len, int fd);
char		*my_fill_buff(char *str, int fd);
int		*my_write_fork(char *value, int *len, int fd);
int		*my_write_lfork(char *value, int *len, int fd);
int		my_file_list_size(t_file *list);
void		check_ld(char *args, char *cmd, t_label *list);
char		*copi_labelde(char *args);
void		printthiserror(char *cmd);
void		printthisseconderror(char *cmd);
void		errorlabel(char *label);
void		errorvalue(char *args);
void		errorvaluereg(char *args);
void		check_st(char *args, char *cmd);
void		check_add(char *args, char *cmd);
void		check_and(char *args, char *cmd, t_label *list);
char		encode_octet(char *args);
int		*my_write_ld(char *args, int *len, int fd);
char		*copi_labeldei(char *args, int x);
void		check_ldi(char *args, char *cmd, t_label *list);
void		check_stinext(char *args, char *cmd, t_label *list);
void		check_aff(char *args, char *cmd);
int		count_args(char *args);
int		*write_add(char *args, int *len, int fd);
int		*write_sub(char *args, int *len, int fd);
int		*write_aff(char *arg, int *len, int fd);
int		*write_and(char *args, int *len, int fd);
int		*write_arg_and(char *args, int *len, int fd);
int		*write_ldi(char *args, int *len, int fd);
int		*write_ldi_arg(char *arg, int *len, int fd);
int		*write_lld(char *args, int *len, int fd);
int		*write_lld_arg(char *arg, int *len, int fd);
int		*write_lldi(char *args, int *len, int fd);
int    		*write_lldi_arg(char *args, int *len, int fd);
int		*write_or(char *args, int *len, int fd);
int		*write_arg_or(char *args, int *len, int fd);
int		*write_xor(char *args, int *len, int fd);
int		*write_arg_xor(char *args, int *len, int fd);
int		*my_write_st(char *args, int *len, int fd);
int		*write_sti(char *args, int *len, int fd);
void		write_sti_arg(char *arg, int *len, int fd);
void		check_cmd_n(t_chkcmd ch, t_label *list);
void		parse_list(t_lst *list, int fd);
void		write_in_buff(char **cmd, int *len, int fd);
int		*write_ld_first(char *args, int *len, int fd);

#endif
