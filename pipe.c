/*
** pipe.c for generalfs in /home/jussea_m/epitech/generalfs/une_famille_en_or/Badrou
**
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
**
** Started on  Mon Jun  9 17:44:30 2014 jussea_m@epitech.eu
** Last update Tue Jun 10 14:49:57 2014 jussea_m@epitech.eu
*/

#include "ufo.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}

int     mission3(char **tab)
{
  int	pid;
  int	fd[2];

  if (pipe(fd) == -1)
    return (write(2, "Genealfs: Error\n", 16));
  if ((pid = fork()) < 0)
     return (-1);
  if (pid == 0)
    {
      close(fd[0]);
      dup2(fd[1], 1);
      genealfs(tab[1], 1);
      return (0);
    }
  else
    {
      close(fd[1]);
      dup2(fd[0], 0);
      execvp(tab[3], tab + 3);
      wait(NULL);
      return (0);
    }
  return (0);
}

int	main(int ac, char **av)
{
  if (ac > 2)
    {
      if(my_strcmp(av[2], "-p") == 0)
	{
	  mission3(av);
	}
    }
  return (0);
}
