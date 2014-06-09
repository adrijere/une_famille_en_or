/*
** ufo.h for badrou in /home/jussea_m/epitech/generalfs/une_famille_en_or/Badrou
** 
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
** 
** Started on  Mon Jun  9 15:26:35 2014 jussea_m@epitech.eu
** Last update Mon Jun  9 17:33:02 2014 mohamedi badr
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

void    genealfs(char *path, int fd);
void    my_putnbr(int fd, int nb);
void    *xmalloc(int size);

#endif /*!__UFO_H__*/
