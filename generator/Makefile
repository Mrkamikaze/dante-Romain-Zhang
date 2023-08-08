##
## EPITECH PROJECT, 2022
## makefile
## File description:
## my_makefile
##

SRC     =       main.c                          \
                display_word_array.c            \
                maze_generator.c		\
		maze_perfect_generator.c

OBJ     =	$(SRC:.c=.o)

NAME    =	generator

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
