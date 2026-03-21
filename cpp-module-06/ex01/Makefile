C++ = c++ -Wall -Wextra -Werror

NAME = program

SRC = main.cpp Serializer.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Serializer.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADERS)
	$(C++) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all