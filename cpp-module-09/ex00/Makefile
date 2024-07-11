CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = btc

INCLUDE = ./

SRC = \
	./main.cpp \
	./BitcoinExchange.cpp \
	./Date.cpp

OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $(NAME)

%.o : %.cpp %.hpp
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
