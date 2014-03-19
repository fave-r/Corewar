/*
** refresh_graphic.c for refresh_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:40:14 2014 Thibaut Lopez
** Last update Wed Mar 19 16:24:37 2014 Thibaut Lopez
*/

#include "vm.h"

/*
change_pos_pc
Données :
	-champ, structure du champion
	-pc, position "après" du PC (important dans le cas d'un zjmp)
	-len, le nombre de bit qu'a lu le champion pour executer sa fonction
	-screen, une variable qui se trouve dans la structure cor (cor->screen)
Résultat :
	Va changer la position du curseur du champion et colorier l'endroit où celui-ci est passé en la couleur "color"
Quand l'appeller:
	A chaque fois que le PC d'un champion avance (donc à la fin de chaque fonction de la VM entre autre)
Pas encore testé
*/

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

/*
change_case_mem
Données :
	-case_mem, la case qui va être changé
	-color, la couleur du champion qui change la valeur de la case
	-screen, une variable qui se trouve dans la structure cor (cor->screen)
Résultat :
	Va colorier l'endroit où le champion change la valeur en la couleur "color"
Quand l'appeller:
	Dans certaines fonctions comme st, qui peuvent changer la valeur d'une case mémoire
Pas encore testé
*/

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
