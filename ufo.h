/*
** ufo.h for  in /home/gysc0/rendu/une_famille_en_or
**
** Made by Zackary Beaugelin
** Login   <gysc0@epitech.net>
**
** Started on  Mon Jun  9 10:33:20 2014 Zackary Beaugelin
** Last update Tue Jun 10 17:02:30 2014 Gysc0
*/

#ifndef __UFO_H__
# define __UFO_H__

#  include <stdio.h>
#  include <unistd.h>
#  include <stdlib.h>
#  include <string.h>
#  include <fcntl.h>
#  include <sys/stat.h>
#  include <sys/types.h>
#  include <sys/wait.h>
#  include <dirent.h>
#  include <pwd.h>

int	genealfs(char *path, int fd, int ret);
void	my_putnbr(int fd, int nb);
char	*my_strcat(char *str1, char *str2);
int	my_strlen(char *str);
int	my_strncmp(char *s1, char *s2, int n);
void	*xmalloc(int size);
int	mission3(char **tab, int ret);

#endif /*!__UFO_H__*/
