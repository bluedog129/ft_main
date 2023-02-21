CFLAGS = -Wall -Wextra -Werror
NAME = so_long.a
SOURCES = ./srcs/map_init.c ./srcs/so_long.c ./srcs/check_map.c \
			./srcs/utils.c ./srcs/check_route.c ./srcs/open_image.c \
			./srcs/display_image.c ./srcs/move_player.c ./srcs/move_enemy.c
B_SOURCES = ./bonus_srcs/map_init_bonus.c ./bonus_srcs/so_long_bonus.c \
			./bonus_srcs/check_map_bonus.c ./bonus_srcs/utils_bonus.c \
			./bonus_srcs/check_route_bonus.c ./bonus_srcs/open_image_bonus.c \
			./bonus_srcs/display_image_bonus.c ./bonus_srcs/move_player_bonus.c \
			./bonus_srcs/move_enemy_bonus.c

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
	cc ./srcs/main.c -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a so_long.a -o so_long.out

.c.o :
	cc $(CFLAGS) -c $< -o $(<:.c=.o)
bonus :
	make WITH_BONUS=1 all
clean :
	rm -rf $(OBJECT) $(B_OBJECT)
	make clean -C mlx
	make clean -C libft

fclean : clean
	rm -rf $(NAME) ./libft/libft.a so_long.a so_long.out

re :
	make fclean
	make all

.PHONY : all clean fclean re
