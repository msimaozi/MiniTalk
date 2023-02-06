CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(LIBFT):
		$(MAKE) -C ./libft

$(SERVER):	$(OBJ_SERVER) $(LIBFT)
		$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) -o server

$(CLIENT):	$(OBJ_CLIENT) $(LIBFT)
		$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) -o client

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(SERVER) $(CLIENT)

re:	fclean	all