/*
** my_put_nbr.c for my_put_nbr.c in /home/beauge_z/Documents/Piscine/Piscine-C-Jour_03
**
** Made by Zackary Beaugelin
** Login   <beauge_z@epitech.net>
**
** Started on  Wed Oct  2 13:42:14 2013 Zackary Beaugelin
** Last update Mon Jun  9 12:04:16 2014 Zackary Beaugelin
*/

#include "ufo.h"

void	my_putchar(int fd, char c)
{
  write(fd, &c, 1);
}

void	my_putnbr(int fd, int nb)
{
  int	neg;

  neg = 0;
  if (nb < 0)
    {
      my_putchar(fd, '-');
      if (nb == -2147483648)
	{
	  neg = -1;
	  nb = nb + 1;
	}
      nb = nb * -1;
    }
  if (nb >= 10)
    my_putnbr(fd, nb /10);
  if (neg == -1)
    {
      neg = 0;
      my_putchar(fd, nb % 10 + '1');
      }
  else
    my_putchar(fd, nb % 10 + '0');
}
