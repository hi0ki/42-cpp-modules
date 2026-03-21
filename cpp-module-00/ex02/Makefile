C++ = c++ -Wall -Wextra -Werror -std=c++98
NAME = program


SRC = tests.cpp Account.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) Account.hpp
	$(C++) -o $(NAME) $(OBJ)

%.o : %.cpp Account.hpp
	$(C++) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all