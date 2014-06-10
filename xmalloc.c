/*
** xmalloc.c for xmalloc in /home/mohame_g/rendu/Systeme_unix/une_famille_en_or/Badrou
** 
** Made by mohamedi badr
** Login   <mohame_g@epitech.net>
** 
** Started on  Mon Jun  9 16:47:29 2014 mohamedi badr
** Last update Tue Jun 10 11:02:06 2014 jussea_m@epitech.eu
*/

#include "ufo.h"

void    *xmalloc(int size)
{
  void  *temp;

  if ((temp = malloc(size)) == NULL)
    exit (-1);
  return (temp);
}
