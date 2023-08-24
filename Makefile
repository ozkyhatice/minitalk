NAME		=	minitalk
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f
CLIENT		=	client
SERVER		=	server
CLIENT_C	=	client.c
SERVER_C	=	server.c

all:		$(NAME)

$(NAME):	$(SERVER) $(CLIENT)

$(SERVER):	$(SERVER_C)
			gcc $(CFLAGS) $(SERVER_C) -o $(SERVER) 

$(CLIENT):	$(CLIENT_C)
			gcc $(CFLAGS) $(CLIENT_C) -o $(CLIENT) 

clean:
			rm -rf $(CLIENT) $(SERVER)

fclean:		clean

re:			fclean all

.PHONY: 	all clean fclean re