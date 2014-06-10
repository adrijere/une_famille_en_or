/*
** xmalloc.c for  in /home/gysc0/rendu/une_famille_en_or
**
** Made by Gysc0
** Login   <gysc0@epitech.net>
**
** Started on  Tue Jun 10 15:05:55 2014 Gysc0
** Last update Tue Jun 10 15:06:00 2014 Gysc0
*/

#include "ufo.h"

void    *xmalloc(int size)
{
  void  *temp;

  if ((temp = malloc(size)) == NULL)
    exit (-1);
  return (temp);
}
