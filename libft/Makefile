NAME=libft.a

.PHONY: all clean fclean re

CFLAGS := -Wall -Werror -Wextra

SRCS = ft_bzero.c ft_memalloc.c\
			ft_strlen.c ft_strdup.c ft_strcpy.c ft_strchr.c ft_strcmp.c \
			ft_atoi.c ft_isdigit.c\
			ft_putchar.c ft_itoa.c ft_putstr.c ft_strcontains.c\
			ft_memset.c\
			ft_memcpy.c

OBJ = $(SRCS:.c=.o)

INCLUDES=./

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(CFLAGS) -c $(SRCS) -I$(INCLUDES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
