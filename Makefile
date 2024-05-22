CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc
NAME = minitalk
LIBPRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
HEADER = minitalk.h
all: $(NAME)

$(NAME): start client server 
	@echo "All Good"

bonus: start server_bonus client_bonus
	

start:
	@cd ./ft_printf && make
	@cd ./libft && make


client: client.c $(LIBFT) $(LIBPRINTF) $(HEADER)
	@echo "Client ready"
	@$(CC) $(CFLAGS) client.c $(LIBFT) $(LIBPRINTF) -o client

server: server.c $(LIBPRINTF) $(HEADER)
	@echo "Server ready"
	@$(CC) $(CFLAGS) server.c $(LIBPRINTF) -o server


client_bonus: client_bonus.c $(LIBFT) $(LIBPRINTF) $(HEADER)
	@echo "Client_bonus ready"
	@$(CC) $(CFLAGS) client_bonus.c $(LIBFT) $(LIBPRINTF) -o client_bonus

server_bonus: server_bonus.c $(LIBPRINTF) $(HEADER)
	@echo "Server_bonus ready"
	@$(CC) $(CFLAGS) server_bonus.c $(LIBPRINTF) -o server_bonus

clean:
	@cd ./ft_printf && make clean
	@cd ./libft && make clean
	@echo "Objects Cleaned"

fclean: clean
	@$(RM) client server client_bonus server_bonus
	@cd ./ft_printf && make fclean
	@cd ./libft && make fclean
	@echo "All cleaned" 

re: fclean all

bre: fclean bonus

.PHONY: clean start
