/*
** my_strcmp.c for genealfs in /home/jussea_m/epitech/generalfs/une_famille_en_or/Badrou
** 
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
** 
** Started on  Tue Jun 10 10:50:21 2014 jussea_m@epitech.eu
** Last update Tue Jun 10 10:50:39 2014 jussea_m@epitech.eu
*/

#include "ufo.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1[i] != s2[i])
    return (-1);
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      i++;
      if (s1[i] != s2[i])
	return (-1);
    }
  return (0);
}
