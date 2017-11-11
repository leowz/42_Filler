# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zweng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 18:11:43 by zweng             #+#    #+#              #
#    Updated: 2017/11/09 18:30:41 by zweng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRC = ft_*.c

HEADER_DIR = ./ 

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	
	$(CC) $(CFLAGS) $(SRC) #-I$(HEADER_DIR)
	ar rc $(NAME) ft_*.o 
	ranlib $(NAME)

clean:
	/bin/rm -f ft_*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
