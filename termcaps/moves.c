/*
** moves.c for moves in /home/e_edouard/rendu/unix_rattrap/une_famille_en_or/termcaps
** 
** Made by edouard vache
** Login   <e_edouard@epitech.net>
** 
** Started on  Tue Jun 10 09:12:50 2014 edouard vache
** Last update Tue Jun 10 15:22:45 2014 lennuy_f
*/

#include "my.h"

int             my_underliners()
{
  char          *res;
  extern char   **environ;

  if (tgetent(NULL, get_term(environ)) == 0)
    {
      my_putstr("problem terminal");
      return (2);
    }
  if ((res = tgetstr("us", NULL)) == NULL)
    {
      my_putstr("bad termcaps");
      return (1);
    }
  tputs(res, 1, my_outc);
  return (0);
}

int             my_underlinere()
{
  char          *res;
  extern char   **environ;

  if (tgetent(NULL, get_term(environ)) == 0)
    {
      my_putstr("problem terminal");
      return (2);
    }
  if ((res = tgetstr("ue", NULL)) == NULL)
    {
      my_putstr("bad termcaps");
      return (1);
    }
  tputs(res, 1, my_outc);
  return (0);
}

void            listprint(t_list *list, t_listel *elem)
{
  t_listel      *new_elem;

  new_elem = list->racine;
  while (new_elem != NULL)
    {
      if (new_elem->pos == elem->pos)
        {
          my_underliners();
          my_putstr(new_elem->data);
	  my_putchar('\n');
	  my_underlinere();
          new_elem = new_elem->next;
        }
      else
        {
	  my_putstr(new_elem->data);
          my_putchar('\n');
	  new_elem = new_elem->next;
        }
    }
}

void    cleanprint(t_list *newlist, t_listel *elem)
{
  my_clean();
  listprint(newlist, elem);
}

int     fleches(struct termios term, t_list *newlist, t_listel *elem)
{
  char  *buffer;

  elem = newlist->racine;
  buffer = malloc(sizeof(char) * 4096);
  while (1)
    {
      bzero(buffer, sizeof(buffer));
      read(0, buffer, 3);
      printf("%d, %d, %d\n", buffer[0], buffer[1], buffer[2]); 
      newlist = enter(buffer, elem, newlist);
      if (buffer[0] == 27 && strlen(buffer) <= 2)
        {
          term.c_lflag = (ICANON | ECHO);
          tcsetattr(0, 0, &term);
          return (0);
        }
      else if (buffer[0] == 27 && buffer[2] == 68 && elem->prev)
        {
          elem = elem->prev;
          cleanprint(newlist, elem);
        }
      else if (buffer[0] == 27 && buffer[2] == 67 && elem->next)
        {
          elem = elem->next;
          cleanprint(newlist, elem);
        }
    }
  return (0);
}
