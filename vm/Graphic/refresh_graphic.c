/*
** refresh_graphic.c for refresh_graphic in /home/thibaut.lopez/Corewar/Corewar/vm/Graphic
** 
** Made by Thibaut Lopez
** Login   <thibaut.lopez@epitech.net>
** 
** Started on  Wed Mar 19 09:40:14 2014 Thibaut Lopez
** Last update Wed Mar 19 10:56:03 2014 Thibaut Lopez
*/

/*
change_pos_pc
Données :
	-old_pc, qui est la position "avant" du PC
	-new_pc, position "après" du PC (important dans le cas d'un zjmp)
	-len, le nombre de bit qu'a lu le champion pour executer sa fonction
	-screen, une variable qui se trouve dans la structure cor (cor->screen)
	-color, la couleur du champion (dans sa structure, champ->color)
	Note : Il y a trop d'argument, mais on peux donner la structure t_champ *champ, qui contiendrait color et l'un des PC. Le problème est que je ne sais pas lequel.
Résultat :
	Va changer la position du curseur du champion et colorier l'endroit où celui-ci est passé en la couleur "color"
Quand l'appeller:
	A chaque fois que le PC d'un champion avance (donc à la fin de chaque fonction de la VM entre autre)
Pas encore testé
*/

void	change_pos_pc(int old_pc, int new_pc, int len, SDL_Surface *screen, Uint32 color)
{
  int		i;
  SDL_Rect	position;

  position.w = 10;
  position.h = 20;
  i = 0;
  while (i < len)
    {
      position.x = (old_pc + i) % (MEM_SIZE - 1) % 149 * 10;
      position.y = (old_pc + i) % (MEM_SIZE - 1) / 149 * 20;
      SDL_FillRect(screen, &position, color);
      i++;
    }
  position.x = (new_pc + i) % (MEM_SIZE - 1) % 149 * 10;
  position.y = (new_pc + i) % (MEM_SIZE - 1) / 149 * 20;
  SDL_FillRect(screen, &position, 0xFFFFFF);
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
}
