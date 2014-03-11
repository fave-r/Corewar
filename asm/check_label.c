/*
** check_label.c for Corewar in /home/blackbird/work/Corewar/asm
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Mar 11 13:02:00 2014 romaric
** Last update Tue Mar 11 14:02:14 2014 romaric
*/

void	check_label(char *str)
{
  int	fd;
  char	*line;
  int	i;

  i = -1;
  fd = xopen(str, O_RDONLY);
  while ((line = get_next_line(fd)))
    {
      while (line[++i] != ':' || line[++i] != '\0')
	i = i; //ceci est une line qui ne sert a rien mais oblige par la boucle
      i--;
      if (line[i] == '%')
	ckeck_for_label(fd);
      i++;
      if (line[i] != '\0')
	create_label(fd);
      i = -1;
    }
}

void	check_for_label(int fd)
{

}

void	create_label(int fd)
{

}
