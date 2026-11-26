CC = cc
SRC = ft_printf.c ft_hellper.c ft_printf_char.c ft_printf_num.c ft_printf_hex.c ft_printf_voidp.c
NAME = libftprintf.a
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re