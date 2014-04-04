/*
** my.h for my in /home/thibaut.lopez/Corewar
**
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
**
** Started on  Sun Feb 23 21:19:02 2014 Thibaut Lopez
** Last update Fri Apr  4 19:32:15 2014 Thibaut Lopez
*/

/*
**Mettre les infos du fichier dans ce sens si
**possible avec 2 retour à la ligne entre chaque type d'info:
**#define
**#include system
**typedef struct
**prototype de fonction
*/

#ifndef MY_H
#define MY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define ER_MALLOC	"Malloc Failed\n"
#define ER_OPEN		" : Open Failed\n"
#define ER_READ		"Read Failed\n"

int		convert_endian(int *nb, int endian);
int		my_endian();
int		my_getnbr(char *str);
void		my_mem_set(int *s, size_t n);
void		my_putchar(char c, int fd);
void		my_putnbr(int n, int fd);
void		my_putnbr_base(unsigned int nb, char *base);
int		my_putstr(char *str, int fd);
char		*my_strcat(char *dest, char *src);
int		my_strchr(char src, char *dest);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strcpy(char *dest, char *src);
char		*my_strdup(char *str);
int		my_strlen(char *str);
void		*xmalloc(size_t n);
int		xopen(char *pathname, int flags);
ssize_t		xread(int fd, void *buf, size_t count);
int		my_printbin(va_list arg, int fd);
int		my_printchar(va_list arg, int fd);
int		my_printnbr(va_list arg, int fd);
int		my_printerno(va_list arg, int fd);
int		my_printlen(va_list arg, int x);
int		my_printoct(va_list arg, int fd);
int		my_printvoid(va_list arg, int fd);
int		my_printstr(va_list arg, int fd);
int		my_printstrsp(va_list arg, int fd);
int		my_printdec(va_list arg, int fd);
int		my_printhex(va_list arg, int fd);
int		my_printhexc(va_list arg, int fd);
int		my_putf_nbr(int nbr, int *i, int fd);
int		my_putfnbr_base(unsigned int nb, char *base, int *i, int fd);
int		my_putlong_base(unsigned long nb, char *base, int *i, int fd);
int		my_strflen(const char *str);
int		my_putfstr(const char *str, int fd);
int		my_printf(int fd, const char *format, ...);
void		my_memset(char *str, size_t n);
char		*my_strndup(char *src, int len);
int		mod_mem(int nb);
int		prog_size_error(char *path);
int		**ifree(int **tab, int len);
void		sfree(char **str);
short int	convert_short_endian(short int *nb, int end);

#endif
