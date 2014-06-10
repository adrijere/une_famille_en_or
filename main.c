/*
** main.c for  in /home/gysc0/rendu/une_famille_en_or
**
** Made by Zackary Beaugelin
** Login   <gysc0@epitech.net>
**
** Started on  Mon Jun  9 10:16:21 2014 Zackary Beaugelin
** Last update Tue Jun 10 15:05:06 2014 Gysc0
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
  write(fd, s, my_strlen(s));
  if (my_strlen(s) < 10)
    write(fd, "\t\tbirth: ", 9);
  else
    write(fd, "\tbirth: ", 8);
  if (buff[my_strlen(buff) - 1] == '\n')
    write(fd, buff, my_strlen(buff) - 1);
  else
    write(fd, buff, my_strlen(buff));
  write(fd, "\tat: ", 5);
  my_putnbr(fd, info.st_uid);
  write(fd, "\n", 1);
}

int		genealfs(char *path, int fd, int ret)
{
  DIR		*dirp;
  char		buf[4096];
  char		*s;
  struct stat	info;
  struct dirent *d;

  if (!(dirp = opendir(path)))
    return (write(2, "Error opening directory, maybe not a directory\n", 47));
  while ((d = readdir(dirp)))
    {
      if (d->d_type == DT_DIR)
	{
	  if (my_strcmp(d->d_name, ".") && my_strcmp(d->d_name, "..") && !ret)
	    {
	      realpath(my_strcat(path, my_strcat("/", d->d_name)), buf);
	      s = my_strcat(buf, "/");
	      ret = genealfs(s, fd, ret);
	      write(fd, "______________________________\n", 31);
	    }
	}
      else if (!ret && d->d_name[0] != '.' && my_strcmp(d->d_name, "father")
	       && my_strcmp(d->d_name, "mother"))
	display(d, info, fd, path);
    }
  return (ret);
}

int	main(int ac, char **av)
{
  int	fd;
  int	ret;

  fd = 1;
  ret = 0;
  if (ac < 2)
    {
      write(2, "./genealfs famille [-f file | -p cmd]\n", 38);
      return (-1);
    }
  else if (ac == 2 || !my_strcmp("-f", av[2]))
    {
      if (av[2] && (!my_strcmp("-f", av[2]) && av[3]))
	ret = genealfs(av[1], (fd = open(av[3], O_RDWR | O_CREAT, 0666)), 0);
      else
	ret = genealfs(av[1], fd, 0);
    }
  if (fd != 1)
    close(fd);
  if (ret)
    return (-1);
  return (ret);
}
