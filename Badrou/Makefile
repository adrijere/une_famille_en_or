##
## Makefile for make in /home/mohame_g/rendu/Systeme_unix/une_famille_en_or/Badrou
## 
## Made by mohamedi badr
## Login   <mohame_g@epitech.net>
## 
## Started on  Mon Jun  9 15:42:54 2014 mohamedi badr
## Last update Mon Jun  9 15:44:16 2014 mohamedi badr
##

NAME    =       genealfs

CC      =       gcc

CFLAGS  +=       -W -Wall -Wextra -Werror -g3

RM      =       rm -rf

SRCS    =       pipe.c \

OBJS    =       $(SRCS:.c=.o)

all:    $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
