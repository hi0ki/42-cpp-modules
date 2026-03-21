C++ = c++ -Wall -Wextra -Werror

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp

NAME = program

OBJ = $(SRC:.cpp=.o)

HEADERS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

ALL: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(C++) $(OBJ) -o $(NAME)

%.o:%.cpp $(HEADERS)
	$(C++) -c $< -o $@

clean:
	rm -rf $(OBJ) *_shrubbery

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)