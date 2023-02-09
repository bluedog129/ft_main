NAME = get_next_line.a
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
AR          = ar -rcs
RM          = rm -f
INCS        = libft.h
SOURCES = get_next_line.c get_next_line_utils.c

OBJECT = $(SOURCES:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJECT)
	$(AR) $@ $^

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:      
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re