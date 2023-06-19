# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 17:58:32 by hyojocho          #+#    #+#              #
#    Updated: 2023/06/17 20:02:17 by hyojocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -MMD
NAME            = philo
RM              = rm -f
LIBS			= libft/libft.a

EXEC            = philo
SRCS_PATH	    = ./

MAIN_PATH  	    = srcs/
MAIN_SRCS       = main.c
MAIN            = $(addprefix $(MAIN_PATH), $(MAIN_SRCS))

INIT_PATH  	    = srcs/initialize/
INIT_SRCS       = init_args.c time_get.c init_resources.c init_philos.c
INIT            = $(addprefix $(INIT_PATH), $(INIT_SRCS))

SOURCES			= $(addprefix $(SRCS_PATH), $(MAIN))\
				  $(addprefix $(SRCS_PATH), $(INIT))

OBJECTS         = $(SOURCES:.c=.o)

HEADER_PATH     = ./headers/
S_HEADER        = philosophers.h structures.h
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

-include $(OBJECTS:.o=.d)

RED = \033[1;31m
PINK = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
DEFAULT = \033[0m