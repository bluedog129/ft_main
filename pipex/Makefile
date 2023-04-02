# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 11:02:56 by hyojocho          #+#    #+#              #
#    Updated: 2023/04/02 15:15:02 by hyojocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -fsanitize=address
AR          = ar -rcs
RM          = rm -f
LIBS		= libft/libft.a
SRCS		= ./srcs/pipex.c \
				./srcs/command_setting.c \
				./srcs/free_utils.c \
				./srcs/pipe_apply.c \
				./srcs/file_open.c \
				./srcs/parent_process.c \
				./srcs/child_process.c
SRCS_BONUS  = ./bonus/pipex_bonus.c \
				./bonus/command_setting_bonus.c \
				./bonus/free_utils_bonus.c \
				./bonus/pipe_apply_bonus.c \
				./bonus/file_open_bonus.c \
				./bonus/parent_process_bonus.c \
				./bonus/child_process_bonus.c \
				./bonus/here_doc_bonus.c
OBJS        = $(SRCS:c=o)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJS_BONUS)
else
	OBJECTS = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(NAME)

$(LIBS) :
	@make -C libft all

bonus:
	@make WITH_BONUS=1 all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./srcs

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(RM) libft/libft.a

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus