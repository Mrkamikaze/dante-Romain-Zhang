##
## EPITECH PROJECT, 2022
## makefile
## File description:
## my_makefile
##

SRC_MY	=	my/functions.c \
		my/my_compute_square_root.c \
		my/my_revstr.c \
		my/my_strcapitalize.c \
		my/my_strcpy.c \
		my/my_str_islower.c \
		my/my_strlowcase.c \
		my/my_strncpy.c \
		my/my_strupcase.c \
		my/functions_2.c \
		my/my_find_prime_sup.c \
		my/my_is_prime.c \
		my/my_show_word_array.c \
		my/my_strcat.c \
		my/my_strdup.c \
		my/my_str_isnum.c \
		my/my_strncat.c \
		my/my_strstr.c \
		my/functions_3.c \
		my/my_compute_factorial_rec.c \
		my/my_getnbr.c \
		my/my_put_nbr.c \
		my/my_sort_int_array.c \
		my/my_strcmp.c \
		my/my_str_isalpha.c \
		my/my_str_isupper.c \
		my/my_strncmp.c \
		my/my_str_to_word_array.c \
		my/is_digits.c \
		my/is_int.c \
		my/is_length.c \
		my/my_str_to_int.c

SRC_STR	=	strings/append.c \
		strings/calc.c \
		strings/conversion.c \
		strings/string.c \
		strings/index.c

OBJ_MY	=	$(SRC_MY:.c=.o)

OBJ_STR	=	$(SRC_STR:.c=.o)

NAME	=	libmy.a

.c.o:
	gcc -c $< -o $@

clean:	move
	rm $(OBJ_MY) $(OBJ_STR)
	cp my/my.h ../include/my.h
	cp strings/strings.h ../include/strings.h

move:	createlib

createlib :	createc
	ar rc $(NAME) $(OBJ_MY) $(OBJ_STR)

createc:	$(OBJ_MY) $(OBJ_STR)
	ar rc $(NAME) $(OBJ_MY) $(OBJ_STR)
