C++ = c++ -Wall -Wextra -Werror

SRC = src/main.cpp  src/ClapTrap.cpp src/ScavTrap.cpp

NAME = program

OBJ = $(SRC:.cpp=.o)

ALL: $(NAME)

$(NAME): $(OBJ) include/ClapTrap.hpp include/ScavTrap.hpp
	$(C++) $(OBJ) -o $(NAME)

%.o:%.cpp include/ClapTrap.hpp include/ScavTrap.hpp
	$(C++) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)