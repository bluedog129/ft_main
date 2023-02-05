# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 13:10:23 by hyojocho          #+#    #+#              #
#    Updated: 2023/02/02 11:27:32 by hyojocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCES = ft_printf.c apply.c conversion_apply.c flags_apply.c ft_arraylist.c\
		 parsing.c precision_apply.c width_apply.c conversion_low_hex_apply.c\
		 conversion_p_ud_apply.c conversion_up_hex_apply.c flags_space_plus_apply.c\
		 ft_arraylist_add_rem.c
B_SOURCES = ft_printf_bonus.c apply_bonus.c conversion_apply_bonus.c \
			flags_apply_bonus.c ft_arraylist_bonus.c parsing_bonus.c \
			precision_apply_bonus.c width_apply_bonus.c \
			conversion_low_hex_apply_bonus.c conversion_p_ud_apply_bonus.c \
			conversion_up_hex_apply_bonus.c flags_space_plus_apply_bonus.c \
		 	ft_arraylist_add_rem_bonus.c
		 
OBJECT = $(SOURCES:.c=.o)
B_OBJECT = $(B_SOURCES:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJECT) $(B_OBJECT)
else
	OBJECTS = $(OBJECT)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C libft all
	cp ./libft/libft.a ./$(NAME)
	ar -rcs $@ $^

.c.o :
	cc $(CFLAGS) -c $< -o $(<:.c=.o)
bonus :
	make WITH_BONUS=1 all
clean :
	rm -rf $(OBJECT) $(B_OBJECT)
	make -C libft clean

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re