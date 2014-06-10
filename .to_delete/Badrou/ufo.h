/*
** ufo.h for badrou in /home/jussea_m/epitech/generalfs/une_famille_en_or/Badrou
** 
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
** 
** Started on  Mon Jun  9 15:26:35 2014 jussea_m@epitech.eu
** Last update Tue Jun 10 14:36:23 2014 jussea_m@epitech.eu
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
#  include <sys/types.h>
#  include <sys/wait.h>

void		genealfs(char *path, int fd);
void		my_putnbr(int fd, int nb);
void		*xmalloc(int size);
int		my_strcmp(char *s1, char *s2);
char		*my_epur_str(char *str);
void            display(struct dirent *d, struct stat info, int fd, char *path);
void            genealfs(char *path, int fd);
int		mission3(char **tab);
char		*my_strcat(char *str1, char *str2);
int		my_strlen(char *str);

#endif /*!__UFO_H__*/
