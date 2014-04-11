/*
** refresh_graphic.c for refresh_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:40:14 2014 Thibaut Lopez
** Last update Thu Apr 10 15:30:36 2014 Thibaut Lopez
*/

#include "vm.h"

void	delete_killed_curs(t_champ *champ, SDL_Surface *screen)
{
  SDL_Rect	position;

  position.w = 10;
  position.h = 20;
  position.x = mod_mem(champ->pc) % 149 * 10;
  position.y = mod_mem(champ->pc) / 149 * 20;
  champ->a_col = champ->color;
  SDL_FillRect(screen, &position, champ->a_col);
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
      position.x = mod_mem(case_mem + i) % 149 * 10;
      position.y = mod_mem(case_mem + i) / 149 * 20;
      SDL_FillRect(screen, &position, color);
      i++;
    }
  SDL_Flip(screen);
}
