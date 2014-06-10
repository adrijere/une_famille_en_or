/*
** pipe.c for generalfs in /home/jussea_m/epitech/generalfs/une_famille_en_or/Badrou
**
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
**
** Started on  Mon Jun  9 17:44:30 2014 jussea_m@epitech.eu
** Last update Tue Jun 10 17:12:47 2014 Gysc0
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

void	put_p_error(char *s)
{
  write(2, s, my_strlen(s));
  write(2, ": command not found\n", 20);
  exit(-1);
}

int     mission3(char **tab, int ret)
{
  int	pid;
  int	fd[2];

  if (pipe(fd) == -1)
    return (write(2, "genealfs: Error\n", 16));
  if ((pid = fork()) < 0)
    return (-1);
  if (pid == 0)
    {
      close(fd[0]);
      dup2(fd[1], 1);
      ret = genealfs(tab[0], 1, 0);
      exit(ret);
    }
  else
    {
      close(fd[1]);
      dup2(fd[0], 0);
      if (execvp(tab[2], tab + 2) == -1)
	put_p_error(tab[2]);
      wait(NULL);
      exit(ret);
    }
  return (ret);
}
