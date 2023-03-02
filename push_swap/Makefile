CFLAGS = -Wall -Wextra -Werror -MMD
NAME = push_swap.a
SRCS = srcs/main.c
BNS_SRCS = bonus_srcs/main_bonus.c
SOURCES = ./srcs/dequeue/dequeue_one.c ./srcs/dequeue/dequeue_two.c ./srcs/push_swap.c \
			./srcs/args_validate.c ./srcs/utils.c ./srcs/commands/command_s_p.c \
			./srcs/commands/command_r.c ./srcs/commands/command_rrr.c
B_SOURCES = 

OBJECT = $(SOURCES:.c=.o)
B_OBJECT = $(B_SOURCES:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(B_OBJECT)
	SRC = $(BNS_SRCS)
else
	OBJECTS = $(OBJECT)
	SRC = $(SRCS)
endif

all : $(NAME)

$(NAME) : $(OBJECTS) $(SRC)
	make all -C ./libft
	cp ./libft/libft.a ./$(NAME)
	make all -C ./ft_printf
	cp ./ft_printf/libftprintf.a ./$(NAME)
	ar -rcs $@ $^
	cc ./$(SRC) $(CFLAGS) libft/libft.a ft_printf/libftprintf.a push_swap.a -o push_swap

.c.o :
	cc $(CFLAGS) -c $< -o $(<:.c=.o)
bonus :
	make WITH_BONUS=1 all
clean :
	rm -rf $(OBJECT) $(B_OBJECT) $(OBJECTS:.o=.d) $(B_OBJECT:.o=.d) push_swap.d
	make clean -C libft
	make clean -C ft_printf

fclean : clean
	rm -rf $(NAME) ./libft/libft.a ./ft_printf/libftprintf.a $(OBJECTS:.o=.d) $(B_OBJECT:.o=.d) push_swap.a push_swap

re :
	make fclean
	make all

.PHONY : all clean fclean re

-include $(OBJECTS:.o=.d)
