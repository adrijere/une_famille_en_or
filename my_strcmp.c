/*
** my_strcmp.c for  in /home/gysc0/rendu/une_famille_en_or
**
** Made by Gysc0
** Login   <gysc0@epitech.net>
**
** Started on  Tue Jun 10 15:00:34 2014 Gysc0
** Last update Tue Jun 10 15:06:58 2014 Gysc0
*/

#include "ufo.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (!s1 || !s2)
    return (-1);
  while (s1[i] != '\0')
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
      i = i + 1;
    }
  if (s1[i] < s2[i])
    return (-1);
  if (s1[i] > s2[i])
    return (1);
  return (0);
}
