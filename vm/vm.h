/*
** vm.h for vm in /home/thibaud/rendu/Corewar/vm
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Tue Feb 25 15:49:14 2014 thibaud
** Last update Tue Feb 25 17:19:30 2014 thibaud
*/

#ifndef VM_H
#define VM_H

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "op.h"

typedef struct	s_champ
{
  header_t	head;
  char		*path;
  int		fd;
  int		champ_nb;
  int		adress;
}		t_champ;

#endif
