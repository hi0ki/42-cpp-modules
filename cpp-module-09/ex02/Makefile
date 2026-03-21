C++ = c++ -Wall -Wextra -Werror -std=c++98

NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = PmergeMe.hpp

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