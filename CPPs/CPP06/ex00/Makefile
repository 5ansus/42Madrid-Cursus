NAME = convert
SRC = Converter.cpp main.cpp
BUILD = ./BUILD/
OBJ = $(addprefix $(BUILD), $(SRC:%.cpp=%.o))
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(BUILD):
	mkdir $@

$(BUILD)%.o: %.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug: CXXFLAGS += -DDEBUG
debug: re

.PHONY: all clean fclean re debug

-include $(OBJ:%.o=%.d)
