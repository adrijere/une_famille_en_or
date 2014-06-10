/*
** main.c for  in /home/gysc0/rendu/une_famille_en_or
**
** Made by Zackary Beaugelin
** Login   <gysc0@epitech.net>
**
** Started on  Mon Jun  9 10:16:21 2014 Zackary Beaugelin
** Last update Tue Jun 10 09:11:06 2014 Gysc0
*/

#include "ufo.h"

void		display(struct dirent *d, struct stat info, int fd, char *path)
{
  char		buf[4096];
  char		buff[4096];
  char		*s;

  bzero(buff, 4096);
  s = my_strcat(my_strcat("./", path), my_strcat("/", d->d_name));
  realpath(s, buf);
  read(open(s, O_RDONLY, 0444), buff, 4096);
  stat(s, &info);
  s = strrchr(buf, '/');
  s++;
  write(fd, "name: ", 6);
  write(fd, s, strlen(s));
  write(fd, " birth: ", 8);
  if (buff[strlen(buff) - 1] == '\n')
    write(fd, buff, strlen(buff) - 1);
  else
    write(fd, buff, strlen(buff));
  write(fd, " at: ", 5);
  my_putnbr(fd, info.st_uid);
  write(fd, "\n", 1);
}

void		genealfs(char *path, int fd)
{
  DIR		*dirp;
  struct stat	info;
  struct dirent *d;

  stat(path, &info);
  if (S_ISDIR(info.st_mode))
    {
      if (!(dirp = opendir(path)))
	exit(fprintf(stderr, "Error opening directory, maybe not a directory\n"));
      if (!(d = readdir(dirp)))
	exit(fprintf(stderr, "Error reading directory\n"));
      while ((d = readdir(dirp)))
	{
	  if (d == NULL)
	    exit(0);
	  if (d->d_name[0] != '.')
	    display(d, info, fd, path);
	}
    }
}

int	main(int ac, char **av)
{
  int	fd;

  fd = 1;
  if (ac < 2)
    exit(fprintf(stderr, "./genealfs famille [-f file | -p cmd]\n"));
  else if (ac == 2 || !strcmp("-f", av[2]))
    {
      if (av[2] && (!strcmp("-f", av[2]) && av[3]))
	genealfs(av[1], (fd = open(av[3], O_RDWR | O_CREAT, 0666)));
      else
	genealfs(av[1], fd);
    }
  if (fd != 1)
    close(fd);
  return (0);
}
