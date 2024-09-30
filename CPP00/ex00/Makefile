NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	c++ -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	c++ -Wall -Wextra -Werror -o $(NAME) $(OBJ)

