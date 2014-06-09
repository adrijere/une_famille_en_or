/*
** main.c for  in /home/gysc0/rendu/une_famille_en_or
**
** Made by Zackary Beaugelin
** Login   <gysc0@epitech.net>
**
** Started on  Mon Jun  9 10:16:21 2014 Zackary Beaugelin
** Last update Mon Jun  9 15:01:32 2014 Gysc0
*/

#include "ufo.h"

void		genealfs(char *path, int fd)
{
  char		buff[4096];
  DIR		*dirp;
  struct dirent *d;
  struct stat	info;
  struct passwd	*pw;

  if (!access(path, F_OK))
    if (!(dirp = opendir(path))
	exit(fprintf(stderr, "Error opening directory, maybe not a directory\n"));
  if (!(d = readdir(dirp)))
    exit(fprintf(stderr, "Error reading directory\n"));
  while ((d = readdir(dirp)))
    {
      bzero(buff, 4096);
      if (d == NULL)
	exit(0);
      if (d->d_name[0] != '.')
	{
	  read(open(d->d_name, O_RDONLY, 0444), buff, 4096);
	  stat(d->d_name, &info);
	  pw = getpwuid(info.st_uid);
	  write(fd, "name: ", 6);
	  write(fd, d->d_name, strlen(d->d_name));
	  write(fd, " birth: ", 7);
	  if (buff[strlen(buff) - 1] == '\n')
	    write(fd, buff, strlen(buff) - 1);
	  else
	    write(fd, buff, strlen(buff) - 1);
	  write(fd, " at: ", 5);
	  my_putnbr(fd, pw->pw_uid);
	  write(fd, "\n", 1);
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
