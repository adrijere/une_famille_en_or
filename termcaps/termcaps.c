/*
** termacaps.c for termacaps in /home/lennuy_f/rendu/une_famille_en_or/une_famille_en_or/termcaps
** 
** Made by lennuy_f
** Login   <lennuy_f@epitech.net>
** 
** Started on  Mon Jun  9 13:57:48 2014 lennuy_f
** Last update Tue Jun 10 14:57:23 2014 lennuy_f
*/

#include "my.h"

void            afflistsel(t_list *newlist)
{
  t_listel      *elem;

  elem = newlist->racine;
  while (elem != NULL)
    {
      my_putstr(elem->data);
      my_putchar('\n');
      elem = elem->next;
    }
}

t_list          *pushback(t_list *list, char *str, int x)
{
  t_listel      *elem;

  if (list != NULL)
    {
      if ((elem = malloc(sizeof(*elem))) == NULL)
        return (NULL);
      if (elem != NULL)
        {
          elem->data = str;
	  elem->pos = x;
          elem->next = NULL;
          if (list->end == NULL)
            {
              elem->prev = NULL;
              list->racine = elem;
              list->end = elem;
            }
          else
            {
              list->end->next = elem;
              elem->prev = list->end;
              list->end = elem;
            }
        }
    }
  return (list);
}

t_list          *initialisation()
{
  t_list        *newlist;

  if ((newlist = malloc(sizeof(*newlist))) == NULL)
    return (NULL);
  if (newlist != NULL)
    {
      newlist->size = 0;
      newlist->racine = NULL;
      newlist->end = NULL;
    }
  return (newlist);
}

int		open_file(t_list *list, char *str2)
{
  t_listel	*elem;
  DIR		*rep;
  struct dirent	*file;
  char		*str;
  int		pos;

  pos = 1;
  file = NULL;
  rep = opendir(str2);
  if (rep == NULL)
    return (-1);
  while ((file = readdir(rep)))
    {
      if (strcmp(file->d_name, "..") != 0 && strcmp(file->d_name, ".") != 0)
	pushback(list, file->d_name, pos);
      pos = pos + 1;
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_list	*newlist;
  t_listel	*elem;
  struct termios        term;

  tcgetattr(0, &term);
  term.c_lflag &= ~ECHO;
  term.c_lflag &= ~ICANON;
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &term);
  my_clean();
  newlist = initialisation();
  open_file(newlist, "./");
  afflistsel(newlist);
  fleches(term, newlist, elem);
  return (0);
}
