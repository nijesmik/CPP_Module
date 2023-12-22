CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = ex03

SRC = \
	./main.cpp \
	./Weapon.cpp \
	./HumanA.cpp \
	./HumanB.cpp

OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
