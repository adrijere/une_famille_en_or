/*
** getterm.c for getterm.c in /home/clementj/rendu/PSU_2013_my_select
** 
** Made by clementjean
** Login   <clementj@epitech.net>
** 
** Started on  Sun Jan 19 13:50:30 2014 clementjean
** Last update Tue Jun 10 09:16:04 2014 edouard vache
*/

#include	"my.h"

char    *my_strcpymod(char *dest, char *src)
{
  int   i;
  int   j;

  i = 0;
  j = 5;
  while (src[j])
    dest[i++] = src[j++];
  dest[i] = '\0';
  return (dest);
}

char    *get_term(char **env)
{
  char  *str;
  int   j;
  int   i;

  i = 0;
  j = 0;
  while (env[j][0] != 'T' || env[j][1] != 'E' || env[j][2] != 'R'
         || env[j][3] != 'M' || env[j][4] != '=')
    j = j + 1;
  if ((str = malloc(sizeof (char) * strlen(env[j]))) == NULL)
    return (0);
  my_strcpymod(str, env[j]);
  i = strlen(env[j]);
  str[i] = '\0';
  return (str);
}
