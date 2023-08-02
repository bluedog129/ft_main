CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = Phonebook
SOURCE = main.cpp Contact.cpp Phonebook.cpp
OBJECTS = $(SOURCE:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re