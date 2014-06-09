/*
** ufo.h for  in /home/gysc0/rendu/une_famille_en_or
**
** Made by Zackary Beaugelin
** Login   <gysc0@epitech.net>
**
** Started on  Mon Jun  9 10:33:20 2014 Zackary Beaugelin
** Last update Mon Jun  9 17:30:26 2014 Gysc0
*/

#ifndef __UFO_H__
# define __UFO_H__

#  include <stdio.h>
#  include <unistd.h>
#  include <stdlib.h>
#  include <string.h>
#  include <fcntl.h>
#  include <sys/stat.h>
#  include <dirent.h>
#  include <pwd.h>

void	genealfs(char *path, int fd);
void	my_putnbr(int fd, int nb);
char	*my_strcat(char *str1, char *str2);

#endif /*!__UFO_H__*/
