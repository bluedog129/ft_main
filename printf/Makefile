# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 13:10:23 by hyojocho          #+#    #+#              #
#    Updated: 2023/01/21 15:29:35 by hyojocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
# LIBS = libft/libft.a
SOURCES = ft_printf.c apply.c conversion_apply.c flags_apply.c ft_arraylist.c\
		 parsing.c precision_apply.c width_apply.c

OBJECT = $(SOURCES:.c=.o) #$(LIBS)
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
	ar rcs $@ $^

#$(LIBS) : make -C libft all

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