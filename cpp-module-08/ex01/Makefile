C++ = c++ -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Span.cpp
HEADERS = Span.hpp

NAME = program

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADERS)
	$(C++) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

