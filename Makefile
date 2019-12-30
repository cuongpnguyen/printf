NAME = test

SRC = main.c\
	  ft_printf.c\
		init.c\
		token.c\
		print.c\
		print_aux.c\
		strings.c\
		integer.c\
		unsigned_integer.c\
		solve.c\
		malloc_integer.c\
		octal.c\
		hex.c\
		hash.c\
		float.c\
		float_aux.c\
		write.c\
		pointer.c
OBJ = $(SRC:.c=.o)

INC = -I includes

LIBFT =	libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC) -g

$(LIBFT):
		make -C ./libft/

clean:
		rm -f $(OBJ)
			make clean -C ./libft/

fclean: clean
		rm -f $(NAME)
		rm -f libft.a
			make fclean -C ./libft/

re: fclean all

