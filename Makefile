##
## EPITECH PROJECT, 2023
## Makefile Setting Up
## File description:
## Setting Up
##

SRC_LIB	=	lib/my/my_strlen.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_putchar.c	\
			lib/my/my_strlen.c	\
			lib/my/my_putstr.c	\
			lib/my/mini_printf.c	\
			lib/my/my_strcpy.c	\
			get_number_lines.c	\
			lib/my/my_compute_power_rec.c	\
			lib/my/my_strcat.c	\
			set_tableau.c	\
			set_tableau_fichier.c	\
			set_tableau_generate.c	\
			find_square_and_replace.c	\
			print_array_and_free.c	\

SRC =	main.c	\

OBJ	=	$(SRC_LIB:.c=.o)

CFLAGS_LIB 	=	-I./include/ -Werror -Wall -Wextra

CFLAGS 	=	-I./include/ -L./lib/my/ -lmy -Werror -Wall -Wextra

NAME	=	setting_up

all: libmy.a
	gcc -o $(NAME) $(SRC) $(CFLAGS)

libmy.a:	$(OBJ)
	gcc -c $(SRC_LIB) $(CFLAGS_LIB)
	ar rc lib/my/libmy.a $(OBJ)
	find -name "*.o" -delete

clean:
	rm -f lib/my/libmy.a

fclean: clean
	rm -f $(NAME)

re: fclean all
