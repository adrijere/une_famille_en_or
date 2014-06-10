/*
** my_strncmp.c for  in /home/gysc0/rendu/une_famille_en_or
** 
** Made by Gysc0
** Login   <gysc0@epitech.net>
** 
** Started on  Tue Jun 10 16:38:53 2014 Gysc0
** Last update Tue Jun 10 16:39:03 2014 Gysc0
*/

#include "ufo.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  if (!s1 || !s2)
    return (-1);
  while (n > 0)
    {
      if (*s1 != *s2)
	return ((*s1 < *s2) ? -1 : 1);
      else if (*s1 == '\0')
	return 0;
      s1++;
      s2++;
      --n;
    }
  return (0);
}
