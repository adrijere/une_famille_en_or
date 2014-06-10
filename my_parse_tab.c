/*
** parse_tab.c for rt in /home/mohame_g/rendu/Ray-Tracing
** 
** Made by mohamedi badr
** Login   <mohame_g@epitech.net>
** 
** Started on  Sun Jun  8 14:22:43 2014 mohamedi badr
** Last update Tue Jun 10 10:59:22 2014 jussea_m@epitech.eu
*/

#include "ufo.h"

char		*fill_backslash(char *str, char delim)
{
  char		a;
  int		i;

  i = 0;
  a = '\0';
  while (str[i] != a)
    {
      if (str[i] == delim)
        str[i] = a;
      i++;
    }
  return (0);
}

int		count_word(char *str, char delim)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (str[i] == delim)
        count++;
      i++;
    }
  return (count + 1);
}

int		count_char(char *str, char delim)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != delim)
    i++;
  return (i + 1);
}

void		my_cpy(int size, char *str, char *str2)
{
  int		i;

  i = 0;
  while (i < size)
    {
      str[i] = str2[i];
      i++;
    }
  str[i] = '\0';
}

char		**parse_tab(char *str, char delim)
{
  int		i;
  int		nb;
  int		cpt;
  int		size;
  int		size_str;
  char		**tab;

  i = 0;
  cpt = 0;
  nb = count_word(str, delim);
  tab = xmalloc((nb + 1) * sizeof(char *));
  size = my_strlen(str);
  size_str = 0;
  while (i <= size && cpt < nb + 1)
    {
      size_str = count_char(&str[i], delim);
      tab[cpt] = xmalloc((size_str + 1) * sizeof(char *));
      memset(tab[cpt], '\0', size_str + 1);
      my_cpy(size_str - 1, tab[cpt], &str[i]);
      //tab[cpt][size_str] = '\0';
      i += size_str;
      cpt++;
    }
  tab[cpt] = NULL;
  return (tab);
}
