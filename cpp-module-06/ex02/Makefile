C++ = c++ -Wall -Wextra -Werror

NAME = program

SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp

OBJ = $(SRC:.cpp=.o)

HEADERS = Base.hpp A.hpp B.hpp C.hpp

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