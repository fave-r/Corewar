/*
** main.c for main in /home/alex-odet/work/sudoku/bonus
**
** Made by Alexandre Odet
** Login   <alex-odet@epitech.net>
**
** Started on  Sun Mar  2 21:08:58 2014 Alexandre Odet
** Last update Sun Mar  2 21:53:38 2014 romaric
*/

#include "struct.h"

int main(int argc, char *argv[])
{
  int	continuer;
  SDL_Event event;

  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_WM_SetCaption("Sudoku OpenGL !",NULL);
  SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
  continuer = 1;
  while (continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
	{
	case SDL_QUIT:
	  continuer = 0;
	}
      my_print_map();
    }
  SDL_Quit();
  return (0);
}

void	my_print_map()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(3,4,2,0,0,0,0,0, 1);
  glBegin(GL_QUADS);
  glColor3ub(255,0,0); //face rouge
  glVertex3d(1,1,1);
  glVertex3d(1,1,-1);
  glVertex3d(-1,1,-1);
  glVertex3d(-1,1,1);
  glColor3ub(0,255,0); //face verte
  glVertex3d(1,-1,1);
  glVertex3d(1,-1,-1);
  glVertex3d(1,1,-1);
  glVertex3d(1,1,1);
  glColor3ub(0,0,255); //face bleue
  glVertex3d(-1,-1,1);
  glVertex3d(-1,-1,-1);
  glVertex3d(1,-1,-1);
  glVertex3d(1,-1,1);
  glColor3ub(255,255,0); //face jaune
  glVertex3d(-1,1,1);
  glVertex3d(-1,1,-1);
  glVertex3d(-1,-1,-1);
  glVertex3d(-1,-1,1);
  glColor3ub(0,255,255); //face cyan
  glVertex3d(1,1,-1);
  glVertex3d(1,-1,-1);
  glVertex3d(-1,-1,-1);
  glVertex3d(-1,1,-1);
  glColor3ub(255,0,255); //face magenta
  glVertex3d(1,-1,1);
  glVertex3d(1,1,1);
  glVertex3d(-1,1,1);
  glVertex3d(-1,-1,1);
  glEnd();
  glFlush();
  SDL_GL_SwapBuffers();
}
