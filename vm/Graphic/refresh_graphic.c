/*
** refresh_graphic.c for refresh_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:40:14 2014 Thibaut Lopez
** Last update Thu Mar 20 16:15:41 2014 Thibaut Lopez
*/

#include "vm.h"

void	change_pos_pc(t_champ *champ, int pc, int len, SDL_Surface *screen)
{
  int		i;
  SDL_Rect	position;

  position.w = 10;
  position.h = 20;
  i = 0;
  while (i < len)
    {
      position.x = (champ->pc + i) % (MEM_SIZE - 1) % 149 * 10;
      position.y = (champ->pc + i) % (MEM_SIZE - 1) / 149 * 20;
      SDL_FillRect(screen, &position, champ->color);
      i++;
    }
  position.x = (pc + i) % (MEM_SIZE - 1) % 149 * 10;
  position.y = (pc + i) % (MEM_SIZE - 1) / 149 * 20;
  SDL_FillRect(screen, &position, 0xFFFFFF);
  SDL_Flip(screen);
}

void	change_case_mem(int case_mem, Uint32 color, SDL_Surface *screen)
{
  SDL_Rect	position;

  position.w = 10;
  position.h = 20;
  position.x = case_mem % (MEM_SIZE - 1) % 149 * 10;
  position.y = case_mem % (MEM_SIZE - 1) / 149 * 20;
  SDL_FillRect(screen, &position, color);
  SDL_Flip(screen);
}
