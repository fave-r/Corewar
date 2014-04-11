/*
** refresh_graphic.c for refresh_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:40:14 2014 Thibaut Lopez
** Last update Fri Apr 11 18:06:51 2014 thibaud
*/

#include "vm.h"

void	change_case_mem(int case_mem, Uint32 color, SDL_Surface *screen)
{
  int		i;
  SDL_Rect	position;

  i = 0;
  position.w = 10;
  position.h = 20;
  while (i < 4)
    {
      position.x = mod_mem(case_mem + i) % 149 * 10;
      position.y = mod_mem(case_mem + i) / 149 * 20;
      SDL_FillRect(screen, &position, color);
      i++;
    }
  SDL_Flip(screen);
}
