##
## EPITECH PROJECT, 2023
## Makefiles
## File description:
## minishell 1
##

SRC	=	src/main.c	\
		src/my_str_to_lines.c	\
		src/cmd_send_read.c	\
		src/loop.c	\
		src/direction.c

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

PATH_TO_PIPES	=	pipes.sh

CFLAGS	=	-W -Wall -Wextra

CPPFLAGS = 	-I./includes

TESTS_LIBS	=	--coverage -lcriterion

TESTS_NAME	=	unit_tests

TESTS_SRC	=	tests/main.c	\
			tests/tests.c	\
			my_str_to_lines.c

CC	=	gcc

all: $(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)

$(LIBMY):
		make -C lib

debug:	CFLAGS += -g3
debug:	$(NAME)

tests:	$(TESTS_NAME)

$(TESTS_NAME):	$(TESTS_SRC)
		$(CC) -o $(TESTS_NAME) $(TESTS_SRC) $(TESTS_LIBS) $(LDFLAGS) $(LDLIBS)

clean:
		rm -f $(OBJ)
		find . -name "*~" -delete
		find . -name "#*#" -delete
		find . -name "*.o" -delete
		find . -name "vgcore.*" -delete

fclean:		clean
		rm -f $(NAME)

re:		fclean all

run:	all
		./$(PATH_TO_PIPES)

.PHONY: all clean fclean re tests debug run
