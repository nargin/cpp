CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = repertory.cpp

all: ex01

ex01:
	$(CXX) $(CXXFLAGS) -I./ $(SRC) -o repertory

clean:
	rm -f *.o

fclean: clean
	rm -f repertory

re: fclean all

.PHONY: all clean fclean re