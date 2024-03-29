# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 12:05:39 by hyojocho          #+#    #+#              #
#    Updated: 2023/03/15 19:13:21 by hyojocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCES = ft_bzero.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_strchr.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_tolower.c ft_toupper.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strnstr.c ft_memcmp.c \
			ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_htoa.c ft_utoa.c ft_uitoa.c \
			ft_uitoa_lower.c ft_strcmp.c ft_atol.c ft_atoi_extension.c \
			./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c
FT_PRINTF = ./ft_printf/apply.c \
			./ft_printf/conversion_apply.c \
			./ft_printf/conversion_low_hex_apply.c \
			./ft_printf/conversion_p_ud_apply.c \
			./ft_printf/conversion_up_hex_apply.c \
			./ft_printf/flags_apply.c \
			./ft_printf/flags_space_plus_apply.c \
			./ft_printf/ft_arraylist_add_rem.c \
			./ft_printf/ft_arraylist.c \
			./ft_printf/ft_printf.c \
			./ft_printf/parsing.c \
			./ft_printf/precision_apply.c \
			./ft_printf/width_apply.c
B_SOURCES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJECT = $(SOURCES:.c=.o)
B_OBJECT = $(B_SOURCES:.c=.o)
P_OBJECT = $(FT_PRINTF:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJECT) $(B_OBJECT) $(P_OBJECT)
else
	OBJECTS = $(OBJECT) $(P_OBJECT)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $@ $^

.c.o :
	cc $(CFLAGS) -c $< -o $(<:.c=.o)
bonus :
	make WITH_BONUS=1 all
clean :
	rm -rf $(OBJECT) $(B_OBJECT) $(P_OBJECT)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re