NAME = PmergeMe
INCLUDE = ./
HEADER = PmergeMe.hpp
SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

.cpp.o :
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re clean fclean