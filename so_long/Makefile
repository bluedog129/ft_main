CFLAGS = -Wall -Wextra -Werror
NAME = so_long.a
SOURCES = map_init.c
B_SOURCES = 
		 
OBJECT = $(SOURCES:.c=.o)
B_OBJECT = $(B_SOURCES:.c=.o)

ifdef WITH_BONUS
	OBJECTS = $(OBJECT) $(B_OBJECT)
else
	OBJECTS = $(OBJECT)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C ./libft all
	cp ./libft/libft.a ./$(NAME)
	make -C ./get_next_line all
	cp ./get_next_line/get_next_line.a ./$(NAME)
	ar -rcs $@ $^

.c.o :
	cc $(CFLAGS) -c $< -o $(<:.c=.o)
bonus :
	make WITH_BONUS=1 all
clean :
	rm -rf $(OBJECT) $(B_OBJECT)
	make -C libft clean
	make -C get_next_line clean

fclean : clean
	rm -rf $(NAME) ./get_next_line/get_next_line.a ./libft/libft.a

re :
	make fclean
	make all

.PHONY : all clean fclean re