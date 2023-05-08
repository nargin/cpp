CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: ex00

ex00:
	$(CXX) $(CXXFLAGS) megaphone.cpp -o megaphone

clean:

fclean: clean
	rm -rf megaphone

re: fclean all

.PHONY: all clean fclean re