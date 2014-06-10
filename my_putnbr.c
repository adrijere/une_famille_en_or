/*
** my_putnbr.c for  in /home/gysc0/rendu/une_famille_en_or
**
** Made by Gysc0
** Login   <gysc0@epitech.net>
**
** Started on  Tue Jun 10 14:59:34 2014 Gysc0
** Last update Tue Jun 10 14:59:37 2014 Gysc0
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
