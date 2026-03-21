C++ = c++ -Wall -Wextra -Werror

SRC = src/main.cpp  src/ClapTrap.cpp src/ScavTrap.cpp src/FragTrap.cpp src/DiamondTrap.cpp

NAME = program

OBJ = $(SRC:.cpp=.o)

HEADERS = include/ClapTrap.hpp include/ScavTrap.hpp include/FragTrap.hpp include/DiamondTrap.hpp

ALL: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(C++) $(OBJ) -o $(NAME)

%.o:%.cpp $(HEADERS)
	$(C++) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)