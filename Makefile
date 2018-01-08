# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zweng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 18:11:43 by zweng             #+#    #+#              #
#    Updated: 2018/01/08 18:25:01 by zweng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = zweng.filler

LIBDIR = libft

LIB = libft.a

SRCS = filler.c fl_get.c fl_resolve.c fl_hotmap.c fl_get_piece.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

LIBSRCS = $(wildcard libft/*.c)

LIBOBJS = $(patsubst %.c, %.o, $(LIBSRCS))

HEADER_DIR = libft

CFLAGS = -Wall -Wextra -Werror

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
#  # ==================

all: $(NAME)

$(NAME): $(LIBDIR)/$(LIB) $(OBJS)
	@$(CC) $(OBJS) -L$(LIBDIR)/ -lft -o $@
	@echo $(GREEN)"Finish linking"$(EOC)

$(LIBDIR)/$(LIB): $(LIBSRCS)
	@make -C $(LIBDIR)/ fclean && make -C $(LIBDIR)/

%.o: %.c
	@echo $(GREEN)"Compiling"$(EOC)
	@$(CC) -c $(CFLAGS) $^ -I. -I$(HEADER_DIR) -o $@
	@echo $(GREEN)"Finish compiling"$(EOC)

clean:
	@/bin/rm -f $(OBJS) 
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME) $(OBJS) $(LIB)
	@make -C libft/ fclean

re: fclean all

.PHONY:clean fclean all
