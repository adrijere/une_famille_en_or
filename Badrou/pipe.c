/*
** pipe.c for pipe in /home/mohame_g/rendu/Systeme_unix/une_famille_en_or/Badrou
** 
** Made by mohamedi badr
** Login   <mohame_g@epitech.net>
** 
** Started on  Mon Jun  9 14:43:59 2014 mohamedi badr
** Last update Mon Jun  9 17:33:48 2014 mohamedi badr
*/

#include "ufo.h"

char	**my_unsettab(char **tab, int i)
{
  int	j;
  char	**ret;

  j = 0;
  if (tab[0] == NULL)
    return (NULL)
  ret = xmalloc(sizeof(char *) * my_size_tab(tab) - i);
  while (tab[n])
    {
      my_strcpy(ret[j], tab[i]);
      j++;
      i++;
    }
  return (ret);
}

int     mission3(char **tab)
{
  
}

int	main(int ac, char **av)
{
  if (ac > 1)
    {
      if(my_strcmp(av[2], "-p") == 0)
	mission3(my_unsettab(av, 2));
    }
}
