##
## EPITECH PROJECT, 2018
## Makefile_lib
## File description:
## Makefile wich will compile the lib
##

SRC	=	my_strdup.c		\
		my_strlen.c		\
		my_strcmp.c		\
		atoi.c			\
		cut_string.c		\
		my_str_to_wordtab.c	\
		my_itoa.c		\
		my_strcat.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)
	rm -f libmy.a

re:	fclean all

.PHONY: all clean fclean re
