C++ = c++ -Wall -Wextra -Werror

SRCS = main.cpp \

OBJS = $(SRCS:.cpp=.o)

NAME = program

HEADER = Array.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(C++) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(C++) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all