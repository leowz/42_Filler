# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zweng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 18:11:43 by zweng             #+#    #+#              #
#    Updated: 2018/03/13 17:06:25 by zweng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

# ----- part to change -----

NAME 			= libft.a

HEADER_PATH 	= includes
H_STD 			= $(HEADER_PATH)/libft.h
H_PRINTF		= $(HEADER_PATH)/ft_printf.h
H_ARRAY			= $(HEADER_PATH)/ft_array.h

SRC_PATH 		= srcs
STD_PATH 		= $(SRC_PATH)/ft_stdlib
PRINTF_PATH 	= $(SRC_PATH)/ft_printf
ARRAY_PATH 		= $(SRC_PATH)/ft_array

SRC_NAME_STD 	=\
			ft_memset.c \
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
			ft_lstsize.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstappend.c \
			ft_lstprint.c \
			ft_abs.c \
			get_next_line.c \

SRC_NAME_PRINTF = \
			ft_convert.c \
		 	ft_convert_util.c \
		 	ft_printf.c \
		 	ft_rpstr.c \
			ft_rpstr_format.c \
			ft_rpstr_util.c \
			ft_rpstr_util2.c \
			ft_vdprintf.c \
		 	ft_wchar.c \

SRC_NAME_ARR=\
			ft_arrnew.c\
		 	ft_arritem_at.c\
			ft_arr_realloc.c\
			ft_arrappend.c\
			ft_arrinsert.c\
			ft_arrremove_at.c\
			ft_arrsub.c\
			ft_arrswap.c\
			ft_arritem_new.c\
			ft_arrdel.c\
			ft_arritem_del.c\
			ft_arrstack.c\
			ft_arrqueue.c\
			ft_arrqsort.c\
			ft_arrmsort.c\

CPPFLAGS = -I$(HEADER_PATH) 
CFLAGS = -Wall -Wextra -Werror

# ----- part automatic -----
SRCS := $(addprefix $(STD_PATH)/,$(SRC_NAME_STD))\
		$(addprefix $(ARRAY_PATH)/,$(SRC_NAME_ARR))\
		$(addprefix $(PRINTF_PATH)/,$(SRC_NAME_PRINTF))
OBJS := $(SRCS:.c=.o)

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
#  # ==================

# ----- part rules -----

all: $(NAME)

$(NAME): $(OBJS) 
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf $(GREEN)"\r\E[K$(NAME) finish\n"$(END)

$(STD_PATH)/%.o: $(STD_PATH)/%.c $(H_STD)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf $(GREEN)"\r\E[Kcompiling %s"$(GREEN) $<

$(ARRAY_PATH)/%.o: $(ARRAY_PATH)/%.c $(H_STD) $(H_ARRAY)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf $(GREEN)"\r\E[Kcompiling %s"$(GREEN) $<

$(PRINTF_PATH)/%.o: $(PRINTF_PATH)/%.c $(H_STD) $(H_PRINTF)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf $(GREEN)"\r\E[Kcompiling %s"$(GREEN) $<

clean:
	@rm -f $(OBJS)
	@printf $(GREEN)"$(NAME) clean\n"$(EOC)

fclean: clean
	@/bin/rm -f $(NAME)
	@printf $(GREEN)"$(NAME) fclean\n"$(EOC)

re: fclean all

norme:
	@norminette $(SRCS)
	@norminette $(HEADER_PATH)/*.h

.PHONY: clean fclean all re norme
