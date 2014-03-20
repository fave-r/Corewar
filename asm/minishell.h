/*
** minishell.h for minishell in /home/blackbird/work/minishell/1
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Dec 18 14:13:39 2013 romaric
** Last update Mon Jan  6 20:37:43 2014 romaric
*/

#ifndef __MINISHELL__
#define __MINISHELL__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct  s_word
{
  int   nbwords;
  int   i;
  char  **strpar;
  char  *ptr;
}               t_word;

typedef struct	s_mainini
{
  char  *buff;
  char  **str;
  char  **envcpy;
  int   pathi;
  char  *path;
  char  **pathsep;
  char  *cmd;
}		t_mainini;

int	main(int ac, char **av, char **env);
int     my_putchar(char c);
int     my_strlen(char *str);
int     my_putstr(char *str, int outpout);
int     xopen(const char *pathname, int flags);
ssize_t xread(int fd, void *buf, size_t count);
void    *xmalloc(size_t n);
int     countword(char *str, char sep);
char    **my_str_to_wordtab(char *str, char sep);
char    *my_strcpy(char *dest, char *src);
char    **envcy(char **env);
int     checkenv(char **env);
char    **my_str_to_wordtabmodif(char *str);
int     countwordmodif(char *str);
int     my_strncmp(char *s1, char *s2, int n);
int      checkpath(char **env);
char    *pathcpy(char **env, int i);
char    *rmpath(char *dest, char *src);
int     checkpathfile(char *dir, char *filename);
char    *checkpathname(char *path, char *file);
void	check(char **str);
int     my_strcmp(char *s1, char *s2);
char    *find_lib(char **path, char *cmd);
char    *my_strdup(char *src);
int     execute(char *pathutil, char *cmd, char **env, char **arv);
char    *my_strcpyfinal(char *dest, char *cmd);
void    handle_signal(int signo);
void    writenotfound(char *cmd);
char    *chkbuiltin(char **pathsep, char *cmd, char **arv);
int     my_getnbr(char *str);
int     is_nume(char l);
int     is_negative(char *str);
char    *aux_main(char **pathsep, char *cmd, char **str, char **env);
void    aux_man(char ***pathsep, char **path);

#endif
