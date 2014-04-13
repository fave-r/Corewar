/*
** set_label_posi.c for calc_label_pos in /home/alex-odet/work/Corewar
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Sun Apr 13 14:39:15 2014 alex-odet
** Last update Sun Apr 13 18:48:08 2014 
*/

#include "struct.h"

t_lab	*set_label_pos(char *str, t_lab *list)
{
  int	fd;
  int	cp;
  char	*tmp;
  char	**word;

  fd = xopen(str, O_RDONLY);
  cp = 0;
  while ((tmp = get_next_line(fd)))
    {
      remove_comment(tmp);
      word = my_str_to_wordtab(tmp, "\t ");
      if (word)
	{
	  list = set_label_pos_code(word, list, &cp);
	  free(word);
	}
      free(tmp);
    }
  close(fd);
  return (list);
}

t_lab	*set_label_pos_code(char **word, t_lab *list, int *cp)
{
  int	i;
  char code;

  i = -1;
  while (word[++i])
    {
      if (my_strcmp(word[i], NAME_CMD_STRING) == 0
	  || my_strcmp(word[i], COMMENT_CMD_STRING) == 0)
	return (NULL);
      else
	{
	  if ((code = word_is_instruction(word[i], cp)) != 0)
	    {
	      while (word[++i])
		check_type(word[i], code, cp);
	      return (list);
	    }
	}
      list = word_label(word[i], list, cp);
    }
  return (list);
}

t_lab	*word_label(char *word, t_lab *list, int *cp)
{
  if (word[0] != '%' && word[my_strlen(word) - 1] == LABEL_CHAR)
    list = my_put_in_lab_list(list, word, *cp);
  return (list);
}

int	word_is_instruction(char *word, int *cp)
{
  int	i;

  i = -1;
  while (op_tab[++i].mnemonique)
    {
      if (my_strcmp(op_tab[i].mnemonique, word) == 0)
	{
	  if (op_tab[i].nbr_args == 1 && op_tab[i].code != 16)
	    *cp += 1;
	  else
	    *cp += 2;
	  return (op_tab[i].code);
	}
    }
  return (0);
}

void	check_type(char *word, char code, int *cp)
{
  int	i;

  i = 0;
  if (word != NULL)
    {
      while (word[i])
	{
	  if (word[i] == 'r')
	    *cp += 1;
	  else if (word[i] == DIRECT_CHAR)
	    {
	      if (code != 9 && code != 12 && code != 10 &&
		  code != 11 && code != 14 && code != 15)
		*cp += 4;
	      else
		*cp += 2;
	    }
	  else
	    *cp += 2;
	  while (word[i] != ',' && word[i])
	    i++;
	  i++;
	}
    }
}
