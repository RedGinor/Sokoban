##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makesfiles
##

SRC	=	src/main.c			\
		src/grid_gestion.c	\
		src/make_move.c		\
		src/check_win.c		\
		src/check_loose.c

TESTS	=	tests/test_socoban.c	\
			src/grid_gestion.c		\
			src/check_win.c			\
			src/check_loose.c

NAME 	=	my_sokoban

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -W -Iinclude

LIB		=	-L lib -lib -lncurses

all:	$(NAME)

make_lib:
	make -C lib all

$(NAME):	make_lib	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(LIB)

clean:
	make -C lib clean
	rm -f $(OBJ)

fclean:	clean
	make -C lib fclean
	rm -f $(NAME)
	rm -f unit_tests
	rm -f *.gc*

re: 	fclean all

unit_tests:	fclean	make_lib
		gcc $(TESTS) -o unit_tests $(LIB) --coverage -lcriterion -Iinclude

tests_run:	unit_tests
		rm -f *.gc*
		./unit_tests
		gcovr --exclude tests/
		gcovr -b --exclude tests/