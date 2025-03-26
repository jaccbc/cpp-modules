# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joandre- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/15 04:01:40 by joandre-          #+#    #+#              #
#    Updated: 2025/01/23 02:21:30 by joandre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = harl
SRC = main.cpp Harl.cpp

all: $(NAME)

$(NAME):
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

run: $(NAME)
	valgrind -s --leak-check=full --show-leak-kinds=all \
		--track-origins=yes ./$(NAME)

clean:
	rm -rf $(NAME)

re: clean all

rerun: re run
