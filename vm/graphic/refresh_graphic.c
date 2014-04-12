/*
** refresh_graphic.c for refresh_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:40:14 2014 Thibaut Lopez
** Last update Sat Apr 12 14:58:08 2014 Thibaut Lopez
*/

#include "vm.h"

int	get_escape()
{
  int		wait;
  SDL_Event	event;

  if (SDL_PollEvent(&event) &&
      (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP))
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
	return (1);
      else if (event.key.keysym.sym == SDLK_SPACE && event.type == SDL_KEYDOWN)
	while (wait == 0)
	  {
	    SDL_WaitEvent(&event);
	    if (event.key.keysym.sym == SDLK_ESCAPE)
	      return (1);
	    else if (event.key.keysym.sym == SDLK_SPACE &&
		     event.type == SDL_KEYDOWN)
	      wait = 1;
	  }
    }
  return (0);
}

void	change_case_mem(int case_mem, Uint32 color, t_sdl *cor)
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
      SDL_FillRect(cor->arena, &position, color);
      i++;
    }
  position.x = 20;
  position.y = 150;
  SDL_BlitSurface(cor->arena, NULL, cor->screen, &position);
  SDL_Flip(cor->screen);
}
