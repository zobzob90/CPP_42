# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 16:45:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/08/11 16:42:57 by ertrigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = brain
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
BOLD = \033[1m
NC = \033[0m # No Color

# Emoji
ROCKET = 🚀
FIRE = 🔥
SPARKLES = ✨
CHECKMARK = ✅
TRASH = 🗑️

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)$(BOLD)$(ROCKET) Linking $(NAME)...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)$(CHECKMARK) $(NAME) compiled successfully! $(FIRE)$(NC)"
	@echo "$(MAGENTA)$(BOLD)Run with: ./$(NAME)$(NC)"

%.o: %.cpp
	@echo "$(YELLOW)$(SPARKLES) Compiling $<...$(NC)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)$(TRASH) Cleaning object files...$(NC)"
	@$(RM) $(OBJS)
	@echo "$(BLUE)Object files cleaned!$(NC)"

fclean: clean
	@echo "$(RED)$(BOLD)$(TRASH) Cleaning $(NAME)...$(NC)"
	@$(RM) $(NAME)
	@echo "$(BLUE)$(BOLD)Everything cleaned!$(NC)"

re: fclean all
	@echo "$(MAGENTA)$(BOLD)$(SPARKLES) Project rebuilt successfully!$(NC)"

run: $(NAME)
	@echo "$(CYAN)$(BOLD)$(ROCKET) Running $(NAME)...$(NC)"
	@./$(NAME)

.PHONY: all clean fclean re run