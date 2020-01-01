NAME = libftprintf.a

FT_PRINTF_SRC = ft_printf.c\
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

LIBFT_PATH = libft/
LIBFT_SRC = ft_bzero.c ft_memalloc.c \
			ft_strlen.c ft_strdup.c ft_strcpy.c ft_strchr.c ft_strcmp.c \
			ft_atoi.c ft_isdigit.c\
			ft_putchar.c ft_itoa.c ft_putstr.c ft_strcontains.c\
			ft_memset.c\
			ft_memcpy.c

OBJ += $(FT_PRINTF_SRC:.c=.o)
OBJ += $(addprefix $(LIBFT_PATH),$(LIBFT_SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
		make fclean -C ./libft/

re: fclean all

.PHONY: all clean fclean re
