CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++98

TARGET = megaphone
SOURCE = megaphone.cpp
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