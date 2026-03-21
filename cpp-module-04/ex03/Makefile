C++ = c++ -Wall -Wextra -Werror

SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp

NAME = program

OBJ = $(SRC:.cpp=.o)

HEADERS = AMateria.hpp ICharacter.hpp Ice.hpp Cure.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp

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