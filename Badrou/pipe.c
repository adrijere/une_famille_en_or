/*
** pipe.c for generalfs in /home/jussea_m/epitech/generalfs/une_famille_en_or/Badrou
**
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
**
** Started on  Mon Jun  9 17:44:30 2014 jussea_m@epitech.eu
** Last update Tue Jun 10 10:55:52 2014 jussea_m@epitech.eu
*/


#include "ufo.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

char	*my_strcat(char *dest, char *src)
{
  int	a;
  int	b;

  a = 0;
  b = my_strlen(src);
  while (dest[b] != '\0')
    {
      dest[b] = src[a];
      b = b + 1;
      a = a + 1;
    }
  return (src);
}

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
  int	i;
  int	pid;
  int	fd;
  char	*sys_tab;

  sys_tab = xmalloc(4096);
  fd = open(tab[0], O_RDONLY);
  pid = fork();
  if (pid < 0)
    return (-1);
  else if (pid == 0)
    {
      fd = open("/tmp/tmp", O_CREAT | O_TRUNC | O_WRONLY, 0660);
      genealfs(tab[1], fd);
      dup2(fd, 0);
      i = 3;
      if  (tab[i] != NULL)
	{
	  my_strcpy(sys_tab, tab[i]);
	  while (tab[i] != NULL)
	    {
	      my_strcat(sys_tab, tab[i]);
	      i++;
	    }
	  system(sys_tab);
	}
    }
  free(sys_tab);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac > 1)
    {
      if(my_strcmp(av[2], "-p") == 0)
	mission3(av);
    }
  return (0);
}
