/*
** my.h for my in /home/thibaut.lopez/Corewar
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Sun Feb 23 21:19:02 2014 Thibaut Lopez
** Last update Thu Feb 27 15:47:04 2014 Thibaut Lopez
*/

/*
Mettre les infos du fichier dans ce sens si possible avec 2 retour à la ligne entre chaque type d'info:
#define
#include system
typedef struct
prototype de fonction
*/

#ifndef MY_H
#define MY_H
#define ER_MALLOC	"Malloc Failed\n"
#define ER_OPEN		" : Open Failed\n"
#define ER_READ		"Read Failed\n"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	convert_endian(int *nb, int endian);
int	my_endian();
int     my_getnbr(char *str);
void	my_mem_set(int *s, size_t n);
void    my_putnbr(int n, int fd);
int	my_putstr(char *str, int fd);
int	my_strchr(char src, char *dest);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *str);
int	my_strlen(char *str);
void	*xmalloc(size_t n);
int	xopen(char *pathname, int flags);
ssize_t	xread(int fd, void *buf, size_t count);

#endif
