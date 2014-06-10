/*
** caps.c for caps in /home/e_edouard/rendu/unix_rattrap/une_famille_en_or/termcaps
** 
** Made by edouard vache
** Login   <e_edouard@epitech.net>
** 
** Started on  Mon Jun  9 20:29:08 2014 edouard vache
** Last update Tue Jun 10 09:24:57 2014 edouard vache
*/

#include "my.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

int     my_outc(int c)
{
  my_putchar(c);
  return (0);
}

int             my_clean()
{
  char          *res;
  extern char   **environ;

  if (tgetent(NULL, get_term(environ)) == 0)
    {
      puts("problem terminal");
      return (2);
    }
  if ((res = tgetstr("cl", NULL)) == NULL)
    {
      puts("bad termcaps");
      return (1);
    }
  tputs(tgoto(res, 0, 0), 1, my_outc);
  return (0);
}

t_list		*enter(char *buffer, t_listel *elem, t_list *new_list)
{
  DIR		*rep;
  struct dirent	*file;
  char		*str;
  int		fd;
  t_list	*new_liste;

  str = malloc(sizeof(char) * 4096);
  if (buffer[0] == 10)
    {
      file == NULL;
      rep = opendir(elem->data);
      if (rep == NULL)
	{
	 fd =  open(elem->data, O_RDONLY);
	 read(fd, str, 4096);
	 printf("%s\n", str);
	 close(fd);
	}
      else
	{
	  new_liste = initialisation();
	  open_file(new_liste, elem->data);
	  my_clean();
	  afflistsel(new_liste);
	  return (new_liste);
	}
    }
  return (new_list);
}
