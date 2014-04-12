/*
** information.c for information in /home/thibaut.lopez/Corewar/Corewar/vm
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Sat Apr 12 22:20:42 2014 Thibaut Lopez
** Last update Sat Apr 12 23:17:47 2014 Thibaut Lopez
*/

#include "my.h"
#include "vm.h"

void	refresh_info(t_cor *cor)
{
  char		*tmp;
  SDL_Color	color;
  SDL_Rect	position;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  position.x = 700;
  position.y = 10;
  SDL_BlitSurface(cor->graphic.ctd[0], NULL, cor->graphic.screen, &position);
  position.x += position.w;
  tmp = my_nbr_to_char(cor->cycle_to_die, cor->cycle_to_die);
  cor->graphic.ctd[1] = TTF_RenderText_Blended(cor->graphic.font, tmp, color);
  free(tmp);
  SDL_BlitSurface(cor->graphic.ctd[1], NULL, cor->graphic.screen, &position);
  SDL_Flip(cor->graphic.screen);
}

void	init_information(t_sdl *cor)
{
  char		*tmp;
  SDL_Color	color;
  SDL_Rect	position;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  position.x = 700;
  position.y = 10;
  cor->ctd[0] = TTF_RenderText_Blended(cor->font,
				       "CYCLE_TO_DIE = ", color);
  SDL_BlitSurface(cor->ctd[0], NULL, cor->screen, &position);
  position.x += position.w;
  tmp = my_nbr_to_char(CYCLE_TO_DIE, CYCLE_TO_DIE);
  cor->ctd[1] = TTF_RenderText_Blended(cor->font, tmp, color);
  free(tmp);
  SDL_BlitSurface(cor->ctd[1], NULL, cor->screen, &position);
}
