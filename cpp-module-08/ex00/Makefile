C++ = c++ -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
HEADERS = easyfind.hpp

NAME = program

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(C++) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

