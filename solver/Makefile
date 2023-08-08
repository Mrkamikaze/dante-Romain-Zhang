##
## EPITECH PROJECT, 2022
## makefile
## File description:
## my_makefile
##

SRC     =	main.c \
		parser/parseur.c \
		solv/solver.c \
		solv/check.c \
		solv/replace.c

OBJ     =	$(SRC:.c=.o)

NAME    =	solver

LINE	=	\n

TEST	=	lib/libmy.a

all:    $(NAME)

.c.o:
	gcc -c $< -I include/ -L lib/ -lmy -o $@

$(NAME):        $(OBJ)
ifeq (,$(wildcard lib/libmy.a))
	cd lib/ && make && cd ../
endif
	gcc -o $(NAME) $(OBJ) -I include/ -L lib/ -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
