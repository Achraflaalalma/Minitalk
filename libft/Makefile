
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc

SRCS =  ft_atoi.c ft_digit.c
		
OBJ = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)
	

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean
