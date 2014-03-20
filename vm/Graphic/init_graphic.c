/*
** init_graphic.c for init_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:16:50 2014 Thibaut Lopez
** Last update Wed Mar 19 16:24:38 2014 Thibaut Lopez
*/

#include "vm.h"

void	init_color_champ(t_cor *cor, t_champ *champ)
{
  int		i;

  i = 0;
  while (champ != NULL)
    {
      if (i == 0)
	champ->color = SDL_MapRGB(cor->screen->format, 255, 0, 0);
      else if (i == 1)
	champ->color = SDL_MapRGB(cor->screen->format, 0, 255, 0);
      else if (i == 2)
	champ->color = SDL_MapRGB(cor->screen->format, 0, 0, 255);
      else
	champ->color = SDL_MapRGB(cor->screen->format, 255, 255, 0);
      i++;
      champ = champ->next;
    }
}

void	fill_screen(t_cor *cor, t_champ *champ)
{
  int		i;
  SDL_Rect	position;

  position.w = 10;
  position.h = 20;
  while (champ != NULL)
    {
      i = 0;
      while (i < champ->head->prog_size)
	{
	  position.x = (champ->pc + i) % (MEM_SIZE - 1) % 149 * 10;
	  position.y = (champ->pc + i) % (MEM_SIZE - 1) / 149 * 20;
	  SDL_FillRect(cor->screen, &position, (i == 0) ? 0xFFFFFF : champ->color);
	  i++;
	}
      champ = champ->next;
    }
  position.x = (MEM_SIZE - 1) % 149 * 10;
  position.y = (MEM_SIZE - 1) / 149 * 20;
  position.w = 1490 - position.x;
  SDL_FillRect(cor->screen, &position,
	       SDL_MapRGB(cor->screen->format, 127, 127, 127));
}

int	init_graphic(t_cor *cor)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (1);
  if ((cor->screen = SDL_SetVideoMode(1490, 840, 32, SDL_SWSURFACE)) == NULL)
    return (1);
  SDL_WM_SetCaption("Corewar VM", NULL);
  SDL_FillRect(cor->screen, NULL, SDL_MapRGB(cor->screen->format, 0, 0, 0));
  init_color_champ(cor, cor->champ);
  fill_screen(cor, cor->champ);
  SDL_Flip(cor->screen);
  return (0);
}
