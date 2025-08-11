# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 16:15:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/08/11 16:14:12 by ertrigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = zombie_horde
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

# Source files
SRCS = main.cpp \
       Zombie.cpp \
       zombieHorde.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Zombie.hpp

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m # No Color

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(NC)"

%.o: %.cpp $(HEADERS)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re