# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 14:41:13 by hyojocho          #+#    #+#              #
#    Updated: 2023/07/08 17:22:56 by hyojocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC              = cc
CFLAGS          = -Wall -Wextra -Werror
NAME            = cub3d
RM              = rm -f
LIBS			= libft/libft.a

EXEC            = cub3d
SRCS_PATH	    = ./

MAIN_PATH  	    = ./
MAIN_SRCS       = main.c
MAIN            = $(addprefix $(MAIN_PATH), $(MAIN_SRCS))

PARSING_PATH  	= srcs/parsing/
PARSING_SRCS    = parsing.c utils.c error.c info_get.c initialize.c \
					line_validation.c map_validation.c 
PARSING         = $(addprefix $(PARSING_PATH), $(PARSING_SRCS))

SOURCES			= $(addprefix $(SRCS_PATH), $(MAIN))\
				  $(addprefix $(SRCS_PATH), $(PARSING))

OBJECTS         = $(SOURCES:.c=.o)

HEADER_PATH     = ./headers/
S_HEADER        = cub3d.h strutures.h
HEADER          = $(addprefix $(HEADER_PATH), $(S_HEADER))

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(EXEC)
	@echo -e "$(GREEN)$(EXEC) created!$(DEFAULT)"

$(LIBS) :
	@make -C libft all

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJECTS)
	@$(RM) $(OBJECTS:.o=.d)
	make -C libft clean

fclean: clean
	@$(RM) $(EXEC)
	@$(RM) libft/libft.a
	@echo -e "$(BLUE)delete all!$(DEFAULT)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re

RED = \033[1;31m
PINK = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
DEFAULT = \033[0m