##
## Makefile for make in /home/mohame_g/rendu/Systeme_unix/une_famille_en_or/Badrou
## 
## Made by mohamedi badr
## Login   <mohame_g@epitech.net>
## 
## Started on  Mon Jun  9 15:42:54 2014 mohamedi badr
## Last update Tue Jun 10 10:36:42 2014 jussea_m@epitech.eu
##

NAME    =       genealfs

CC      =       gcc

CFLAGS  +=       -W -Wall -Wextra -Werror -g3

RM      =       rm -rf

SRCS    =       pipe.c \
		my_epur_str.c \
		my_parse_tab.c \
		my_putnbr.c \
		xmalloc.c \

OBJS    =       $(SRCS:.c=.o)

all:    $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
