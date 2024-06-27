CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = a.out

INCLUDE = ./

SRC = \
	./main.cpp \
	./Bureaucrat.cpp \
	./AForm.cpp \
	./ShrubberyCreationForm.cpp \
	./RobotomyRequestForm.cpp \
	./PresidentialPardonForm.cpp

OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
