CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: ex00

ex00:
	$(CXX) $(CXXFLAGS) megaphone.cpp -o megaphone

clean:
	rm *.o
fclean:
	rm -rf megaphone

re: fclean all

.PHONY: all clean fclean re