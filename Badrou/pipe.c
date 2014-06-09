/*
** pipe.c for pipe in /home/mohame_g/rendu/Systeme_unix/une_famille_en_or/Badrou
** 
** Made by mohamedi badr
** Login   <mohame_g@epitech.net>
** 
** Started on  Mon Jun  9 14:43:59 2014 mohamedi badr
** Last update Mon Jun  9 15:31:22 2014 jussea_m@epitech.eu
*/

#include "ufo.h"

int     mission3(char **com, int i, int fd, char **env)
{
  int   pfd[2];
  int   pid;
  char  **tab;

  if (i >= 0)
    {
      if (pipe(pfd) == -1)
        return (-1);
      if ((pid = fork()) == 0)
        {
          close(pfd[1]);
          dup2(pfd[0], 0);
          dup2(fd, 1);
          tab = my_str_to_wordtab_mod(' ', com[i], 0, 0);
        }
      else
        {
          close(pfd[0]);
          my_pipe(com, i - 1, pfd[1], env);
          if (i >= 0)
            wait(NULL);
          shell(env);
        }
    }
  return (0);
}

int     checkpipe(char  *str)
{
  int   n;

  n = 0;
  while (str[n])
    {
      if (str[n] == '-' && str[n + 1] == 'p')
        return (1);
      n++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  if (ac > 1)
    {
      while (av[ac] != 0)
	{
	  checkpipe(av[ac]);
	  ac--;
	}
    }
}