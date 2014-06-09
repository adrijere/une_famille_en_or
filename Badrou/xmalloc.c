/*
** xmalloc.c for xmalloc in /home/mohame_g/rendu/Systeme_unix/une_famille_en_or/Badrou
** 
** Made by mohamedi badr
** Login   <mohame_g@epitech.net>
** 
** Started on  Mon Jun  9 16:47:29 2014 mohamedi badr
** Last update Mon Jun  9 17:32:46 2014 mohamedi badr
*/

void    *xmalloc(int size)
{
  void  *temp;

  if ((temp = malloc(size)) == NULL)
    exit (-1);
  return (temp);
}
