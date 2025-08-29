# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eric <eric@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/27 10:00:00 by ertrigna          #+#    #+#              #
#    Updated: 2025/08/29 15:08:35 by eric             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME		= FragTrap

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

# Colors for pretty output
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
RED			= \033[0;31m
BLUE		= \033[0;34m
CYAN		= \033[0;36m
RESET		= \033[0m
BOLD		= \033[1m

# Source files
SOURCES		= main.cpp \
			  ClapTrap.cpp \
			  ScavTrap.cpp \
			  FragTrap.cpp

# Object files
OBJECTS		= $(SOURCES:.cpp=.o)

# Default rule
all: $(NAME)

# Compile the program
$(NAME): $(OBJECTS)
	@echo "$(CYAN)🔗 Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

# Compile object files
%.o: %.cpp
	@echo "$(YELLOW)🔨 Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@$(RM) $(OBJECTS)
	@echo "$(GREEN)✅ Object files cleaned!$(RESET)"

# Clean everything
fclean: clean
	@echo "$(RED)🗑️  Removing $(NAME) and old executables...$(RESET)"
	@$(RM) $(NAME) FlagTrap
	@echo "$(GREEN)✅ Everything cleaned!$(RESET)"

# Rebuild everything
re: fclean all

# Run the program
run: $(NAME)
	@echo "$(BLUE)🚀 Running $(NAME)...$(RESET)"
	@./$(NAME)

# Debug version
debug: CXXFLAGS += -g -DDEBUG
debug: re
	@echo "$(CYAN)🐛 Debug version compiled!$(RESET)"

# Show help
help:
	@echo "$(BOLD)$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)     - Compile the program"
	@echo "  $(GREEN)clean$(RESET)   - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)  - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)      - Clean and recompile"
	@echo "  $(GREEN)run$(RESET)     - Compile and run the program"
	@echo "  $(GREEN)debug$(RESET)   - Compile with debug flags"
	@echo "  $(GREEN)help$(RESET)    - Show this help message"

# Phony targets
.PHONY: all clean fclean re run debug help