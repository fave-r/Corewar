/*
** free_graphic.c for free_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:18:05 2014 Thibaut Lopez
** Last update Sun Apr 13 13:47:22 2014 Thibaut Lopez
*/

#include "vm.h"

void	free_graphic(t_sdl *cor)
{
  int	i;

  i = 0;
  while (cor->name[i] != NULL)
    {
      SDL_FreeSurface(cor->name[i]);
      i++;
    }
  SDL_FreeSurface(cor->arena);
  SDL_FreeSurface(cor->ctd[0]);
  SDL_FreeSurface(cor->ctd[1]);
  SDL_FreeSurface(cor->bg);
  TTF_CloseFont(cor->font);
  TTF_Quit();
  SDL_Quit();
}
