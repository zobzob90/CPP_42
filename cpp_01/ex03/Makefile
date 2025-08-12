# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 12:45:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/08/12 12:45:48 by ertrigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = violence
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

# Source files
SRCS = main.cpp \
       Weapon.cpp \
       HumanA.cpp \
       HumanB.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Weapon.hpp \
          HumanA.hpp \
          HumanB.hpp

# Colors and Emojis
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
BOLD = \033[1m
NC = \033[0m # No Color

# Fighting Emojis
SWORD = ⚔️
SHIELD = 🛡️
FIRE = 🔥
SPARKLES = ✨
CHECKMARK = ✅
TRASH = 🗑️
ROCKET = 🚀
FIST = 👊

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)$(BOLD)$(SWORD) Forging the ultimate weapon...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)$(CHECKMARK) $(NAME) compiled successfully! $(FIRE)$(NC)"
	@echo "$(MAGENTA)$(BOLD)Ready for battle! Run with: ./$(NAME) $(FIST)$(NC)"

%.o: %.cpp $(HEADERS)
	@echo "$(YELLOW)$(SPARKLES) Crafting $<...$(NC)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)$(TRASH) Cleaning the battlefield...$(NC)"
	@$(RM) $(OBJS)
	@echo "$(BLUE)Weapons cleaned!$(NC)"

fclean: clean
	@echo "$(RED)$(BOLD)$(TRASH) Destroying $(NAME)...$(NC)"
	@$(RM) $(NAME)
	@echo "$(BLUE)$(BOLD)Total annihilation complete! $(SHIELD)$(NC)"

re: fclean all
	@echo "$(MAGENTA)$(BOLD)$(SPARKLES) Weapons reforged successfully!$(NC)"

run: $(NAME)
	@echo "$(CYAN)$(BOLD)$(ROCKET) Entering the arena...$(NC)"
	@./$(NAME)
	@echo "$(GREEN)$(BOLD)Battle concluded! $(SWORD)$(NC)"

.PHONY: all clean fclean re run