C++ = c++ -Wall -Wextra -Werror -std=c++98

NAME = btc

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = BitcoinExchange.hpp

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