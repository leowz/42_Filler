# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zweng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 18:11:43 by zweng             #+#    #+#              #
#    Updated: 2018/01/05 16:30:59 by zweng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

SRCS = ft_memset.c \
		 ft_bzero.c \
		 ft_memcpy.c \
		 ft_memccpy.c \
		 ft_memmove.c \
		 ft_memchr.c \
		 ft_memcmp.c \
		 ft_strlen.c \
		 ft_strdup.c \
		 ft_strcpy.c \
		 ft_strncpy.c \
		 ft_strcat.c \
		 ft_strncat.c \
		 ft_strlcat.c \
		 ft_strchr.c \
		 ft_strrchr.c \
		 ft_strstr.c \
		 ft_strnstr.c \
		 ft_strcmp.c \
		 ft_strncmp.c \
		 ft_strrev.c \
		 ft_atoi.c \
		 ft_isalpha.c \
		 ft_isdigit.c \
		 ft_isalnum.c \
		 ft_isascii.c \
		 ft_isprint.c \
		 ft_toupper.c \
		 ft_tolower.c \
		 ft_memalloc.c \
		 ft_memdel.c \
		 ft_strnew.c \
		 ft_strdel.c \
		 ft_strclr.c \
		 ft_striter.c \
		 ft_striteri.c \
		 ft_strmap.c \
		 ft_strmapi.c \
		 ft_strequ.c\
		 ft_strnequ.c \
		 ft_strsub.c \
		 ft_strjoin.c \
		 ft_strtrim.c \
		 ft_strsplit.c \
		 ft_itoa.c \
		 ft_itoa_base.c \
		 ft_putchar.c \
		 ft_putstr.c \
		 ft_putendl.c \
		 ft_putnbr.c \
		 ft_putchar_fd.c \
		 ft_putstr_fd.c \
		 ft_putendl_fd.c \
		 ft_putnbr_fd.c \
		 ft_strlastchrp.c \
		 ft_lstnew.c \
		 ft_lstdelone.c \
		 ft_lstdel.c \
		 ft_lstadd.c \
		 ft_lstiter.c \
		 ft_lstmap.c \
		 ft_lstappend.c \
		 ft_lstprint.c \
		 get_next_line.c \

OBJS = $(SRCS:%.c=%.o)

HEADER_DIR = .

CFLAGS = -c -Wall -Wextra -Werror
# === Colors ===
# usage "$(WHITE) Hello $(END)"
WHITE="\033[1;37m"
RED="\033[1;31m"
GREEN="\033[1;32m"
BLACK="\033[1;30m"
END="\033[0;0m"
# # ==============

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS) 
	@ranlib $(NAME)
	@echo $(GREEN)"libft finish"$(END)

%.o:%.c
	@$(CC) $(CFLAGS) $^ -I$(HEADER_DIR) -o $@

clean:
	@/bin/rm -f $(OBJS)
	@echo $(GREEN)"libft clean"$(END)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo $(GREEN)"libft fclean"$(END)

re: fclean all
