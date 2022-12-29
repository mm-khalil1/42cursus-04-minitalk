# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 20:03:13 by mkhalil           #+#    #+#              #
#    Updated: 2022/12/29 13:16:28 by mkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client

SRCSV = server.c
SRCCL = client.c

OBJSV = $(SRCSV:.c=.o)
OBJCL = $(SRCCL:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
		make -C libft
		make start

start: $(SERVER) $(CLIENT)

$(SERVER): $(OBJSV)
		$(CC) $(CFLAGS) $(OBJSV) libft/libft.a -o $(SERVER)

$(CLIENT): $(OBJCL)
		$(CC) $(CFLAGS) $(OBJCL) libft/libft.a -o $(CLIENT)

clean:	
	rm -f $(OBJSV) $(OBJCL)
	make clean -C libft
	
fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make fclean -C libft
	
re: fclean all
