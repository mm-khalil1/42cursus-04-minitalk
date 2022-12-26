# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 20:03:13 by mkhalil           #+#    #+#              #
#    Updated: 2022/12/26 21:39:01 by mkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 
SERVER = server
CLIENT = client

SRCSV = server.c
SRCCL = client.c

OBJSV = $(SRCSV:.c=.o)
OBJCL = $(SRCCL:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

start:
		make -C libft
		cp libft/libft.a .
		make all

all: $(SERVER) $(CLIENT)

$(NAME): start

$(SERVER): 
		$(CC) $(CFLAGS) $(SRCSV) libft.a -o $(SERVER)

$(CLIENT): 
		$(CC) $(CFLAGS) $(SRCCL) libft.a -o $(CLIENT)

clean:	
	rm -f $(OBJSV) $(OBJCL)
	make clean -C libft
	
fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make fclean -C libft
	
re: fclean all