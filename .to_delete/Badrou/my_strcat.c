/*
** my_strcat.c for genealfs in /home/jussea_m/epitech/generalfs/une_famille_en_or/Badrou
** 
** Made by jussea_m@epitech.eu
** Login   <jussea_m@epitech.net>
** 
** Started on  Tue Jun 10 14:13:53 2014 jussea_m@epitech.eu
** Last update Tue Jun 10 14:14:03 2014 jussea_m@epitech.eu
*/

#include "ufo.h"

int	my_strlen(char *str)
{
  int	k;

  k = 0;
  if (str == NULL)
    return (0);
  else
    while (str[k])
      k++;
  return (k);
}

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	k;
  int	lenght;
  char	*ret;

  i  = 0;
  k = my_strlen(str1);
  lenght = my_strlen(str2) + k;
  ret = xmalloc(sizeof(char) * lenght + 1);
  while (i != k)
    {
      ret[i] = str1[i];
      i += 1;
    }
  i = 0;
  while ((k + i) != lenght)
    {
      ret[k + i] = str2[i];
      i += 1;
    }
  ret[k + i] = '\0';
  return (ret);
}
