/*
** gnl_icanon.h for gnl_icanon in /home/thibaut.lopez/GNL_ICANON
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Tue Jan 21 17:24:34 2014 Thibaut Lopez
** Last update Tue Mar  4 10:38:35 2014 Thibaut Lopez
*/

#ifndef GNL_H
#define GNL_H
#define BUFF_SIZE	1024

#include <stdlib.h>
#include <termios.h>
#include <term.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <unistd.h>

typedef struct	s_struct
{
  char		*buffer;
  char		*str;
  int		len_read;
  int		bool;
}		t_struct;

char	*get_next_line(const int fd);
char	*gnl_icanon(char **env);
int	set_term(struct termios *term, char **env, char **term_name);
void	unset_term(struct termios *term, char *term_name);
char	*x_mem_malloc(int nbr);
char	*cat_gnl_icanon(char *dest, char *src);
void	my_backspace(char **result, char *buff);
void	my_enter(char **result, char *buff);
void	my_control_l(char **result, char *buff);
char	**fill_touch();
void	tfree(char **touch);

#endif
