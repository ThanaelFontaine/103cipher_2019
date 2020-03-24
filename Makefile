##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile for 103cipher
##

CC		=		gcc

SRC		=		src/main.c			\
				src/cipher.c	\

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-g3				\
				-I./include		\
				-lm				\
				# -W				\
				# -Wall			\
				#-Wextra			\

NAME	=		103cipher

all:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all