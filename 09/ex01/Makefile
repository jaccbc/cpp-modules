# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 15:27:32 by joandre-          #+#    #+#              #
#    Updated: 2025/12/13 18:52:02 by joandre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = RPN
SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)
INPUT = '$(wordlist 2, $(words $(MAKECMDGOALS)), $(MAKECMDGOALS))'

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: $(NAME)
	valgrind -s --leak-check=full --show-leak-kinds=all \
		--track-origins=yes --track-fds=yes ./$(NAME) $(INPUT)

rerun: re run
