
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc

SRCS =	ft_printf.c ft_putchar.c ft_puthex.c  ft_putnbr.c \
		ft_putstr.c ft_uputnbr.c ft_puthexp.c

OBJ = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)
	
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean