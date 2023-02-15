CFLAGS = -Wall -Wextra -Werror
NAME = so_long.a
SOURCES = map_init.c so_long.c check_map.c help.c check_route.c\
	open_image.c display_image.c
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
	make all -C ./libft
	cp ./libft/libft.a ./$(NAME)
	make all -C ./mlx 2> /dev/null
	ar -rcs $@ $^
	cc main.c -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a so_long.a -o so_long.out

.c.o :
	cc $(CFLAGS) -c $< -o $(<:.c=.o)
bonus :
	make WITH_BONUS=1 all
clean :
	rm -rf $(OBJECT) $(B_OBJECT)
	make clean -C mlx
	make clean -C libft

fclean : clean
	rm -rf $(NAME) ./libft/libft.a

re :
	make fclean
	make all

.PHONY : all clean fclean re