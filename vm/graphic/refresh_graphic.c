/*
** refresh_graphic.c for refresh_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:40:14 2014 Thibaut Lopez
** Last update Tue Apr  8 11:02:56 2014 Thibaut Lopez
*/

#include "vm.h"

void	change_pos_pc(t_champ *champ, int pc, SDL_Surface *screen)
{
  unsigned int	color;
  SDL_Rect	position;

  position.w = 10;
  position.h = 20;
  position.x = champ->pc % (MEM_SIZE - 1) % 149 * 10;
  position.y = champ->pc % (MEM_SIZE - 1) / 149 * 20;
  SDL_FillRect(screen, &position, champ->a_col);
  position.x = pc % (MEM_SIZE - 1) % 149 * 10 + 1;
  position.y = pc % (MEM_SIZE - 1) / 149 * 20 + 1;
  color = ((unsigned int*)screen->pixels)
    [position.y * (screen->pitch / sizeof(unsigned int)) + position.x];
  position.x--;
  position.y--;
  champ->a_col = color;
  SDL_FillRect(screen, &position, 0xFFFFFF);
  SDL_Flip(screen);
}

void	change_case_mem(int case_mem, Uint32 color, SDL_Surface *screen)
{
  int		i;
  SDL_Rect	position;

  i = 0;
  position.w = 10;
  position.h = 20;
  while (i < 4)
    {
      position.x = (case_mem + i) % (MEM_SIZE - 1) % 149 * 10;
      position.y = (case_mem + i) % (MEM_SIZE - 1) / 149 * 20;
      SDL_FillRect(screen, &position, color);
      i++;
    }
  SDL_Flip(screen);
}
