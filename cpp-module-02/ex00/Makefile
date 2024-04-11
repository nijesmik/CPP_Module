CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = ex00

INCLUDE = ./

SRC = \
	./main.cpp \
	./Fixed.cpp

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
