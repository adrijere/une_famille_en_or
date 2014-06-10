/*
** my.h for my in /home/e_edouard/rendu/unix_rattrap/une_famille_en_or/termcaps
** 
** Made by edouard vache
** Login   <e_edouard@epitech.net>
** 
** Started on  Mon Jun  9 20:05:34 2014 edouard vache
** Last update Tue Jun 10 20:30:32 2014 edouard vache
*/

#ifndef _MY_H_
#define _MY_H_

#include <stdio.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <curses.h>
#include <term.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <dirent.h>
#include <fcntl.h>

typedef struct          s_listel
{
  char			*data;
  int			select;
  int			pos;
  struct s_listel	*prev;
  struct s_listel	*next;
}                       t_listel;

typedef struct  s_list
{
  int		size;
  t_listel	*racine;
  t_listel	*end;
}               t_list;

int		fleches(struct termios term, t_list **newlist, t_listel *elem);
int		my_clean();
char		*get_term(char **env);
t_list		*enter(char *buffer, t_listel *elem, t_list **new_list);
int		open_file(t_list *list, char *str2);
t_list		*initialisation();
int		my_outc(int c);
void		my_putchar(char c);
void		my_putstr(char *str);
void            afflistsel(t_list *newlist);
void		*xmalloc(int size);

#endif
