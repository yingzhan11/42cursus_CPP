# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 13:37:20 by yzhan             #+#    #+#              #
#    Updated: 2025/03/18 13:37:22 by yzhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombies
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = main.cpp Zombie.cpp zombieHorde.cpp

OBJS_DIR = objs
OBJS = $(SRCS:.cpp=.o)
TARGETS = $(addprefix $(OBJS_DIR)/, $(OBJS))

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(TARGETS)
	$(CC) $(CFLAGS) -o $(NAME) $(TARGETS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
