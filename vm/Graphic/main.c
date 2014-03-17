/*
** main.c for main in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Mon Mar 17 17:01:09 2014 Thibaut Lopez
** Last update Mon Mar 17 20:28:58 2014 Thibaut Lopez
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <unistd.h>
#include "../../op.h"

void	my_pause()
{
  int		bool;
  SDL_Event	event;

  bool = 1;
  while (bool == 1)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
        {
	case SDL_QUIT:
	  bool = 0;
        }
    }
}

int main()
{
  int		i;
  int		col1;
  int		col2;
  int		col3;
  SDL_Surface	*screen;
  SDL_Rect	position;
  SDL_Surface	*case_mem[MEM_SIZE] = {NULL};

  screen = NULL;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return (1);
  if ((screen = SDL_SetVideoMode(1490, 840, 32, SDL_SWSURFACE)) == NULL)
    return (1);
  SDL_WM_SetCaption("COREWAR POPOPOOOOOOOOOOOOOOOO", NULL);
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 17, 206, 112));
  for (i = 0 ; i <= MEM_SIZE ; i++)
    case_mem[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 20, 32, 0, 0, 0, 0);
  col1 = 0;
  col2 = 0;
  col3 = 0;
  for (i = 0 ; i <= MEM_SIZE - 1 ; i++)
    {
      position.x = i % 149 * 10;
      position.y = i / 149 * 20;
      SDL_FillRect(case_mem[i], NULL, SDL_MapRGB(screen->format, col1, col2, col3));
      SDL_BlitSurface(case_mem[i], NULL, screen, &position);
      col1 = (col1 == 0) ? 255 : 0;
      col2 = (col2 == 0) ? 255 : 0;
      col3 = (col3 == 0) ? 255 : 0;
    }
  SDL_Flip(screen);
  my_pause();
  for (i = 0 ; i <= MEM_SIZE - 1 ; i++)
    SDL_FreeSurface(case_mem[i]);
  SDL_Quit();
  return (0);
}
