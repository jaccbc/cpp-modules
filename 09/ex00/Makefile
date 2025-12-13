# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/16 15:27:32 by joandre-          #+#    #+#              #
#    Updated: 2025/12/13 17:40:19 by joandre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = btc
SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)
DB = data.csv
FILE = $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS));

all: $(NAME) $(DB)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(DB):
	wget -q https://cdn.intra.42.fr/document/document/40964/cpp_09.tgz
	tar xfz cpp_09.tgz && mv cpp_09/$(DB) . && rm -rf cpp_09 cpp_09.tgz

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) $(DB)

re: fclean all

run: $(NAME) $(DB)
	valgrind -s --leak-check=full --show-leak-kinds=all \
		--track-origins=yes --track-fds=yes ./$(NAME) $(FILE)

rerun: re run
