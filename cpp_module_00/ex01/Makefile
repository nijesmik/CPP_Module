CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra

NAME = phonebook

INCLUDE = ./

SRC = \
	./main.cpp \
	./PhoneBook.cpp \
	./Contact.cpp
OBJ = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE) $^ -o $(NAME)

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
