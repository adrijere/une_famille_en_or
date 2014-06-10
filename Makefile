##
## Makefile for  in /home/gysc0/rendu/une_famille_en_or
##
## Made by Zackary Beaugelin
## Login   <gysc0@epitech.net>
##
## Started on  Mon Jun  9 10:14:36 2014 Zackary Beaugelin
## Last update Tue Jun 10 16:32:49 2014 Gysc0
##

NAME	=	genealfs

CC	=	gcc

CFLAGS	+=	 -W -Wall -Wextra -Werror -g3

RM	=	rm -rf

SRCS	=	main.c \
		my_strcat.c \
		my_strncmp.c \
		pipe.c \
		xmalloc.c \
		my_putnbr.c

OBJS	=	$(SRCS:.c=.o)

all:	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
