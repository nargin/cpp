CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Account.cpp tests.cpp

all: XiJinping

XiJinping:
	$(CXX) $(CXXFLAGS) -I./ $(SRC) -o borzoi

clean:
	rm -f *.o

fclean: clean
	rm -f borzoi

re: fclean all

.PHONY: all clean fclean re