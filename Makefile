CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm
RMFLAGS = -f
NAME = CppRegex
HEADERS = ./src/Regex.hpp \
		  ./src/RegexEngine.hpp \
		  ./src/helpers/ClassToken.hpp \
		  ./src/helpers/LiteralToken.hpp \
		  ./src/helpers/RangeToken.hpp \
		  ./src/helpers/Token.hpp \
		  ./src/helpers/ast/AstNode.hpp
SRCS = ./src/main.cpp $(HEADERS:.hpp=.cpp)
OBJS = $(SRCS:.cpp=.o)


default: all

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re