/*
** main.c for  in /home/gysc0/rendu/une_famille_en_or
**
** Made by Zackary Beaugelin
** Login   <gysc0@epitech.net>
**
** Started on  Mon Jun  9 10:16:21 2014 Zackary Beaugelin
** Last update Tue Jun 10 12:09:47 2014 jussea_m@epitech.eu
*/

#include "ufo.h"

void		display(struct dirent *d, struct stat info, int fd, char *path)
{
  char		buf[4096];
  char		buff[4096];
  char		*s;

  bzero(buff, 4096);
  s = my_strcat(path, d->d_name);
  realpath(s, buf);
  read(open(s, O_RDONLY, 0444), buff, 4096);
  stat(s, &info);
  s = strrchr(buf, '/');
  s++;
  write(fd, "name: ", 6);
  write(fd, s, strlen(s));
  if (strlen(s) < 10)
    write(fd, "\t\tbirth: ", 9);
  else
    write(fd, "\tbirth: ", 8);
  if (buff[strlen(buff) - 1] == '\n')
    write(fd, buff, strlen(buff) - 1);
  else
    write(fd, buff, strlen(buff));
  write(fd, "\tat: ", 5);
  my_putnbr(fd, info.st_uid);
  write(fd, "\n", 1);
}

void		genealfs(char *path, int fd)
{
  DIR		*dirp;
  char		buf[4096];
  char		*s;
  struct stat	info;
  struct dirent *d;

  if (!(dirp = opendir(path)))
    exit(fprintf(stderr, "Error opening directory: %s, maybe not a directory\n", path));
  while ((d = readdir(dirp)))
    {
      if (d->d_type == DT_DIR)
	{
	  if (strcmp(d->d_name, ".") && strcmp(d->d_name, ".."))
	    {
	      write(fd, "family: ", 8);
	      write(fd, d->d_name, strlen(d->d_name));
	      write(fd, "\n", 1);
	      realpath(my_strcat(path, my_strcat("/", d->d_name)), buf);
	      s = my_strcat(buf, "/");
	      dprintf(2, "%s\n", s);
	      genealfs(s, fd);
	      write(fd, "______________________________\n", 31);
	    }
	}
      else if (d->d_name[0] != '.' && strcmp(d->d_name, "father")
	       && strcmp(d->d_name, "mother"))
	display(d, info, fd, path);
    }
}
