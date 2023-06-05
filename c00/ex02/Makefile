SRC = Account.cpp tests.cpp
	
OBJS = $(SRC:.c=.o)
RM = rm -f
NAME = tamer

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


all : author $(NAME)


author :
	@echo "Author :\tkumlord"
	@echo "Project :\t$(NAME)"
	@echo --------------------------------------------------------

PRINT_NAME = 1

%.o: %.c
	@if [ $(PRINT_NAME) -eq 1 ]; then echo -n "$(NAME) : "; fi
	@$(CC) $(FLAGS) -c $< -o $@
	@echo -n "\033[32m✔\033[0m"
	@$(eval PRINT_NAME = 0)

$(NAME) : $(OBJS)
	@${CC} ${CFLAGS} $(OBJS) -o $(NAME)
	@echo
	@echo $(NAME) is runable.

clean :
	@${RM} ${OBJS}
	@echo Object files removed.

fclean : clean
	@${RM} $(NAME)
	@echo ${NAME} removed.

re : author fclean all
		@echo Rebuild done.

.PHONY: all clean fclean re