# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 21:10:09 by sanferna          #+#    #+#              #
#    Updated: 2026/02/09 21:20:49 by sanferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
SRC = main.cpp Bureaucrat.cpp
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

.PHONY: all clean fclean re
