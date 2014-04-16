/*
** struct.h for corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Thu Mar 13 10:29:46 2014 romaric
** Last update Wed Apr 16 18:08:58 2014 romaric
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

typedef struct	s_lab
{
  struct s_lab	*next;
  char		*lab;
  int		oct_pos;
}		t_lab;

typedef struct s_label
{
  struct s_label *next;
  char		*name;
}		t_label;

typedef struct	s_size
{
  unsigned int	len;
  int		size;
}		t_size;

typedef struct	s_cmd
{
  char		*cmd;
  void		(*ptr)(char *, t_size *, int fd, t_lab *list);
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
header_t	*fill_header(char *name, char *comment, int len);
header_t	*init();
char		*check_comment(char *str);
char		*recup_comment(char *str);
void		print_header_error();
int		create_cor(char *name, header_t *header);
void		print_assembling(char *names, char *name, char *comment);
void		check_cmd(char *str, t_label *list);
char		*cmd_exist(char *str, int *bool);
void		my_show_list(t_label *list);
t_label		*fill_list_of_label(char *str);
t_label		*my_put_in_list(t_label *list, char *name);
t_label		*new_node(char *name);
t_label		*check_label(char *tmp, t_label *list);
t_label		*copy_label(char *tmp, int len, t_label *list);
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
void		my_write_live(char *value, t_size *p, int fd, t_lab *lab);
void		my_write_zjmp(char *value, t_size *p, int fd, t_lab *lab);
int		my_fill_buff(char *str, int fd, t_lab *lab);
void		my_write_fork(char *value, t_size *p, int fd, t_lab *lab);
void		my_write_lfork(char *value, t_size *p, int fd, t_lab *lab);
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
void		my_write_ld(char *args, t_size *p, int fd, t_lab *lab);
char		*copi_labeldei(char *args, int x);
void		check_ldi(char *args, char *cmd, t_label *list);
void		check_stinext(char *args, char *cmd, t_label *list);
void		check_aff(char *args, char *cmd);
int		count_args(char *args);
void		write_add(char *args, t_size *p, int fd, t_lab *lab);
void		write_sub(char *args, t_size *p, int fd, t_lab *lab);
void		write_aff(char *arg, t_size *p, int fd, t_lab *lab);
void		write_and(char *args, t_size *p, int fd, t_lab *lab);
void		write_arg_and(char *args, t_size *p, int fd, t_lab *lab);
void		write_ldi(char *args, t_size *p, int fd, t_lab *lab);
void		write_ldi_arg(char *arg, t_size *p, int fd, t_lab *lab);
void		write_lld(char *args, t_size *p, int fd, t_lab *lab);
void		write_lld_arg(char *arg, t_size *p, int fd, t_lab *lab);
void		write_lldi(char *args, t_size *p, int fd, t_lab *lab);
void 		write_lldi_arg(char *args, t_size *p, int fd, t_lab *lab);
void		write_or(char *args, t_size *p, int fd, t_lab *lab);
void		write_arg_or(char *args, t_size *p, int fd, t_lab *lab);
void		write_xor(char *args, t_size *p, int fd, t_lab *lab);
void		write_arg_xor(char *args, t_size *p, int fd, t_lab *lab);
void		my_write_st(char *args, t_size *p, int fd, t_lab *lab);
void		write_sti(char *args, t_size *p, int fd, t_lab *lab);
void		write_sti_arg(char *arg, t_size *p, int fd, t_lab *lab);
void		check_cmd_n(t_chkcmd ch, t_label *list);
int		parse_list(t_lst *list, int fd, t_lab *lab);
int		write_in_buff(char **cmd, t_size *p, int fd, t_lab *lab);
void		write_ld_first(char *args, t_size *p, int fd, t_lab *lab);
t_lab		*new_lab_node(char *label, int oct_pos);
t_lab		*my_put_in_lab_list(t_lab *list, char *label, int oct_pos);
t_lab		*set_label_pos(char *str, t_lab *list);
t_lab		*set_label_pos_code(char **word, t_lab *list, int *cp);
t_lab		*word_label(char *word, t_lab *list, int *cp);
int		word_is_instruction(char *word, int *cp);
void		check_type(char *word, char code, int *cp);
char		*remove_comment(char *str);
char		*good_lab(t_lab *list);
char		*good_lab_call(char *value);
int		find_good_lab(t_lab *list, char *value);
int		my_cmd_size(t_lst *list);

#endif
