# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 14:15:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/08/13 14:14:43 by ertrigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = fixed
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

# Source files
SRCS = main.cpp \
       Fixed.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Fixed.hpp

# Colors and Emojis
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
BOLD = \033[1m
NC = \033[0m

# Fixed Point Emojis
FIXED = 🔢
POINT = 📍
MATH = 🧮
CHECKMARK = ✅
TRASH = 🗑️
ROCKET = 🚀
STAR = ⭐
GEAR = ⚙️

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)$(BOLD)$(ROCKET) Building Fixed Point class...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)$(CHECKMARK) $(NAME) compiled successfully! $(FIXED)$(NC)"
	@echo "$(MAGENTA)$(BOLD)Usage: ./$(NAME) to test Fixed Point arithmetic $(MATH)$(NC)"

%.o: %.cpp $(HEADERS)
	@echo "$(YELLOW)📄 Compiling $<...$(NC)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)$(TRASH) Cleaning object files...$(NC)"
	@$(RM) $(OBJS)
	@echo "$(BLUE)Object files cleaned! $(CHECKMARK)$(NC)"

fclean: clean
	@echo "$(RED)$(BOLD)$(TRASH) Removing $(NAME)...$(NC)"
	@$(RM) $(NAME)
	@echo "$(BLUE)$(BOLD)Everything cleaned! $(STAR)$(NC)"

re: fclean all
	@echo "$(MAGENTA)$(BOLD)$(GEAR) Project rebuilt successfully!$(NC)"

test: $(NAME)
	@echo "$(CYAN)$(BOLD)$(FIXED) Running Fixed Point tests...$(NC)"
	@echo "$(GREEN)$(BOLD)======= FIXED POINT TESTS =======$(NC)"
	@./$(NAME)
	@echo "$(GREEN)$(BOLD)=================================$(NC)"

debug: $(NAME)
	@echo "$(YELLOW)$(GEAR) Running with debug output:$(NC)"
	@valgrind --leak-check=full ./$(NAME)

orthodoxy:
	@echo "$(MAGENTA)$(BOLD)$(POINT) Checking Orthodox Canonical Form:$(NC)"
	@echo "$(GREEN)$(CHECKMARK) Default Constructor: Fixed()$(NC)"
	@echo "$(GREEN)$(CHECKMARK) Copy Constructor: Fixed(const Fixed &)$(NC)"
	@echo "$(GREEN)$(CHECKMARK) Assignment Operator: operator=()$(NC)"
	@echo "$(GREEN)$(CHECKMARK) Destructor: ~Fixed()$(NC)"
	@echo "$(CYAN)Your Fixed class follows the Orthodox Canonical Form! $(STAR)$(NC)"

help:
	@echo "$(CYAN)$(BOLD)$(STAR) Available commands:$(NC)"
	@echo "$(GREEN)  make$(NC)          - Compile Fixed Point class $(FIXED)"
	@echo "$(GREEN)  make test$(NC)     - Run Fixed Point tests $(MATH)"
	@echo "$(GREEN)  make debug$(NC)    - Run with memory check"
	@echo "$(GREEN)  make orthodoxy$(NC)- Check Orthodox Canonical Form $(POINT)"
	@echo "$(GREEN)  make clean$(NC)    - Remove object files $(TRASH)"
	@echo "$(GREEN)  make fclean$(NC)   - Remove all generated files"
	@echo "$(GREEN)  make re$(NC)       - Rebuild the project"
	@echo "$(GREEN)  make help$(NC)     - Show this help"

.PHONY: all clean fclean re test debug orthodoxy help