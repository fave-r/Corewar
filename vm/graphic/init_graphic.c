/*
** init_graphic.c for init_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:16:50 2014 Thibaut Lopez
** Last update Sat Apr 12 20:16:10 2014 Thibaut Lopez
*/

#include "vm.h"

void	init_color_champ(t_sdl *cor, t_champ *champ)
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

void	fill_arena(t_sdl *cor, t_champ *champ)
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
	  SDL_FillRect(cor->arena, &position, champ->color);
	  i++;
	}
      champ = champ->next;
    }
  position.x = (MEM_SIZE - 1) % 149 * 10;
  position.y = (MEM_SIZE - 1) / 149 * 20;
  position.w = 1490 - position.x;
  SDL_FillRect(cor->arena, &position,
	       SDL_MapRGB(cor->arena->format, 127, 127, 127));
  position.x = 20;
  position.y = 150;
  SDL_BlitSurface(cor->arena, NULL, cor->screen, &position);
}

void	loop_name(SDL_Rect *position, t_sdl *cor, int i, t_champ *tmp)
{
  SDL_Color	color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  position->w = 15;
  position->h = 30;
  SDL_FillRect(cor->screen, position, tmp->color);
  position->x += 50;
  cor->name[i] = TTF_RenderText_Solid(cor->font,
				      tmp->head->prog_name, color);
  SDL_BlitSurface(cor->name[i], NULL, cor->screen, position);
  position->x -= 50;
  position->y += 35;
}

void	name_champ(t_sdl *cor, t_champ *champ)
{
  int		i;
  t_champ	*tmp;
  SDL_Rect	position;

  position.x = 100;
  position.y = 10;
  i = 0;
  if ((cor->font = TTF_OpenFont("graphic/varsity_regular.ttf", 20)) == NULL)
    exit(0);
  tmp = champ;
  while (tmp != NULL)
    {
      loop_name(&position, cor, i, tmp);
      i++;
      tmp = tmp->next;
    }
  if (i < 4)
    cor->name[i] = NULL;
}

int	init_graphic(t_sdl *cor, t_champ *champ)
{
  SDL_Rect	position;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (1);
  if (TTF_Init() == -1)
    return (1);
  if ((cor->screen = SDL_SetVideoMode(1530, 1010, 32, SDL_SWSURFACE)) == NULL)
    return (1);
  SDL_WM_SetCaption("Corewar VM", NULL);
  SDL_FillRect(cor->screen, NULL, SDL_MapRGB(cor->screen->format, 150, 150, 150));
  position.x = 0;
  position.y = 0;
  cor->bg = SDL_LoadBMP("graphic/cyber-photo-2.bmp");
  if (cor->bg != NULL)
    SDL_BlitSurface(cor->bg, NULL, cor->screen, &position);
  cor->arena = SDL_CreateRGBSurface(SDL_HWSURFACE, 1490, 840, 32, 0, 0, 0, 0);
  SDL_FillRect(cor->arena, NULL, SDL_MapRGB(cor->arena->format, 0, 0, 0));
  init_color_champ(cor, champ);
  name_champ(cor, champ);
  fill_arena(cor, champ);
  SDL_Flip(cor->screen);
  return (0);
}
