CPP = c++ -Wall -Wextra -Werror -std=c++98

NAME = program

SRC = main.cpp Harl.cpp
HEADERS = Harl.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CPP) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all