/*
** dasm.h for dasm in /home/thibaut.lopez/Corewar/Corewar/asm/Disassembler
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Apr  2 19:54:43 2014 Thibaut Lopez
** Last update Sat Apr  5 17:11:40 2014 Thibaut Lopez
*/

#ifndef __DASM__
#define __DASM__
#define NO_ARG	"Usage : ./dasm name_of_file.\n"
#define ER_COR	" is not a corewar executable.\n"
#define ER_SIZE	" take to much memory to be launched.\n"
#define S_EXT	".s"

void	create_dot_s(int fd, int new_fd, int size, char *path);
int	get_nbr_action(unsigned char *buff, int pc, int len);
int	**get_encode(unsigned char *buff, int i, int size);

int	my_live(unsigned char *buff, int fd, int i, int size);
int	my_ld(unsigned char *buff, int fd, int i, int size);
int	my_st(unsigned char *buff, int fd, int i, int size);
int	my_add(unsigned char *buff, int fd, int i, int size);
int	my_sub(unsigned char *buff, int fd, int i, int size);
int	my_and(unsigned char *buff, int fd, int i, int size);
int	my_or(unsigned char *buff, int fd, int i, int size);
int	my_xor(unsigned char *buff, int fd, int i, int size);
int	my_zjmp(unsigned char *buff, int fd, int i, int size);
int	my_ldi(unsigned char *buff, int fd, int i, int size);
int	my_sti(unsigned char *buff, int fd, int i, int size);
int	my_fork(unsigned char *buff, int fd, int i, int size);
int	my_lld(unsigned char *buff, int fd, int i, int size);
int	my_lldi(unsigned char *buff, int fd, int i, int size);
int	my_lfork(unsigned char *buff, int fd, int i, int size);
int	my_aff(unsigned char *buff, int fd, int i, int size);

#endif
