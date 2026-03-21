C++ = c++ -Wall -Wextra -Werror

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp

NAME = program

OBJ = $(SRC:.cpp=.o)

ALL: $(NAME)

$(NAME): $(OBJ) Fixed.hpp Point.hpp
	$(C++) $(OBJ) -o $(NAME)

%.o:%.cpp Fixed.hpp Point.hpp
	$(C++) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)